#include <iostream>
#include "string.h"
using namespace std;

int glas(string str) {
    int gl = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || str[i] == 'A' || str[i] == 'E' || str[i] == 'Y' || str[i] == 'U' || str[i] == 'I' || str[i] == 'O') {
            gl++;
        }
        else {
            gl = gl;
        }
    }
    return gl;
}

void caez(string str, int n) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 32) {
            continue;
        }
        str[i] = str[i] + n;
        if (str[i] > 122 || str[i] > 90 && str[i] < 97) {
            str[i] -= 26;
        }
    }
    cout << str;
}
void atba(string str) {
    int n = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 32) {
            continue;
        }
        n = str[i];
        if (n > 90) {
            n = n - 96;
            n = 26 - (n - 1);
            n += 96;
        }
        else if (n < 91) {
            n = n - 64;
            n = 26 - (n - 1);
            n += 64;
        }
        str[i] = char(n);
    }
    cout << str;
}
void alphtonum(string str) {
    for (int i = 0; i < str.size(); i++) {
        int n = 0;
        if (str[i] == 32) {
            cout << " '  ' ";
        }
        n = str[i];
        if (n > 90) {
            n = n - 96;
            cout << " ' " << n << " ' ";
        }
        else if (n < 91) {
            n = n - 64;
            cout << " ' " << n << " ' ";
        }
        str[i] = char(n);
    }
}
string dupl(string str) {
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j]) {
                str[j] = 0;
            }
        }
    }
    return str;
}
void pol(string str) {
    int num = str.size();
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == str[num - 1 - i]) {
            res++;
        }

    }
    if (res == str.size()) {
        cout << "строка является палиндромом";
    }
    else {
        cout << "строка не является палиндромом";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    string str = "abcdezZ dfg";

    string test = "opopop";
    cout << "количество гласных в строке:" << glas(str) << endl;

    cout << "зашифрованная строка:";
    caez(str, 1);
    cout << endl;
    atba(str);
    cout << endl;
    alphtonum(str);
    cout << endl;
    cout << dupl(test);
    cout << endl;
    pol(test);

}
