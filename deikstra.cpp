#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iomanip>
#include <tuple>

using namespace std;

struct SimpleGraph
{
	// ребра
	unordered_map<char, vector<char>> edges;

	// соседи
	vector<char> neighbours(char id)
	{
		return edges[id];
	}
};

struct GridLocation
{
	int x, y;
};

namespace std
{
	// функция для перегрузки (), чтобы они работали с сеткой
	template <> struct hash<GridLocation>
	{
		size_t operator() (const GridLocation& id) const noexcept
		{
			return std::hash<int>()(id.x ^ (id.y << 16));
		}
	};
}

// перегрузка оператора для сравнения двух точек (почему-то внутри GridLocation не робит)
bool operator == (GridLocation a, GridLocation b)
{
	return (a.x == b.x && a.y == b.y);
}

bool operator != (GridLocation a, GridLocation b)
{
	return !(a == b);
}

// аналогично оператору ==
bool operator < (GridLocation a, GridLocation b)
{
	return tie(a.x, a.y) < tie(b.x, b.y);
}

struct SquareGrid
{
	// !!! поменял с array на вектор
	static vector<GridLocation> DIRS;

	int width, height;

	unordered_set<GridLocation> walls;

	SquareGrid(int height_, int width_) : height(height_), width(width_) {};

	bool in_bounds(GridLocation id) const
	{
		return (0 <= id.x && id.x < width) and (0 <= id.y and id.y < height);
	}

	bool passable(GridLocation id) const
	{
		return walls.find(id) == walls.end();
	}

	vector<GridLocation> neighbours(GridLocation id) const
	{
		vector<GridLocation> results;

		for (GridLocation dir : DIRS)
		{
			GridLocation next{ id.x + dir.x, id.y + dir.y };

			if (in_bounds(next) and passable(next))
			{
				results.push_back(next);
			}
		}

		// ПОКА МЫ НЕ ЗНАЕМ ЧТО ТАКОЕ "УРОДЛИВЫЕ ПУТИ"
		if ((id.x + id.y) % 2 == 0)
		{
			reverse(results.begin(), results.end());
		}

		return results;
	}
};

vector<GridLocation> SquareGrid::DIRS =
{
	GridLocation{1, 0}, GridLocation{-1, 0},
	GridLocation{0, -1}, GridLocation{0, 1}
};

struct GridWithWeights : SquareGrid
{
	unordered_set<GridLocation> forests;

	GridWithWeights(int h, int w) : SquareGrid(w, h) {}

	double cost(GridLocation from, GridLocation to) const
	{
		return forests.find(to) != forests.end() ? 5 : 1;
	}
};

// T - вершина, priority_t - приоритет
template<typename T, typename priority_t>
struct PriorityQueue
{
	typedef pair <priority_t, T> PQElement;
	priority_queue<PQElement, vector<PQElement>,
		greater<PQElement>> elements;

	inline bool empty() const
	{
		return elements.empty();
	}

	inline void put(T item, priority_t priority)
	{
		elements.emplace(priority, item);
	}

	T get()
	{
		T best_item = elements.top().second;
		elements.pop();

		return best_item;
	}
};

// основная функция отрисовки карты
template<class Graph>
void draw_grid(const Graph& graph,
	unordered_map<GridLocation, double>* distances = nullptr,
	unordered_map<GridLocation, GridLocation>* point_to = nullptr,
	vector<GridLocation>* path = nullptr,
	GridLocation* start = nullptr,
	GridLocation* goal = nullptr) {
	const int field_width = 3;
	cout << string(field_width * graph.width, '_') << '\n';
	for (int y = 0; y != graph.height; ++y) {
		for (int x = 0; x != graph.width; ++x) {
			GridLocation id{ x, y };
			if (graph.walls.find(id) != graph.walls.end()) {
				cout << "\033[31m";
				cout << string(field_width, '#');
				cout << "\033[0m";
			}
			else if (start && id == *start) {
				cout << "\033[0;44m A ";
				cout << "\033[0m";
			}
			else if (distances != nullptr && graph.forests.find(id) != graph.forests.end())
			{
				cout << "\033[32m";
				cout << ' ' << left << setw(field_width - 1) << (*distances)[id];
				cout << "\033[0m";
			}
			else if (goal && id == *goal) {
				cout << "\033[0;44m X \033[0m";
			}
			else if (path != nullptr && find(path->begin(), path->end(), id) != path->end()) {
				cout << " @ ";
			}
			else if (point_to != nullptr && point_to->count(id)) {
				GridLocation next = (*point_to)[id];
				if (next.x == x + 1) { cout << " > "; }
				else if (next.x == x - 1) { cout << " < "; }
				else if (next.y == y + 1) { cout << " v "; }
				else if (next.y == y - 1) { cout << " ^ "; }
				else { cout << " * "; }
			}
			else if (distances != nullptr && distances->count(id)) {
				cout << ' ' << left << setw(field_width - 1) << (*distances)[id];
			}
			else {
				cout << " . ";
			}
		}
		cout << '\n';
	}
	cout << string(field_width * graph.width, '~') << '\n';
}

