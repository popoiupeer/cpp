#include <iostream>
using namespace std;

class Socks {
private:
    string color;
    int size;
    int cost;
public:
    string Getcols() {
        return color;
    }
    int Getsizes() {
        return size;
    }
    int Getcosts(){
        return cost;
    }
    void Setcols(string color) {
        this->color = color;
    }
    void Getsizes(int size) {
        this->size = size;
    } 
    void Setcosts(int cost) {
        this->cost = cost;
    }
    void Printsocks() {
        cout <<"color: " << color << endl;
        cout <<"size: " << size << endl;
        cout << "cost: " << cost << endl;
    }
};
class Shoes {
private:
    int size;
    string color;
    string material;
    int cost;
public:
    string Getcol() {
        return color;
    }
    int Getsize() {
        return size;
    }
    int Getcost() {
        return cost;
    }
    string Getmat() {
        return material;
    }
    void Setcol(string color) {
        this->color = color;
    }
    void Getsize(int size) {
        this->size = size;
    }
    void Setcost(int cost) {
        this->cost = cost;
    }
    void Setmat(string material) {
        this->material = material;
    }
    void Printshoes() {
        cout << "color: " << color << endl;
        cout << "size: " << size << endl;
        cout << "cost: " << cost << endl;
        cout << "materisl: " << material << endl;
    }
};
class Hats {
private:
    int size; 
    string color;
    string type;
public:
    int Getsizeh() {
        return size;
    }
    string Getcolorh() {
        return color;
    }
    string Gettypeh() {
        return type;
    }
    void Setsizeh(int size) {
        this->size = size;
    }
    void Setcolorh(string color) {
        this->color = color;
    }
    void Settypeh(string type) {
        this->type = type;
    }
    void Printallh() {
        cout << "size: " << size << endl;
        cout << "color: " << color << endl;
        cout << "type: " << type << endl;
    }
};

int main()
{
    Hats b;
    b.Setcolorh("black");
    b.Setsizeh(50);
    b.Settypeh("ushanka");
    b.Printallh();
}
