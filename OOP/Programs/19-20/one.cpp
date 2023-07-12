/*
Program to find the largest element in an array using pointer arithmetic

Input:{5, 9, 3, 7, 1}
Output: Largest element: 9

*/

#include <iostream>

// Function to find the largest element in an array using pointer arithmetic
int findLargestElement(int* arr, int size) {
    int largest = *arr; // Initialize largest with the first element

    // Iterate through the array using pointer arithmetic
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > largest) {
            largest = *(arr + i);
        }
    }

    return largest;
}

int main() {
    int arr[] = {5, 9, 3, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargestElement(arr, size);
    std::cout << "Largest element: " << largest << std::endl;

    return 0;
}
/*
This program demonstrates how to find the largest element in an array using pointer arithmetic.
It iterates through the array using a pointer and compares each element with the current largest element.
*/
