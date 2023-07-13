/*
 Write a program to create a linked list using dynamic memory allocation.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head ==    NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);

    cout << "Linked List: ";
    displayList(head);

    deleteList(head);

    return 0;
}

/*
This program creates a linked list using dynamic memory allocation. It defines functions to create a new node, insert
a node at the end of the list, display the list, and delete the list.
The main function demonstrates the usage of these functions by inserting elements into the list, displaying the list,
and deallocating the memory.
*/
