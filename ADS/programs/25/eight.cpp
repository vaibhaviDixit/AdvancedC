/*
Implement a linked list and find the middle node.

Input: Enter elements for linked list (enter -1 to stop): 4 6 8 9 12 -1
Output:
Linked List: 4 6 8 9 12
Middle Node: 8

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

// Function to find the middle node of the linked list
Node* findMiddleNode(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    // Find the middle node of the linked list
    Node* middleNode = findMiddleNode(head);

    if (middleNode != nullptr) {
        cout << "\nMiddle Node: " << middleNode->data;
    } else {
        cout << "\nLinked List is empty.";
    }

    // Free memory by deleting nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
This program demonstrates finding the middle node of a linked list. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The middle node of the linked list is found using a two-pointer approach. A slow pointer advances one node at a time, while a fast pointer advances two nodes at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node (or middle-left node if the list has an even number of nodes). The middle node is then displayed, and memory is freed by deleting the nodes.

*/
