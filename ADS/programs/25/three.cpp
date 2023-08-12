/*
Implement a singly linked list with operations to insert elements at the front, end, and a specific position in the list, and to
delete elements from the list.

Input:
insertEnd(5);
insertFront(3);
insertAtPosition(4, 2);
insertEnd(7);
deleteElement(4);

Output:
3 4 5 7
3 5 7


*/

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to insert an element at the front of the linked list
    void insertFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert an element at the end of the linked list
    void insertEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Function to insert an element at a specific position in the linked list
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node;
        newNode->data = data;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position.\n";
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to delete an element from the linked list
    void deleteElement(int data) {
        Node* temp = head;
        Node* prev = nullptr;

        // If the element to be deleted is at the head
        if (temp != nullptr && temp->data == data) {
            head = temp->next;
            delete temp;
            return;
        }

        // Search for the element to be deleted
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        // If the element is not found
        if (temp == nullptr) {
            cout << "Element not found.\n";
            return;
        }

        // Unlink the node from the list and free memory
        prev->next = temp->next;
        delete temp;
    }

    // Function to print the elements of the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertEnd(5);
    list.insertFront(3);
    list.insertAtPosition(4, 2);
    list.insertEnd(7);
    list.printList();

    list.deleteElement(4);
    list.printList();

    return 0;
}

/*
This program implements a singly linked list with basic operations. The Node struct represents a node in the linked list, and the SinglyLinkedList class provides functions to insert elements at the front, end, and a specific position in the list, as well as delete elements from the list. The linked list is dynamically allocated, and memory is freed after deleting elements to avoid memory leaks.

When the program is executed, it creates a singly linked list, inserts elements at the front, end, and a specific position, and then prints the list. It then deletes an element and prints the updated list.

*/


