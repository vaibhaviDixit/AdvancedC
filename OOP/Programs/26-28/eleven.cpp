/*
 Write a program to merge two sorted arrays using dynamic memory allocation and pointers.

Input:
Enter the size of the first array: 3
Enter the size of the second array: 2
Enter the elements of the first array (sorted in ascending order): 2 4 6
Enter the elements of the second array (sorted in ascending order): 1 3

Output:
Merged Array: 1 2 3 4 6
*/


#include <iostream>
using namespace std;

int* mergeArrays(int* arr1, int* arr2, int size1, int size2) {
    int* merged = new int[size1 + size2];

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (*(arr1 + i) <= *(arr2 + j)) {
            *(merged + k) = *(arr1 + i);
            i++;
        } else {
            *(merged + k) = *(arr2 + j);
            j++;
        }
        k++;
    }

    while (i < size1) {
        *(merged + k) = *(arr1 + i);
        i++;
        k++;
    }

    while (j < size2) {
        *(merged + k) = *(arr2 + j);
        j++;
        k++;
    }

    return merged;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    cout << "Enter the size of the second array: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    cout << "Enter the elements of the first array (sorted in ascending order): ";
    for (int i = 0; i < size1; i++) {
        cin >> *(arr1 + i);
    }

    cout << "Enter the elements of the second array (sorted in ascending order): ";
    for (int i = 0; i < size2; i++) {
        cin >> *(arr2 + i);
    }

    int* mergedArray = mergeArrays(arr1, arr2, size1, size2);

    cout << "Merged Array: ";
    printArray(mergedArray, size1 + size2);

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;

    return 0;
}

/*
This program merges two sorted arrays using dynamic memory allocation and pointers.
It defines a function mergeArrays that takes pointers to two integer arrays, the sizes of the arrays, and merges them into a new
dynamically allocated array. The main function asks the user for the sizes and elements of the two arrays, performs the merging operation,
and prints the merged array.
Finally, it deallocates the memory.
*/
