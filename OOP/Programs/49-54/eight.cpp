/*
Create a class representing an array and overload the '[]' operator to access array elements.
*/

#include <iostream>
#include <stdlib.h>  // standard library function

using namespace std;

const int SIZE = 5;

class MyArray {
private:
    int arr[SIZE];

public:
    MyArray() {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = i + 1;
        }
    }

    // Overloading the array index '[]' operator
    int& operator[](int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Index out of range." << endl;
            exit(1);
        }
        return arr[index];
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyArray arr;

    cout << "Original Array: ";
    arr.display();

    arr[2] = 10; // Change element at index 2
    cout << "Modified Array: ";
    arr.display();

    return 0;
}

/*
This program implements a class MyArray to represent an array.
The '[]' operator is overloaded to access array elements.
The display() function is used to print the array before and after modification.

*/


