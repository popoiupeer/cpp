#include <iostream>
using namespace std;
#include "string"

void glas(string str) {
	for (int i = 0; i < str.size();i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o') {
			str[i] = '_';
		}
		else {
			str[i] = str[i];
		}
	}
	cout << str;
	
}
void Atoa(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (int(str[i]) >= 65 && int(str[i]) <= 90) {
			str[i] = int(str[i]) + 32;
		}
		

	}
	cout << str;
}

	int main() {
	setlocale(LC_ALL, "rus");
	string str="QweRtY";
	cout<<endl;
	glas(str);
	string test = "QWer";
	Atoa(test);
	
}
