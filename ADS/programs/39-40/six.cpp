/*
Implement a C++ program to delete an element from a Min-Heap and maintain the Min-Heap property.

Input: min-heap{ 1,5,3,8,9,7,6 }
Output:
Min-Heap before deletion: 1 5 3 8 9 7 6
Min-Heap after deleting element at index 2: 1 5 6 8 9 7

*/

#include <iostream>
using namespace std;

// Function to perform heapify on a Min-Heap
void heapify(int arr[], int n, int i) {
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // Left child
    int r = 2 * i + 2; // Right child

    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than the smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Function to delete the element at index 'i' from Min-Heap
void deleteElement(int arr[], int& n, int i) {
    if (i >= n)
        return;

    // Replace the element to be deleted with the last element
    arr[i] = arr[n - 1];
    n = n - 1;

    // Heapify the tree from the updated element position
    int parent = (i - 1) / 2;
    if (i > 0 && arr[i] < arr[parent]) {
        while (i > 0 && arr[i] < arr[parent]) {
            swap(arr[i], arr[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    } else {
        heapify(arr, n, i);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = { 1,5,3,8,9,7,6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Min-Heap before deletion: ";
    printArray(arr, n);

    // Deleting the element at index 2 (value 3)
    deleteElement(arr, n, 2);

    cout << "Min-Heap after deleting element at index 2: ";
    printArray(arr, n);

    return 0;
}

/*
In this program, we implement the process of deleting an element from a Min-Heap while maintaining the Min-Heap property.
The Min-Heap is a binary tree where each node has a value less than or equal to its children. When an element is deleted from the heap,
we replace it with the last element and then perform the "heapify" operation to move the new element to its proper position while
preserving the Min-Heap property.

*/


