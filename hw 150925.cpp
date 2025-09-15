#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }


    void addFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void removeFirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    List list;
    list.addFirst(4);
    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);
    list.print();
    return 0;
}
