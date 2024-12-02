#include <iostream>
using namespace std;
#include "string"
void lampf() {
	cout << "         |||| " << endl;
	cout << "        /----\\"<<endl;
	cout << "       |  ||  |" << endl;
	cout << "       |  ||  |" << endl;
	cout << "       |  %%  |" << endl;
	cout << "        \\____/" << endl;

}
void lampn() {
	cout << "    \033[33m     |||| " << endl;
	cout << "        /----\\" << endl;
	cout << "       |  ||  |" << endl;
	cout << "       |  ||  |" << endl;
	cout << "       |  \033[31m&&\033[33m  |" << endl;
	cout << "        \\____/\033[0m" << endl;

}




	int main() {
	setlocale(LC_ALL, "rus");

	int s;
	cout << "введите число(1-включено, 0-выключено):";
	cin >> s;
	if (s == 0) {
		lampf();
	}
	else if (s == 1) {
		lampn();
	}
	int reb;
	cin >> reb;
	cout << "v=" << reb * 3 << "\ns=" << reb * 2;
	int m1, m2, r;
	cout << "введите массу первого тела в кг ";
	cin >> m1;
	cout << "введите массу второго тела в кг ";
	cin >> m2;
	cout << "введите расстояние в м ";
	cin >> r;
	double f = ((m1 * m2) / r ^ 2) * 0.0000000000667;
	cout << f;
	int x, y;
	cout << "введите х";
	cin >> x;
	cout << "введите y";
	cin >> y;
	if (x > y) {
		cout << "z=" << x - y;
	}
	else cout << "z=" << y - x + 1;
	double num1, num2, num3;
	cout << "введите числа";
	cin >> num1 >> num2 >> num3;
	if (num1 < 3 && num1>1) {
		cout << num1;
	}if (num2 < 3 && num2>1) {
		cout << num2;
	}
	if (num3 < 3 && num3>1) {
		cout << num3;
	}
	
    int yer;
	cin >> yer;
	if (yer < 100) {
		if (yer > 10 && yer < 20) {
			cout << yer << "лет";
		}
		else if (yer % 10 > 4 && yer % 10 < 10) {
			cout << yer << "лет";
		}
		else if (yer % 10 == 4 || yer % 10 == 3 || yer % 10 == 2) {
			cout << yer << "года";
		}
		else if (yer % 10 == 1) {
			cout << yer << "год";
		}
		else if (yer % 10 == 0) {
			cout << yer << "лет";
		}
	}
	else { cout << "возраст больше 100";
	}
		
	double tc=0;
	double tf=0;
	for (int i = 0; i < 101; i++) {
		cout <<i+1<<"- "<< i<<" ";
	}
	cout << endl;
	for (int i = 0; i < 101; i++) {
		tf = 1.8 * tc;

		cout << i << "- " << tf + 32 << " ";
		tc ++;
	}
	int x;
	cout << "введите число ";
	cin >> x;
	if (x < 0) {
		cout << "f(x)= " << -x;
	}
	else if (x > 0) {
		cout << "f(x)= -" << x * x;
	}
	double r;
	cin >> r;
	cout << "площадь кольца-" << (3.14 * r * r) - 1256;
	int s;
	cout << "введите число(1-включить,2-выключить) ";
	cin >> s;
	if (s == 1) {
		cout << ;
	}
	
	
}
