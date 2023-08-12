/*
Implement a linked list and reverse it.

Input: Enter elements for linked list (enter -1 to stop):
       4 5 7 8 -1
       Linked List before reversal: 4 5 7 8
Output: Linked List after reversal: 8 7 5 4

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

// Function to reverse the linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
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

    // Display the linked list before reversal
    cout << "Linked List before reversal: ";
    displayLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Display the reversed linked list
    cout << "\nLinked List after reversal: ";
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
This program demonstrates the reversal of a linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The program then reverses the linked list using an iterative approach. The nodes of the linked list are reversed by adjusting their next pointers. After reversal, the updated linked list is displayed, and memory is freed by deleting the nodes.

*/
