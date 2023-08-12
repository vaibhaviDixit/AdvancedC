/*
Create a class called 'DynamicArray' with an integer array attribute.
Implement constructors, destructor, and resize function to manage dynamic memory allocation.

Input:
    DynamicArray arr1(5);
    arr1.display();

    arr1.resize(3);
    arr1.display();

    DynamicArray arr2 = arr1;
    arr2.display();

    arr2.resize(2);
    arr2.display();

Output:

12887352 12845248 0 0 83886085
12887352 12845248 0
12887352 12845248 0
0 0
(dummy values at memory locations)

*/

#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray(int s) {
        size = s;
        arr = new int[size];
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void resize(int newSize) {
        delete[] arr;
        size = newSize;
        arr = new int[size];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray arr1(5);
    arr1.display();

    arr1.resize(3);
    arr1.display();

    DynamicArray arr2 = arr1; // Copy constructor called
    arr2.display();

    arr2.resize(2);
    arr2.display();

    return 0;
}

/*
The DynamicArray class provides the following member functions:

Constructor: The constructor takes an integer s as its parameter and initializes the size attribute. It also dynamically allocates memory for the array using new int[size].

Copy Constructor: The copy constructor is used to create a new DynamicArray object as a copy of an existing DynamicArray object. It takes a reference to another DynamicArray object (const DynamicArray& other) as its parameter. Inside the copy constructor, we allocate new memory for the array and copy the elements from the arr array of the other object to initialize the arr array of the newly created object.

Copy Assignment Operator: The copy assignment operator (operator=) allows assignment of one DynamicArray object to another. It takes a reference to another DynamicArray object (const DynamicArray& other) as its parameter. The copy assignment operator first checks whether the two objects are not the same (to avoid self-assignment) and then deallocates the current memory using delete[]. Next, it updates the size attribute with the size of the other object and allocates new memory for the arr array. Finally, it copies the elements from the arr array of the other object to the arr array of the current object.

resize function: This function takes an integer newSize as its parameter and resizes the dynamic array accordingly. It first deallocates the existing memory using delete[], then it updates the size attribute with the new size, and finally, it allocates a new memory block using new int[size].

Destructor: The destructor is responsible for releasing the dynamically allocated memory when the object is destroyed. It uses delete[] to deallocate the memory assigned to the array.

In the main() function, we demonstrate the use of the DynamicArray class by creating two DynamicArray objects (arr1 and arr2). We resize arr1 using the resize() function to change its size to 3, and then we display the elements of both arrays using the display() function. Next, we create arr2 as a copy of arr1 using the copy constructor. We resize arr2 to size 2 and display its elements.

*/


