#include <iostream>
using namespace std;
int fib(int num) {
	if (num == 1) { return  1; }
	else return fib(num - 1) + fib(num - 2);
}
int stepen(int num, int step) {
	if (step == 0) return 1;
	else if (step < 0) return 1 / stepen(num, -step);
	else return num * stepen(num, step - 1);
}
int main()
{
	std::cout << stepen(2, 5) << endl;
	std::cout << fib(5);
}
