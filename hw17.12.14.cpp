cpp
#include <iostream> 
int* sort(int* arr[], int size) { 
    int a = *arr[0]; 
    for (int i = 0; i < size*size; i++) { 
        if (a > *arr[i]) { 
            a = *arr[i + 1]; 
            *arr[i + 1] = *arr[i]; 
            *arr[i] = a; 
        } 
    } 
    int* res = *arr; 
    return res; 
} 
 
 
 
int* uniq(int * arr[], int size ) { 
    int* newarr = new int[size]; 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            if (arr[i] == arr[j]) 
            { 
                *arr[j] = 0; 
            } 
        } 
    } 
    for (int i = 0; i < size; i++) { 
        if (arr[i] != 0) { 
            newarr[i] = *arr[i]; 
             
        } 
    } 
    int* res = newarr; 
    return res; 
} 
int main() 
{ 
    int size=10; 
    int* arr = new int[size]; 
    for (int i = size-1; i > 0; i--) { 
        arr[i] = i; 
    } 
     
    int* q = &size; 
    int* newarr = sort(&*&arr, size); 
    newarr = uniq(&*&arr, size); 
}
