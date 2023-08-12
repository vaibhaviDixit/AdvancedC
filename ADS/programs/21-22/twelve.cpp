/*
Create a linked list class called 'LinkedList' with nodes.
Implement constructors, copy constructor, copy assignment operator, and destructor.

Input:
    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    LinkedList list2 = list1; // Copy constructor called

    LinkedList list3;
    list3 = list1; // Copy assignment operator called

    list1.display();
    list2.display();
    list3.display();

Output:
1 -> 2 -> 3 -> nullptr
1 -> 2 -> 3 -> nullptr
1 -> 2 -> 3 -> nullptr

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList& other) {
        if (other.head == nullptr) {
            head = nullptr;
        } else {
            head = new Node(other.head->data);
            Node* curr = head;
            Node* otherCurr = other.head->next;

            while (otherCurr != nullptr) {
                curr->next = new Node(otherCurr->data);
                curr = curr->next;
                otherCurr = otherCurr->next;
            }
        }
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            // Copy Constructor
            LinkedList temp(other);
            // Swap the data of current object and temp
            swap(head, temp.head);
        }
        return *this;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    LinkedList list2 = list1; // Copy constructor called

    LinkedList list3;
    list3 = list1; // Copy assignment operator called

    list1.display();
    list2.display();
    list3.display();

    return 0;
}
/*
Node Class:
The Node class represents a node in a linked list. It has two public attributes: data, which stores the integer value of the node, and next, which is a pointer to the next node in the linked list. The constructor of the Node class takes an integer value as its parameter and initializes the data attribute with the provided value. The next attribute is initialized to nullptr by default, indicating that the node currently has no next node.

LinkedList Class:
The LinkedList class represents a singly linked list. It has a private attribute head, which is a pointer to the first node in the linked list. The constructor of the LinkedList class initializes the head attribute to nullptr, indicating an empty list.

The LinkedList class has the following member functions:

Copy Constructor: The copy constructor is used to create a new LinkedList object as a copy of an existing LinkedList object. It takes a reference to another LinkedList object (const LinkedList& other) as its parameter. The copy constructor performs a deep copy of the linked list, creating new nodes for each node in the original list and copying their values.

Copy Assignment Operator: The copy assignment operator (operator=) allows assignment of one LinkedList object to another. It takes a reference to another LinkedList object (const LinkedList& other) as its parameter. The copy assignment operator first checks whether the two objects are not the same (to avoid self-assignment). Then, it uses the copy constructor to create a temporary LinkedList object (LinkedList temp(other)) and swaps the head pointers of the current object and the temporary object using the swap() function. This ensures that the current object gets a deep copy of the linked list from the temp object, and the temp object gets destroyed with the old linked list.

append function: This function is used to append a new node with the given value to the end of the linked list. If the linked list is empty, the new node becomes the head. Otherwise, the function traverses the linked list to find the last node and appends the new node as its next node.

display function: This function is used to display the elements of the linked list in order. It traverses the linked list from the head, printing the data of each node followed by "->", and finally "nullptr" when the end of the linked list is reached.

Destructor: The destructor is responsible for releasing the dynamically allocated memory when the object is destroyed. It iterates through the linked list and deletes each node to prevent memory leaks.

In the main() function, we demonstrate the use of the LinkedList class by creating three linked lists (list1, list2, and list3). We append three elements (1, 2, and 3) to list1 using the append() function. Then, we create list2 as a copy of list1 using the copy constructor. Next, we create list3 without any initialization and then use the copy assignment operator to assign list1 to list3. Finally, we display the elements of all three linked lists using the display() function.

*/
