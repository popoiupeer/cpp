#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int mass[5];
	int a;
	cout << "введите 5 значений в массив"<<endl;
	cin >> mass[0] >> mass[1] >> mass[2] >> mass[3] >> mass[4];
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (mass[i] == mass[j]) {
				cout << "элемент " << mass[i] << " повторяется." << endl;
			}
		}
	}
}
