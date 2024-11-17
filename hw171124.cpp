using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int mass[20];
    int mass2[10] = { 0,0,0,0,0,0,0,0,0,0 };

    cout << "Введите 20 чисел от 0 до 9"<<endl;
    for (int i = 0; i < 20; i++) {
        cin >> mass[i];
        mass2[mass[i]]++;
    }

    cout << "Гистограмма частоты:"<<endl;
    for (int i = 0; i < 10; ++i) {
        cout << i << ": ";
        for (int j = 0; j < mass2[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
