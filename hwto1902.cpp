#include<iostream>
using namespace std;

class Wheels {
protected:
    int radius;
    string creator;
public:
};
class Engine {
protected:
    int horsepow;
    int volume;
public:
};
class Body {
protected:
    string type;
    int length;
public:
};
class ClassName {
protected:
    string Classname;
public:
};
class Car :Wheels, Engine, Body, ClassName {
    string name;
public:
    void print() {
        cout << "radius of wheels: " << radius << endl;
        cout << "creator of wheels: " << creator << endl;
        cout << "horse power: " << horsepow << endl;
        cout << "volume:: " << volume << endl;
        cout << "type of body: " << type << endl;
        cout << "length: " << length << endl;
        cout << "Classname: " << Classname << endl;
    }
    Car() {
        radius = 0;
        creator = "";
        horsepow = 0;
        volume = 0;
        type = "";
        length = 0;
        Classname = "";
    }
    Car(int rad, string creat, int hors, int vol, string type, int leng, string clas) {
        radius = rad;
        creator = creat;
        horsepow = hors;
        volume = vol;
        type = type;
        length = leng;
        Classname = clas;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Car a{ 250,"popo",2500,20,"sport",7,"Coupe" };
    a.print();
}
