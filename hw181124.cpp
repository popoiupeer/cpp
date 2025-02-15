#include<iostream>
using namespace std;



void transponMatrix(int** matrix, int size_X, int size_Y) {
    for (int i = 0; i < size_X; i++) {


        for (int j = 0; j < size_Y; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}
void printMatrix(int** matrix, int size_X, int size_Y) {
    for (int i = 0; i < size_X; i++) {


        for (int j = 0; j < size_Y; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int** getRandomMatrix(int size_X, int size_Y) {
    int** matrix = new int* [size_X];

    for (int i = 0; i < size_X; i++) {
        matrix[i] = new int[size_Y];

        for (int j = 0; j < size_Y; j++) {
            matrix[i][j] = rand() % 9 + 1;
        }
    }

    return matrix;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int** matrix = getRandomMatrix(5, 5);
    cout << "матрица:"<<endl;
    printMatrix(matrix, 5, 5);
    cout << "транспонированная матрица:" << endl;
    transponMatrix(matrix, 5, 5);
    return 0;
}
