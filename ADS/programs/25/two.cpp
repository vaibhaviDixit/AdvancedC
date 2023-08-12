/*

Given a singly linked list. Find the number of nodes present in the linked list.

Input: Enter elements for linked list (enter -1 to stop): 9 8 5 12 4 7 5 1 -1
       Linked List: 9 8 5 12 4 7 5 1
Output: Length of the Linked List: 8

Input: Enter elements for linked list (enter -1 to stop): -1
Linked List:
Output: Length of the Linked List: 0

*/

#include <iostream>
using namespace std;

// Node structure for singly linked list
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

// Function to find the length of the linked list
int findLength(Node* head) {
    int length = 0;
    Node* current = head;

    while (current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
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

    // Find the length of the linked list
    int length = findLength(head);

    // Display the length of the linked list
    cout << "\nLength of the Linked List: " << length << endl;

    // Free memory by deleting nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
This program allows the user to create a singly linked list by entering elements until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The program then calculates the length of the linked list by traversing the linked list and counting the number of nodes. The length of the linked list is displayed, and memory is freed by deleting the nodes.

*/


