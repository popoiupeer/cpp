#include <iostream>
#include <cstdlib>
using namespace std;

class Task {
private:
    string _title;
    string _description;
    string _timeDeadline;
    int _priority; // 0..2, 0 - зеленый, 2 - красный
    bool _isActive; //false -> в архив

public:
    string getTitle() {
        return _title;
    }
    void setTitle(string title) {
        _title = title;
    }
    string getDescription() {
        return _description;
    }
    void setDescription(string description) {
        _description = description;
    }
    string getTimeDeadline() {
        return _timeDeadline;
    }
    void setTimeDeadline(string timeDeadline) {
        _timeDeadline = timeDeadline;
    }
    int getPriority() {
        return _priority;
    }
    void setPriority(int priority) {
        _priority = priority;
    }
    bool getIsActive() {
        return _isActive;
    }
    void setIsActive(bool isActive) {
        _isActive = isActive;
    }

    Task() {
        _title = "Undefined";
        _description = "Undefined";
        _timeDeadline = "Undefined";
        _priority = 0;
        _isActive = true;
    }

    Task(string title,
        string description,
        string timeDeadline,
        int priority,
        bool isActive)
    {
        _title = title;
        _description = description;
        _timeDeadline = timeDeadline;
        _priority = priority;
        _isActive = isActive;
    }

    void display() {
        switch (_priority) {
        case 0:
            cout << "\033[32m"; //Зеленый
            break;
        case 1:
            cout << "\033[33m"; //Желтый
            break;
        case 2:
            cout << "\033[31m"; //Красный
            break;
        default:
            cout << "\033[37"; //Серый
            break;
        }
        cout << _title << endl << _description << endl << _timeDeadline << endl;
        cout << "\033[0m";
    }

    void pushToArchive() {
        _timeDeadline = "Бессрочно";
        _priority = 3;
        _isActive = false;
    }
    
    
};

class TaskManager {
private:

    Task* _tasks;
    int _sizeTasks;

public:
    TaskManager() {
        _sizeTasks = 0;
        _tasks = new Task[_sizeTasks];
    }
    int GetSize() {
        return _sizeTasks;
    }

    void pushTask(Task task) {
        Task* newTasks = new Task[_sizeTasks + 1];

        for (int i = 0; i < _sizeTasks; i++) {
            newTasks[i] = _tasks[i];
        }
        newTasks[_sizeTasks] = task;
        _sizeTasks++;
        delete[] _tasks;
        _tasks = newTasks;
    }

    void displayActiveTasks() {
        for (int i = 0; i < _sizeTasks; i++) {
            if (_tasks[i].getIsActive())
                _tasks[i].display();
        }
    }

    void displayArchiveTasks() {
        for (int i = 0; i < _sizeTasks; i++) {
            if (!_tasks[i].getIsActive())
                _tasks[i].display();
        }
    }

    void addTaskFromKeyboard() {
        string title;
        string description;
        string timeDeadline;

        cout << "Введите название" << endl;
        cin >> title;
        cout << "Введите описание" << endl;
        cin >> description;
        cout << "Введите время дедлайна" << endl;
        cin >> timeDeadline;


        Task newTask = Task(title, description, timeDeadline, 0, true);
        pushTask(newTask);
    }

    void startManager() {
        bool flag = true;
        while (flag) {
            // Работает только на windows
            int choice;
            cout << "Введите действие: " << endl;
            cout << "1. Вывести активные задачи" << endl;
            cout << "2. Вывести архивные задачи" << endl;
            cout << "3. Добавить задачу" << endl;
            cout << "4. Выйти из программы" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                displayActiveTasks();
                break;

            case 2:
                displayArchiveTasks();
                break;
            case 3:
                addTaskFromKeyboard();
                break;
            case 4:
                flag = false;
                break;
            default:
                break;
            }
        }
    }

    Task* SortByPriority() {
        Task swap;
        for (int i = 0; i < _sizeTasks; i++) {
            for (int j = 0; j < _sizeTasks; j++) {
                if (_tasks[j].getPriority() < _tasks[j + 1].getPriority()) {
                    swap = _tasks[j];
                    _tasks[j] = _tasks[j + 1];
                    _tasks[j + 1] = swap;
                }
            }
        }
            return _tasks;
        }
    
    void GoToArchive(int num) {
        _tasks[num].setIsActive(false);
    }
};




int main()
{
    setlocale(LC_ALL, "rus");
    TaskManager window = TaskManager();
    window.pushTask(Task("Название 1", "Описание 1", "10.02.2025 10:25", 1, true));
    window.pushTask(Task("Название 2", "Описание 2", "10.02.2025 10:30", 0, true));
    window.pushTask(Task("Название 3", "Описание 3", "10.02.2025 10:40", 2, true));
    window.SortByPriority();
    window.GoToArchive(0);//по индексу
    window.startManager();
}
