/*
Implement a basic singly linked list with insert and display functions.

Input:
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.display();
Output:
1 -> 2 -> 3 -> nullptr

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode; //insert at the head
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(3);
    list.insert(2);
    list.insert(1);

    list.display();

    return 0;
}



/*
This program defines a simple singly linked list class LinkedList with a basic Node class representing each element in the list.
The LinkedList class has an insert function to insert elements at the beginning of the list and a display function to print the elements
in the list.

*/