// нарисовать стены
void add_rect(SquareGrid& grid, int x1, int y1, int x2, int y2) {
	for (int x = x1; x < x2; ++x) {
		for (int y = y1; y < y2; ++y) {
			grid.walls.insert(GridLocation{ x, y });
		}
	}
}


//для отрисовки кратчайшего пути
template<typename Location>
vector<Location> reconstruct_path(Location start, Location goal,
	unordered_map<Location, Location> came_from)
{
	vector<Location> path;
	Location current = goal;

	if (came_from.find(goal) == came_from.end()) { return path; }

	while (current != start)
	{
		path.push_back(current);
		current = came_from[current];
	}

	path.push_back(start);
	reverse(path.begin(), path.end());

	return path;
}

// создать карту ()
SquareGrid make_diagram_weightless() {
	SquareGrid grid(20, 30);
	add_rect(grid, 3, 3, 5, 12);
	add_rect(grid, 13, 4, 15, 15);
	add_rect(grid, 21, 0, 23, 7);
	add_rect(grid, 23, 5, 26, 7);
	return grid;
}

GridWithWeights make_diagram_weights() {
	GridWithWeights grid(30, 30);
	add_rect(grid, 3, 3, 5, 12);
	add_rect(grid, 13, 4, 15, 15);
	add_rect(grid, 21, 0, 23, 7);
	add_rect(grid, 23, 5, 26, 7);

	typedef GridLocation L;
	grid.forests = unordered_set<GridLocation>{
	  L{3, 4}, L{3, 5}, L{4, 1}, L{4, 2},
	  L{4, 3}, L{4, 4}, L{4, 5}, L{4, 6},
	  L{4, 7}, L{4, 8}, L{5, 1}, L{5, 2},
	  L{5, 3}, L{5, 4}, L{5, 5}, L{5, 6},
	  L{5, 7}, L{5, 8}, L{6, 2}, L{6, 3},
	  L{6, 4}, L{6, 5}, L{6, 6}, L{6, 7},
	  L{7, 3}, L{7, 4}, L{7, 5}, L{16, 15},
	  L{16, 16}, L{16, 17}, L{16, 18}, L{16, 19},
	  L{17, 16}, L{17, 17}, L{17, 18}, L{17, 19},
	  L{18, 16}, L{18, 17}, L{18, 18}, L{18, 19},
	  L{20, 16}, L{20, 17}, L{20, 18}, L{20, 19}
	};

	return grid;
}

template<typename Location, typename Graph>
void dijkstra(Graph graph, Location start, Location goal,
	unordered_map<Location, Location>& came_from,
	unordered_map<Location, double>& cost_so_far)
{
	PriorityQueue<Location, double> frontier;
	frontier.put(start, 0);

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty())
	{
		Location current = frontier.get();

		if (current == goal) { break; }

		for (Location next : graph.neighbours(current))
		{
			double new_cost = cost_so_far[current] + graph.cost(current, next);

			if (cost_so_far.find(next) == cost_so_far.end()
				|| new_cost < cost_so_far[next])
			{
				cost_so_far[next] = new_cost;
				came_from[next] = current;
				frontier.put(next, new_cost);
			}
		}
	}
}

// v2.0
template<typename Location, typename Graph>
unordered_map<Location, Location> bfs(Graph graph, Location start, Location goal)
{
	queue<Location> frontier;
	frontier.push(start);

	unordered_map<Location, Location> came_from;
	came_from[start] = start;


	while (!frontier.empty())
	{
		Location current = frontier.front();
		frontier.pop();

		if (current == goal) { break; }

		for (Location next : graph.neighbours(current))
		{
			if (came_from.find(next) == came_from.end())
			{
				frontier.push(next);
				came_from[next] = current;
			}
		}
	}

	return came_from;
}


int main()
{
	// TODO: глянуть, почему пути все еще уродливые

	setlocale(LC_ALL, "Russian");

	GridLocation start{ 8, 15 };
	GridLocation goal{ 19, 17 };

	unordered_map<GridLocation, GridLocation> came_from;
	unordered_map<GridLocation, double> cost_so_far;

	GridWithWeights grid = make_diagram_weights();

	dijkstra(grid, start, goal, came_from, cost_so_far);

	//draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);

	cout << "\nС ВЫБРАННЫМ ПУТЕМ\n";

	vector<GridLocation> path = reconstruct_path(start, goal, came_from);
	draw_grid(grid, &cost_so_far, nullptr, &path, &start, &goal);
}
