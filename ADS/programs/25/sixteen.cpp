/*
 Implement a singly linked list and delete a node at a given position from the list.

 Input:
 Enter elements for linked list (enter -1 to stop): 8 9 12 4 2 1 -1
 Linked List before deleting nodes: 8 9 12 4 2 1
 Enter the position of the node to be deleted (0-indexed): 2

 Output: Linked List after deleting nodes: 8 9 4 2 1

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

// Function to delete a node at a given position from the linked list
Node* deleteNodeAtPosition(Node* head, int position) {
    if (head == nullptr) {
        return nullptr;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;
    int currentPosition = 0;

    while (current != nullptr && currentPosition < position) {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        return head; // Node at the given position not found
    }

    prev->next = current->next;
    delete current;

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

    // Prompt the user to enter the position of the node to be deleted
    int position;
    cout << "\nEnter the position of the node to be deleted (0-indexed): ";
    cin >> position;

    // Delete the node at the given position from the linked list
    head = deleteNodeAtPosition(head, position);

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

The user is then prompted to enter the position (0-indexed) of the node to be deleted from the linked list. The program traverses the linked list and deletes the node at the given position. The updated linked list is displayed, and memory is freed by deleting the nodes.

*/

