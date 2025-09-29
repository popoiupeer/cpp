#include <iostream>
#include <unordered_map>
using namespace std;
//class Contact {
//private:
//	string name;
//	string num;
//public:
//	Contact() {
//		name = "";
//		num = "";
//	}
//	Contact(string name, string num) {
//		this->name = name;
//		this->num = num;
//	}
//	string GetName() {
//		return name;
//	}
//	string GetNum() {
//		return num;
//	}
//};

void PushContact(unordered_map<string, string>& con, string name, string num) {
	con.insert({ name, num });
	cout << "Контакт добавлен\n";
}
void DeleteContact(unordered_map<string, string>& con, string name) {
	con[name].clear();
	cout << "Контакт удален\n";
}
string SearchNum(unordered_map<string, string> con, string name) {
	for (auto& c : con) {
		if (c.second == name) {
			return c.first;
		}
	}
}
void PrintAll(unordered_map<string, string> con) {
	for (auto& c : con) {
		cout << "Имя контакта: " << c.first << "\nНомер телефона: " << c.first<< endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	unordered_map<string, string> contact;
	int a = 0;
	string name, num;
	while (a != 5) {
	cout << "Выберите функицю:\n1-Добавить контакт\n2-Удалить контакт\n3-Найти все контакты по имени\n4-Вывести все контакты\n5-Завершить программу\n";
	cin >> a;
		switch (a) {
		case 1:
			cout << "Введите имя контакта" << endl;
			cin >> name;
			cout << "Введите номер контакта" << endl;
			cin >> num;
			PushContact(contact, name, num);
			break;
		case 2:
			cout << "Введите имя" << endl;
			cin >> name;
			DeleteContact(contact, name);
			break;
		case 3:
			cout << "Введите имя" << endl;
			cin >> name;
			SearchNum(contact, name);
			break;
		case 4:
			PrintAll(contact);
			break;
		}
	}
}

