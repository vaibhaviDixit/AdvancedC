/*
 Implement a linked list and delete a node with a given value.

 Input: Enter elements for linked list (enter -1 to stop): 9 5 4 3 -1
        Linked List before deletion: 9 5 4 3
        Enter a value to delete from the linked list: 5

 Output: Linked List after deletion: 9 4 3


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

// Function to delete a node with the given value from the linked list
Node* deleteNodeWithValue(Node* head, int value) {
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
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            break;
        }
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

    // Display the linked list before deletion
    cout << "Linked List before deletion: ";
    displayLinkedList(head);

    int value;
    cout << "\nEnter a value to delete from the linked list: ";
    cin >> value;

    // Delete the node with the given value
    head = deleteNodeWithValue(head, value);

    // Display the linked list after deletion
    cout << "Linked List after deletion: ";
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
This program demonstrates the deletion of a node with a given value from a linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The user is then prompted to enter a value to be deleted from the linked list. The program finds the node with the given value and deletes it from the linked list. After deletion, the updated linked list is displayed, and memory is freed by deleting the nodes.

*/
