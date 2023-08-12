/*
Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

Input:
Enter elements for linked list (enter -1 to stop):
7 8 5 1 9 -1
Linked List before insertion: 7 8 5 1 9
Enter the key to be inserted in the middle: 99

Output: Linked List after insertion: 7 8 5 99 1 9

*/

#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
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

// Function to find the middle node of the linked list
Node* findMiddleNode(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to insert the key in the middle of the linked list
Node* insertInMiddle(Node* head, int key) {
    if (head == nullptr) {
        return nullptr;
    }

    // Find the middle node
    Node* middle = findMiddleNode(head);

    // Create a new node with the key
    Node* newNode = new Node;
    newNode->data = key;

    // Insert the new node after the middle node
    newNode->next = middle->next;
    middle->next = newNode;

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
    int data, key;

    // Create the linked list with user input
    cout << "Enter elements for linked list (enter -1 to stop):\n";
    while (true) {
        cin >> data;
        if (data == -1)
            break;

        head = insertAtEnd(head, data);
    }

    // Display the linked list before inserting the key
    cout << "Linked List before insertion: ";
    displayLinkedList(head);

    // Prompt the user to enter the key to be inserted
    cout << "\nEnter the key to be inserted in the middle: ";
    cin >> key;

    // Insert the key in the middle of the linked list
    head = insertInMiddle(head, key);

    // Display the linked list after inserting the key
    cout << "Linked List after insertion: ";
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
This program inserts a given key in the middle of a linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The program then prompts the user to enter the key to be inserted in the middle of the linked list. The middle node of the linked list is found using the "findMiddleNode" function, and a new node with the key is inserted after the middle node using the "insertInMiddle" function. The updated linked list is displayed, and memory is freed by deleting the nodes.

*/




