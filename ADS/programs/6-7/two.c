/*
Implement the Selection Sort algorithm to sort an array of integers in ascending order.

Input: Unsorted array: 64 34 25 12 22 11 90
Output: Sorted array: 11 12 22 25 34 64 90

*/

#include <stdio.h>

// Selection Sort Algorithm
// This function takes an array 'arr' and its size 'n' as input
// and sorts the elements of the array in ascending order.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the current index as the index of the minimum element
        int min_idx = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the minimum element with the first element of the unsorted part
        // This effectively moves the smallest element to its correct position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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

    // Call the Selection Sort function to sort the array
    selectionSort(arr, n);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Selection Sort algorithm, a simple sorting technique that repeatedly selects the minimum (or maximum) element from the unsorted part of the array and moves it to the beginning (or end) of the sorted part of the array.
The selectionSort function takes an array arr and its size n as input and modifies the array in-place to sort it in ascending order.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the selectionSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.

*/

