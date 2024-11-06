#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int a, b=0;
	cout << "введите количество дней- ";
	cin >> a;
	for (int i = 0; i < a*2 ; i += 2)
	{
		b += 15 + i;
	}
		cout << "пройденное расстояние:"<< b <<"сантиметров";



  
	char a;
	cout << "введите символ ";
	cin >> a;
	int b, c;
	cout << " введите количество символов";
	cin >> b;
	cout << "1)горизонталь\n2)вертикаль ";
	cin >> c;
	for (int i = 0; i < b; i++) {
		if (c == 1) { cout << a; }
		else {
			cout << a << endl;
		}
	}



  
	int a = 1000;
	for (int i = 3; i <= a; i++)
	{
		for (int y = 2; y <= a; y++)
		{
			if (i % y == 0) {
				if (i != y)
					break;
				cout << i << endl;
				break;
			}
		}
	}



  
	int a, b = 0;
	cout << "введите пятизначное число- ";
	cin >> a;
	for (int i = 0; i < 5; i++) {
		b += (a % 10);
		a= a / 10;
	}
	cout <<"сумма цифр вашего числа равна- " << b;



  
	int a = 0; 
	for (int i = 0; i <= 9; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == i) continue; 
			for (int q = 0; q <= 9; ++q) {
				if (q == i || q == j) continue;
				cout << i << j << q << endl;
				a++;
			}
		}
	}
	cout << "время затрачиваемое на открытие замка в худшем случае:" << a * 3 << " секунд";
		return 0;
	}

