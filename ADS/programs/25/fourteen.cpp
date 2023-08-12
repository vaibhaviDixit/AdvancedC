/*
 Implement a circular linked list and split it into two halves.

 Input:
 Enter elements for circular linked list (enter -1 to stop): 5 8 9 12 15 19 4 -1
 Circular Linked List: 5 8 9 12 15 19 4

 Output:
 First Half of Circular Linked List: 5 15 19 4
 Second Half of Circular Linked List: 15 19 4 5

*/

#include <iostream>
using namespace std;

// Node structure for circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert an element at the end of the circular linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (head == nullptr) {
        newNode->next = newNode; // Only one node, points to itself
        return newNode;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;
    return head;
}

// Function to display the circular linked list
void displayCircularLinkedList(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}

// Function to split a circular linked list into two halves
void splitCircularLinkedList(Node* head, Node** head1, Node** head2) {
    if (head == nullptr) {
        *head1 = *head2 = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    // Move fast pointer twice as fast as slow pointer
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If there are even number of nodes, move fast one more step
    if (fast->next == head) {
        fast = fast->next;
    }

    // Split the circular linked list into two halves
    *head1 = head;
    *head2 = slow->next;

    slow->next = head;
    fast->next = *head2;
}

int main() {
    Node* head = nullptr;
    int data;

    // Create the circular linked list with user input
    cout << "Enter elements for circular linked list (enter -1 to stop):\n";
    while (true) {
        cin >> data;
        if (data == -1)
            break;

        head = insertAtEnd(head, data);
    }

    // Display the circular linked list
    cout << "Circular Linked List: ";
    displayCircularLinkedList(head);

    // Split the circular linked list into two halves
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    splitCircularLinkedList(head, &head1, &head2);

    // Display the first half of the circular linked list
    cout << "\nFirst Half of Circular Linked List: ";
    displayCircularLinkedList(head1);

    // Display the second half of the circular linked list
    cout << "\nSecond Half of Circular Linked List: ";
    displayCircularLinkedList(head2);

    // Free memory by deleting nodes (note: this is not necessary for circular linked list implementation)

    return 0;
}

/*
This program demonstrates splitting a circular linked list into two halves. The user is prompted to enter elements for the circular linked list until they enter -1. Each element is inserted at the end of the circular linked list. After creating the circular linked list, the elements are displayed.

The program then splits the circular linked list into two halves using the slow and fast pointers technique. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the beginning of the circular linked list again, the slow pointer will be at the midpoint. The circular linked list is then split into two halves by updating the pointers accordingly.

The first and second halves of the circular linked list are displayed, and memory is freed (note: this is not necessary for a circular linked list implementation).

*/
