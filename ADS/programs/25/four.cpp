/*
 Implement a linked list and insert elements at the beginning.

Input: Enter elements for linked list (enter -1 to stop): 4 5 3 -1
Output: Linked List: 3 5 4

*/

#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert an element at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    return newNode;
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

        head = insertAtBeginning(head, data);
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
This program demonstrates insertion at the beginning of a linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the beginning of the linked list. After creating the linked list, the elements are displayed, and memory is freed by deleting the nodes.

*/
