#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void funct(int** arr, int sizex, int sizey) {
    int st;
    for (int i = 0; i < sizex; i++) {
        int min = arr[i][0];
        st = 0;
        for (int j = 1; j < sizey; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
                st = j;
            }
        }
        int prov=1;
        for (int k = 0; k < sizex; k++) {
            if (arr[k][st] > min) {
                prov = 0;
                
            }
        }
        if (prov==1) {
            cout << "cедловая точка: " << min ;
        }
    }
}



int main()
{
    setlocale(LC_ALL, "rus");
    int sizex = 3;
    int sizey = 3;
    int a = 1;
    int** arr = new int* [sizex];
    for (int i = 0; i < sizey; i++) 
        arr[i] = new int[sizey];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = a;
            a++;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    funct(arr, sizex, sizey);
    
}
