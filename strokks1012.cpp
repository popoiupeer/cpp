#include <iostream> 
#include "string.h" 
using namespace std;
  string* returnTest(string& str) {//функция которая принимает адрес строки
    string* stringPtr = new string;//создание переменной котрая хранит адрес строки 
    *stringPtr = "New Test";//обращение и заполнение значения строки которая находится по адресу 0x0000024df43f5c60 

    return stringPtr;//возврат адреса принимаемой строки 0x0000024df43f5c60
}
int main()
{
    setlocale(LC_ALL, "rus");
    string str = "test";//создание и объявление строки
    string* newStr = returnTest(str);//создание указателя на адрес которое вернула функция
    cout << newStr << endl;//вывод адреса который вернула функция 0x0000024df43f5c60
    cout << *newStr << endl;//вывод значения адреса который вернула функция "New Test"
    cout << &*newStr << endl;//вывод адреса переменной которая хранит значение адреса который вернула функция 0x0000028eae3e70f0 

}
