#include <iostream>  
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

Node* InitializeList(int size) {
    Node* head = new Node();
    Node* current = head;
    current->value = 0;
    for (int i = 0; i < size - 1; i++) {
        current->next = new Node();
        current = current->next;
        current->value = 0;
    }
    return head;
}

void PrintList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
}
bool contains(Node* head, int target) {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (target == current->value) {
            return true;
            index++;
        }
        current = current->next;
    }
    return false;
}
int maxofl(Node* head) {
    Node* current = head;
    int max = current->value;
    while (current != nullptr) {
        if (max < current->value) {
            max = current->value;
        }
        current = current->next;
    }
    return max;
}
int minofl(Node* head) {
    Node* current = head;
    int min = current->value;
    while (current != nullptr) {
        if (min > current->value) {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}

int summofl(Node* head) {
    Node* current = head;
    int summ = 0;
    while (current != nullptr) {
        summ = summ + current->value;
        current = current->next;
    }
    return summ + 1;
}

Node* DeleteElementFromList(Node* head, int index) {
    Node* current = head;
    while (current != nullptr) {
        if (1 == index) {
            Node* rep = current->next;
            current->next = current->next->next;
            delete rep;
        }
        index--;
        return head;
    }
}
Node* copyl(Node* head) { 
    Node* current = head; 
    Node* current1 = head; 
    while (current != nullptr) { 
 
    } 
} 
void DeleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* rep = current->next;
        current->next = current->next->next;
        delete rep;
    }
}
Node* StaticArrayToList(int arr[], int size) {
    Node* head = new Node();
    Node* current = head;
    for (int i = 0; i < size; i++) {
        current->next = new Node();
        current->value = arr[i];
        current = current->next;
    }return head;
}
void SwapList(Node* head, int index1, int index2) {
    Node* current = head;
    int swap = 0;
    while (current != nullptr) {
        if (index1 == 1) {
            Node* swap1 = current->next;
            current->next = current->next->next;
        }
    }
    current->value = swap;
}
void col(Node* head) {
    Node* current = head;
    int size = 0;
    while (current != nullptr) {
        size++;
    }
    cout << size;
}
Node* DynamicArrayToList(int* array, int size) { 
    Node* head = new Node(); 
    Node* current = head; 
    for (int i = 0; i < size; i++) { 
        current->next = new Node(); 
        current->value = array[i]; 
        current = current->next; 
    }return head; 
} 
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    Node* test = InitializeList(5);
    test->value = 1;
    test->next->value = 2;
    test->next->next->value = 3;
    test->next->next->next->value = 4;
    test->next->next->next->next->value = 5;

    cout << "изначальный массив: " << endl;
    PrintList(test);
    cout << endl;
    cout << contains(test, 1) << endl;
    //cout << "удален первый элемент массива: "; 
    //DeleteElementFromList(test,1);  
    //PrintList(test);  
    cout << endl;
    cout << "сумма всех элементов массива: " << summofl(test) << endl;
    /*DeleteList(test);*/
    int arr[5]{ 1,2,3,4,5 };
    PrintList(StaticArrayToList(arr, 5));//int* array[5]; 
    //cout << endl<<"динамический: "; 
    //PrintList(DynamicArrayToList(*array, 5)); 
    col(test);
}
