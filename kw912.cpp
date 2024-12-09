#include <iostream> 
#include "string.h" 
using namespace std; 
int* vo(int* arr, int size) { 
    int* newarr = new int[size / 2]; 
    int i = 0; 
    for (int j = 1; j < size; j = j + 2) { 
        newarr[i] = arr[j]; 
        i++; 
    } 
 
    return newarr; 
} 
int min(int* arr, int size) { 
    int minim = arr[0]; 
    for (int i = 0; i < size; i++) { 
        if (arr[i] < minim) { 
            minim = arr[i]; 
        } 
    } 
    return minim; 
} 
int max(int* arr, int size) { 
    int minim = arr[0]; 
    for (int i = 0; i < size; i++) { 
        if (arr[i] > minim) { 
            minim = arr[i]; 
        } 
    } 
    return minim; 
} 
int strok(string& str) { 
    int num = 1; 
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] == ' ') { 
            num++; 
        } 
    } 
    return num; 
} 
 
 
void pal(string& str) { 
    int a = 0; 
    for (int i = 0; i < str.size(); i++) { 
        for (int j = 0; j > str.size(); j--) { 
            if (str[i] == str[j]) { 
                a++; 
            } 
        } 
    } 
    if (a == str.size()) { 
        cout << "строка палиндром"; 
    } 
    else { cout << "строка не палиндром"; 
    } 
} 
void sort(int * arr, int size) { 
    int a = arr[0]; 
    int b = 0; 
    for (int i = 0; i < size ; i++) { 
        for (int j = 0; j < size; j++) { 
            if (a > arr[i]) { 
                b = a; 
                a = arr[i]; 
                arr[i] = b; 
            } 
        } 
    } 
    for (int i = 0; i < size; i++) { 
        cout << arr[i]<<" "; 
    } 
} 
void printArr(int* arr, int size) { 
    for (int i = 0; i < size; i++) { 
        cout << arr[i] << " "; 
    } 
} 
int schet (string& str, char a) { 
    int o=0; 
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] == a) { 
            o++; 
        } 
    } 
    return o; 
} 
void raan(int* arr, int size) { 
    for (int i = 0; i < size; i++) { 
        arr[i] = rand()%10 ; 
    } 
    for (int i = 0; i < size; i++) { 
        cout << arr[i]<<" "; 
 
    } 
} 
double ara(int* arr, int size) { 
    double a=0; 
    for (int i = 0; i < size; i++) { 
        a += arr[i]; 
    } 
    return a / size; 
} 
 
int main() 
{ 
    setlocale(LC_ALL, "rus"); 
    int* arr = new int[6] {8,24,13,4,51,2}; 
    int** u = &arr; 
    string str = "asd asd dsa"; 
    string* strr = &str; 
 
    int* ar = vo(arr, 6); 
    char a = 'a'; 
    cout << "четные элементы "; 
    printArr(ar,3); 
    cout << endl; 
    cout<<"min: " << min(arr, 6)<<endl; 
    cout  <<"max: "<<max(arr, 6)<<endl; 
    cout << "сортированный: "; 
    sort(arr, 6); 
    cout << endl; 
    pal(*strr); 
    cout << endl; 
    cout << "рандом: "; 
    raan(arr, 6); 
    cout << endl; 
    cout << "количество слов а: "; 
    cout << strok(*strr); 
    cout << endl; 
    cout << "количество символов: "; 
    cout << schet(*strr, a); 
    cout << endl; 
    cout << "среднее арифметическое: "; 
    cout << ara (arr,6); 
}
