#include <iostream>
using namespace std;

void matrix_auto_add(int** matrix, int x, int y) {
    int value = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            value++;
            matrix[i][j] = value;
        }
    }
}

void matrix_add(int** matrix, int x, int y) {
    cout << "Ручной ввод матрицы " << x << "x" << y << ":" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void print_all(int*** matrix, int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        cout << "Матрица " << i + 1 << ":" << endl;
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                cout << matrix[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void arr_matrix(int*** matrix, int size, int x, int y) {
    int choice;
    cout << "\n1-Авто ввод в матрицу\n2-Ручной ввод\n";
    cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < size; i++)
            matrix_auto_add(matrix[i], x, y);
    }
    else {
        for (int i = 0; i < size; i++)
            matrix_add(matrix[i], x, y);
    }
    print_all(matrix, size, x, y);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int x = 4, y = 5;
    cout << "Введите количество матриц в массиве\n";
    int size;
    cin >> size;

    int*** matrix = new int** [size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int* [x];
        for (int j = 0; j < x; j++) {
            matrix[i][j] = new int[y];
            for (int k = 0; k < y; k++) {
                matrix[i][j][k] = 0;
            }
        }
    }
    arr_matrix(matrix, size, x, y);

    return 0;
}
