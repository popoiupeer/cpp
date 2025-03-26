#include <iostream>
using namespace std;

//persona-stud
//persona-prepod-zavkafedr

class Person {
protected:
    int age;
    string name;
public:
    virtual void print() = 0;
};
class Stud:public Person {
protected:
    string group;
public:
    Stud() {
        age = 0;
        name = "";
        group = "";
    }
    Stud(int age, string name, string group) {
        this->age = age;
        this->name = name;
        this->group = group;
    }
    void print() {
        cout << "age: " << age << endl;
        cout << "name: " << name << endl;
        cout << "group: " << group << endl;
    }
    friend ostream& operator<<(ostream& out,Stud s) {
        out << "age: " << s.age << endl;
        out << "name: " << s.name << endl;
        out << "group: " << s.group << endl;
        return out;
    }
};
class Teacher:public Person {
protected:
    int count_groups;
    int salary;
public:
    Teacher() {
        age = 0;
        name = "";
        count_groups = 0;
        salary = 0 ;
    }
    Teacher(int age, string name,int cou, int sal ) {
        this->age = age;
        this->name = name;
        this->count_groups = cou;
        this->salary = sal;
    }
    void print() {
        cout << "age: " << age << endl;
        cout << "name: " << name << endl;
        cout << "count os groups: " << count_groups << endl;
        cout << "salary: " << salary << endl;
    }
    friend ostream& operator<<(ostream& out, Teacher t) {
        out << "age: " << t.age << endl;
        out << "name: " << t.name << endl;
        out << "count os groups: " << t.count_groups << endl;
        out << "salary: " << t.salary << endl;
        return out;
    }
};
class ZavKafed:Teacher{
private:
    int yearofwork;
public:
    ZavKafed() {
        age = 0;
        name = "";
        count_groups = 0;
        salary = 0;
        yearofwork = 0;
    }
    ZavKafed(int age, string name, int cou, int sal, int year) {
        this->age = age;
        this->name = name;
        this->count_groups = cou;
        this->salary = sal;
        this->yearofwork = year;
    }
    void print() {
        cout << "age: " << age << endl;
        cout << "name: " << name << endl;
        cout << "count os groups: " << count_groups << endl;
        cout << "salary: " << salary << endl;
        cout << "year of work: " << yearofwork << endl;
    }
    friend ostream& operator<<(ostream& out, ZavKafed z) {
        out << "age: " << z.age << endl;
        out << "name: " << z.name << endl;
        out << "count os groups: " << z.count_groups << endl;
        out << "salary: " << z.salary << endl;
        out << "year of work: " << z.yearofwork << endl;
        return out;
    }
};

int main()
{
    Teacher Denis{ 24,"Denis",2,4000000 };
    cout << Denis << endl;
    ZavKafed Roman{ 46,"Roman",1,4000000 , 20 };
    cout << Roman;
}
