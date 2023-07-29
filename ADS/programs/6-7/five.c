/*
 Implement the Counting Sort algorithm to sort an array of integers in ascending order.

 Input: Unsorted array: 64 34 25 12 22 11 90
 Output: Sorted array: 11 12 22 25 34 64 90

*/


#include <stdio.h>

// Find the maximum element in the array
// This function takes an array 'arr' and its size 'n' as input.
// It finds and returns the maximum element in the array.
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It sorts the array in ascending order using the Counting Sort algorithm.
void countingSort(int arr[], int n) {
    int max = findMax(arr, n); // Find the maximum element in the array
    int count[max + 1]; // Create a count array to store the count of each element
    int output[n]; // Create an output array to store the sorted elements

    // Initialize count array with zeros
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Store the count of each element in count array
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Modify the count array to store the actual position of each element in output array
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr, so that arr now contains the sorted integers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
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

    // Call the Counting Sort function to sort the array
    countingSort(arr, n);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Counting Sort algorithm, which is an efficient sorting technique used for integers within a specified range.
The findMax function takes an array arr and its size n as input and finds the maximum element in the array. This information is needed to determine the range of elements in the counting array.
The countingSort function takes an array arr and its size n as input. It sorts the array in ascending order using the Counting Sort algorithm.
The algorithm first finds the maximum element in the array and creates a counting array (count) of size max + 1 to store the count of each element in the input array.
It then calculates the running sum in the count array to determine the correct position of each element in the output array (output).
The sorted elements are placed in the output array, and then the sorted result is copied back to the original array arr.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the countingSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.

*/


