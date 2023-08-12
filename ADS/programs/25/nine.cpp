/*
Implement a linked list and implement function to create and detect  a loop.

Input:
Enter elements for linked list (enter -1 to stop):
4 5 7 9 -1
Linked List: 4 5 7 9
Before creation of loop
Linked List does not contain a loop.
Enter the position of the node where loop starts (0-indexed, enter -1 for no loop): 2
After creation of loop

Output: Linked List contains a loop.

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

// Function to create a loop in the linked list (for testing)
void createLoop(Node* head, int pos) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* loopStart = nullptr;

    int i = 0;
    while (current->next != nullptr) {
        if (i == pos) {
            loopStart = current;
        }

        current = current->next;
        i++;
    }

    current->next = loopStart;
}

// Function to detect loop in the linked list using Floyd's cycle detection algorithm
bool detectLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
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

    cout<<"\nBefore creation of loop \n";
    // Detect loop in the linked list
    if (detectLoop(head)) {
        cout << "Linked List contains a loop.\n ";
    } else {
        cout << "Linked List does not contain a loop.\n";
    }

    // Create a loop in the linked list (for testing)
    int pos;
    cout << "\nEnter the position of the node where loop starts (0-indexed, enter -1 for no loop): ";
    cin >> pos;
    createLoop(head, pos);

    cout<<"After creation of loop \n";
    // Detect loop in the linked list
    if (detectLoop(head)) {
        cout << "Linked List contains a loop.";
    } else {
        cout << "Linked List does not contain a loop.";
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
This program demonstrates detecting a loop in a linked list using Floyd's cycle detection algorithm. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The program allows the user to create a loop in the linked list for testing purposes. The loop is created by connecting the last node to the node at the specified position (0-indexed) in the linked list.

The loop in the linked list is then detected using Floyd's cycle detection algorithm. Two pointers, slow and fast, traverse the linked list. If there is a loop, the fast pointer will eventually catch up to the slow pointer. If there is no loop, the fast pointer will reach the end of the list. The program then displays whether the linked list contains a loop or not, and memory is freed by deleting the nodes.

*/
