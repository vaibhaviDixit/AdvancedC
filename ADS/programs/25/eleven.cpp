/*
Implement a linked list and check if it is a palindrome.

Input: Enter elements for linked list (enter -1 to stop): 1 2 1 -1
Output:
Linked List: 1 2 1
Linked List is a palindrome.


*/

#include <iostream>
#include <stack>
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

// Function to check if the linked list is palindrome using stack
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the linked list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Push the first half of the linked list onto the stack
    stack<int> halfList;
    Node* current = head;
    while (current != slow) {
        halfList.push(current->data);
        current = current->next;
    }

    // If the length of the linked list is odd, skip the middle element
    if (fast != nullptr) {
        slow = slow->next;
    }

    // Check for palindrome by comparing second half with the elements popped from the stack
    while (slow != nullptr) {
        if (slow->data != halfList.top()) {
            return false;
        }
        halfList.pop();
        slow = slow->next;
    }

    return true;
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
    displayLinkedList(head);

    // Check if the linked list is palindrome
    if (isPalindrome(head)) {
        cout << "\nLinked List is a palindrome.";
    } else {
        cout << "\nLinked List is not a palindrome.";
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
This program demonstrates checking if a linked list is a palindrome. The user is prompted to enter elements for the linked list until they enter -1. Each element is inserted at the end of the linked list. After creating the linked list, the elements are displayed.

The program checks if the linked list is a palindrome using a stack. It first finds the middle of the linked list using the slow and fast pointers technique. Then, it pushes the first half of the linked list (up to the middle node) onto a stack. After that, it compares the second half of the linked list with the elements popped from the stack. If all elements match, the linked list is a palindrome. The result is displayed, and memory is freed by deleting the nodes.

*/


