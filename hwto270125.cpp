#include <iostream>
using namespace std;

void per(int**arr, int n, int an) {
    if (an == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    int** res = new int* [n];
    if (an == 90) {
        for (int a = 0; a < 3; a++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = arr[j][i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << endl;
        }
    }
    if (an == 180) {
        for (int a = 0; a < 2; a++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = arr[j][i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << endl;
        }
    }
    if (an == 270) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = arr[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << endl;
        }
    }
}

int main()
{
    int n = 4;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = i;
        }
    }
    per(arr, n, 90);
} 
