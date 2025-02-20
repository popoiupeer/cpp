#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int salary;
public:
    Employee(string nam, int sal){
        name = nam;
        salary = sal;
    }
    Employee() {
        name = "";
        salary = 0;
    }
    virtual int CalculateBonus() {
        return 15;
    }
};
class Manager:Employee {
private:
    int numSub;
public: 
    Manager(string nam, int num, int sal) {
        numSub = num;
        name = nam;
        salary = sal;
    }
    Manager() {
        numSub = 0;
    }
    int numS() {
        return numSub;
    }
    int CalculateBonus() override {
        return salary / numSub * 10;
    }
};
class Developer :Employee {
private:
    int numProj;
public:
    Developer( string nam, int num, int sal):Employee() {
        numProj = num;
        name = nam;
        salary = sal;
    }
    Developer() {
        numProj = 0;
    }
    int numPr() {
        return numProj;
    }
    int CalculateBonus() override {
        return salary / numProj * 5;
    }
};

class Intern :Employee {
private:
    int intShip;
public:
    Intern(string nam, int num, int sal) {
        intShip = num;
        name = nam;
        salary = sal;
    }
    Intern() {
        intShip = 0;
    }
    int CalculateBonus() override {
        if (intShip >= 3)
            return 15;
        return 0;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Employee a{ "asd", 15000 };
    Employee* b = &a;
    b->CalculateBonus();
    Developer c{ "asdaf", 20000, 3 };
    

}
