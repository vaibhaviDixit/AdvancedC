/*
Implement a linked list and swap two nodes.

Input: Enter elements for linked list (enter -1 to stop): 6 8 9 12 17 -1
       Linked List before swapping nodes: 6 8 9 12 17
       Enter the positions (0-indexed) of the nodes to be swapped: 1 3

Output: Linked List after swapping nodes: 6 12 9 8 17

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

// Function to find the previous node of a given node in the linked list
Node* findPreviousNode(Node* head, Node* targetNode) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current == targetNode) {
            return prev;
        }
        prev = current;
        current = current->next;
    }

    return nullptr; // Target node not found
}

// Function to swap two nodes in the linked list
Node* swapNodes(Node* head, Node* node1, Node* node2) {
    if (head == nullptr || node1 == nullptr || node2 == nullptr) {
        return head;
    }

    // Find the previous nodes of node1 and node2
    Node* prevNode1 = findPreviousNode(head, node1);
    Node* prevNode2 = findPreviousNode(head, node2);

    // Check if any of the nodes are not present in the linked list
    if (prevNode1 == nullptr || prevNode2 == nullptr) {
        return head;
    }

    // Update the next pointers to swap the nodes
    prevNode1->next = node2;
    prevNode2->next = node1;

    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    // Update the head if either node1 or node2 was the head of the linked list
    if (head == node1) {
        head = node2;
    } else if (head == node2) {
        head = node1;
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

    // Display the linked list before swapping nodes
    cout << "Linked List before swapping nodes: ";
    displayLinkedList(head);

    // Prompt the user to enter the positions of the nodes to be swapped (0-indexed)
    int position1, position2;
    cout << "\nEnter the positions (0-indexed) of the nodes to be swapped: ";
    cin >> position1 >> position2;

    // Find the nodes to be swapped based on the positions entered
    Node* node1 = head;
    Node* node2 = head;

    for (int i = 0; i < position1 && node1 != nullptr; i++) {
        node1 = node1->next;
    }

    for (int i = 0; i < position2 && node2 != nullptr; i++) {
        node2 = node2->next;
    }

    // Swap the nodes
    head = swapNodes(head, node1, node2);

    // Display the linked list after swapping nodes
    cout << "Linked List after swapping nodes: ";
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
This program demonstrates swapping two nodes in a linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The user is then prompted to enter the positions (0-indexed) of the nodes to be swapped. The program finds the nodes based on the entered positions. It then swaps the nodes in the linked list by adjusting their next pointers. The updated linked list is displayed, and memory is freed by deleting the nodes.

*/

