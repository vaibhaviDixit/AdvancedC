/*
Implement two sorted linked lists and merge them into a single sorted linked list.

Input:

Enter elements for the first linked list (enter -1 to stop):
3 7 9 -1
Enter elements for the second linked list (enter -1 to stop):
1 10 8 -1

Output:

First Linked List: 3 7 9
Second Linked List: 1 10 8
Merged Linked List: 1 3 7 9 10 8


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

// Function to merge two sorted linked lists into a single sorted linked list
Node* mergeSortedLinkedLists(Node* list1, Node* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Node* mergedList = nullptr;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeSortedLinkedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeSortedLinkedLists(list1, list2->next);
    }

    return mergedList;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int data;

    // Create the first linked list with user input
    cout << "Enter elements for the first linked list (enter -1 to stop):\n";
    while (true) {
        cin >> data;
        if (data == -1)
            break;

        head1 = insertAtEnd(head1, data);
    }

    // Create the second linked list with user input
    cout << "Enter elements for the second linked list (enter -1 to stop):\n";
    while (true) {
        cin >> data;
        if (data == -1)
            break;

        head2 = insertAtEnd(head2, data);
    }

    // Display the first linked list
    cout << "First Linked List: ";
    displayLinkedList(head1);

    // Display the second linked list
    cout << "\nSecond Linked List: ";
    displayLinkedList(head2);

    // Merge the two sorted linked lists
    Node* mergedList = mergeSortedLinkedLists(head1, head2);

    // Display the merged linked list
    cout << "\nMerged Linked List: ";
    displayLinkedList(mergedList);

    // Free memory by deleting nodes
    while (head1 != nullptr) {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    while (mergedList != nullptr) {
        Node* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}

/*
This program demonstrates merging two sorted linked lists into a single sorted linked list. The user is prompted to enter elements for the first and second linked lists until they enter -1. Each element is inserted at the end of the respective linked list. After creating the linked lists, the elements are displayed.

The two sorted linked lists are then merged into a single sorted linked list using a recursive approach. The mergeSortedLinkedLists function merges the two lists by comparing the data values of the nodes. The resulting merged list is then displayed, and memory is freed by deleting the nodes.

*/


