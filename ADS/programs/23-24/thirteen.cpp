/*
Create a base class Array with a virtual function display(). Implement derived classes IntArray and DoubleArray that override the display()
function to display their respective array elements.

Input:

    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    Array* array1 = new IntArray(intArray, 5);
    Array* array2 = new DoubleArray(doubleArray, 5);

    array1->display();
    array2->display();

Output:
Displaying an integer array: 1 2 3 4 5
Displaying a double array: 1.1 2.2 3.3 4.4 5.5

*/


#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

// Base class Array
class Array {
public:
    // Virtual function 'display()' to display a generic array (has a default implementation).
    // The 'virtual' keyword allows dynamic binding to the appropriate derived class implementation.
    virtual void display() {
        cout << "Displaying a generic array." << endl;
    }
};

// Derived class IntArray from the base class Array to represent integer arrays.
class IntArray : public Array {
private:
    int* data; // Private member variable to store the integer array elements.
    int size; // Private member variable to store the size of the integer array.

public:
    // Constructor to initialize the IntArray object with the provided integer array and size.
    IntArray(int* arr, int s) : data(arr), size(s) {}

    // Override the 'display()' method to display elements of the integer array.
    // This method will be invoked dynamically through dynamic binding based on the object type.
    void display() override {
        cout << "Displaying an integer array: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Derived class DoubleArray from the base class Array to represent double arrays.
class DoubleArray : public Array {
private:
    double* data; // Private member variable to store the double array elements.
    int size; // Private member variable to store the size of the double array.

public:
    // Constructor to initialize the DoubleArray object with the provided double array and size.
    DoubleArray(double* arr, int s) : data(arr), size(s) {}

    // Override the 'display()' method to display elements of the double array.
    // This method will be invoked dynamically through dynamic binding based on the object type.
    void display() override {
        cout << "Displaying a double array: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int intArray[] = {1, 2, 3, 4, 5}; // Create an integer array.
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5}; // Create a double array.

    Array* array1 = new IntArray(intArray, 5); // Create an Array pointer pointing to a dynamically allocated IntArray object.
    Array* array2 = new DoubleArray(doubleArray, 5); // Create an Array pointer pointing to a dynamically allocated DoubleArray object.

    array1->display(); // Dynamic binding to IntArray's display() - Polymorphism.
    array2->display(); // Dynamic binding to DoubleArray's display() - Polymorphism.

    delete array1; // Deallocate the memory for the IntArray object.
    delete array2; // Deallocate the memory for the DoubleArray object.

    return 0; // Exit the program with a success status.
}

/*

This C++ program demonstrates the concept of polymorphism using virtual functions and dynamic binding.
The program defines a base class 'Array' with a virtual function 'display()'. The 'display()' method is intended to be overridden in derived classes.
Two derived classes, 'IntArray' and 'DoubleArray', inherit from the 'Array' base class and override the 'display()' method to display their respective array elements.

*/


