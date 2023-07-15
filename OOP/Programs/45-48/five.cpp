/*
Create a class called "DynamicArray" that uses dynamic memory allocation in its constructor to store
an array of integers.
Implement a function to display the array elements.
*/

#include <iostream>

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Constructor with dynamic memory allocation
    DynamicArray(int arrSize) {
        size = arrSize;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
    }

    void displayArray() {
        std::cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Destructor to free the dynamically allocated memory
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray arrObj(5);
    arrObj.displayArray();
    return 0;
}


/*
This program defines a class DynamicArray with a constructor that uses dynamic memory allocation to store
an array of integers with the given size. The displayArray() method prints the elements of the array.
The destructor is also implemented to free the dynamically allocated memory when the object goes out of scope.
*/
