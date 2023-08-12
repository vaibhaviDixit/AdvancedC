/*
Implement a singly linked list and delete the first occurrence of a given value from the list.

Input:
Enter elements for linked list (enter -1 to stop):
3 5 9 12 5 8 -1
Linked List before deleting nodes: 3 5 9 12 5 8
Enter the value to be deleted from the linked list: 5

Output: Linked List after deleting nodes: 3 9 12 5 8

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

// Function to display the linked list
void displayLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Function to delete the first occurrence of a given value from the linked list
Node* deleteFirstNodeWithValue(Node* head, int value) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            prev->next = current->next;
            delete current;
            break;
        }

        prev = current;
        current = current->next;
    }

    return head;
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

    // Display the linked list before deleting nodes
    cout << "Linked List before deleting nodes: ";
    displayLinkedList(head);

    // Prompt the user to enter the value to be deleted
    int valueToDelete;
    cout << "\nEnter the value to be deleted from the linked list: ";
    cin >> valueToDelete;

    // Delete the first node with the given value from the linked list
    head = deleteFirstNodeWithValue(head, valueToDelete);

    // Display the linked list after deleting nodes
    cout << "Linked List after deleting nodes: ";
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
In this program, we implement a singly linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The user is then prompted to enter the value to be deleted from the linked list. The program traverses the linked list and deletes the first node with the given value. The updated linked list is displayed, and memory is freed by deleting the nodes.

*/
