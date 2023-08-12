/*
Implement a sorted linked list and remove duplicates.

Input:
Enter elements for sorted linked list (enter -1 to stop):
5 8 12 16 16 17 18 18 -1

Output:
Linked List before removing duplicates: 5 8 12 16 16 17 18 18
Linked List after removing duplicates: 5 8 12 16 17 18

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

// Function to remove duplicates from a sorted linked list
Node* removeDuplicates(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* current = head;
    Node* nextNode = head->next;

    while (nextNode != nullptr) {
        if (current->data == nextNode->data) {
            Node* temp = nextNode;
            nextNode = nextNode->next;
            delete temp;
            current->next = nextNode;
        } else {
            current = nextNode;
            nextNode = nextNode->next;
        }
    }

    return head;
}

int main() {
    Node* head = nullptr;
    int data;

    // Create the linked list with user input
    cout << "Enter elements for sorted linked list (enter -1 to stop):\n";
    while (true) {
        cin >> data;
        if (data == -1)
            break;

        head = insertAtEnd(head, data);
    }

    // Display the linked list before removing duplicates
    cout << "Linked List before removing duplicates: ";
    displayLinkedList(head);

    // Remove duplicates from the sorted linked list
    head = removeDuplicates(head);

    // Display the linked list after removing duplicates
    cout << "\nLinked List after removing duplicates: ";
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
This program demonstrates finding the intersection point of two linked lists. The user is prompted to enter elements for the first and second linked lists until they enter -1. Each element is inserted at the end of the respective linked list. After creating the linked lists, the elements are displayed.

The program finds the intersection point of the two linked lists using the approach of advancing the longer list pointer to make both lists equal in length. Then, it traverses both lists together to find the intersection point. If there is an intersection, the intersection node is displayed, and memory is freed by deleting the nodes.

*/
