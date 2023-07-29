/*
 Implement the Bubble Sort algorithm to sort an array of integers in ascending order.

 Input: Unsorted array: 64 34 25 12 22 11 90
 Output: Sorted array: 11 12 22 25 34 64 90

*/

#include <stdio.h>

// Bubble Sort Algorithm
// This function takes an array 'arr' and its size 'n' as input
// and sorts the elements of the array in ascending order.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements, swap them if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Sample unsorted array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the Bubble Sort function to sort the array
    bubbleSort(arr, n);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Bubble Sort algorithm, a simple sorting technique that repeatedly steps through the list to be sorted, compares adjacent elements, and swaps them if they are in the wrong order.
The bubbleSort function takes an array arr and its size n as input and modifies the array in-place to sort it in ascending order.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the bubbleSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.

*/



