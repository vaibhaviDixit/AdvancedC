/*
Implement a linked list with inserting elements from the end.

Input: Enter elements for linked list (enter -1 to stop): 5 7 9 -1
Output: Linked List: 5 7 9

*/

#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert an element at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display the linked list
void displayLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;
    int data;

    // Create the linked list with user input
    cout << "Enter elements for linked list (enter -1 to stop):\n";
    while (true) {
        cin >> data;
        if (data == -1)
            break;

        head = insertAtEnd(head, data);
    }

    // Display the linked list
    cout << "Linked List: ";
    displayLinkedList(head);

    // Free memory by deleting nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
This program demonstrates insertion at the end of a linked list. The user is prompted to enter elements for the linked list until
they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed, and memory is freed by deleting the nodes.

*/
