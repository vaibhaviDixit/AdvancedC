/*
Implement the Quickselect algorithm to find the kth smallest element in an array.

Input: {64, 34, 25, 12, 22, 11, 90}
Output: The 4th smallest element is: 25


*/

#include <stdio.h>

// Partition Function (same as used in Quick Sort)
// This function takes an array 'arr' and its lower and higher indices 'low' and 'high'.
// It selects the last element (arr[high]) as the pivot and arranges the elements such that all elements
// smaller than the pivot are on the left side, and all elements greater than the pivot are on the right side.
// It returns the index of the pivot element after partitioning.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Select the pivot element as the last element (arr[high])
    int i = low - 1; // Initialize the index of the smaller element

    // Iterate through the array and move elements smaller than the pivot to the left side
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap elements to move smaller elements to the left side
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element to its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the index of the pivot element after partitioning
}

// Quickselect Algorithm
// This function takes an array 'arr', its lower and higher indices 'low' and 'high', and the value 'k'.
// It finds the kth smallest element in the array using the Quickselect algorithm.
int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k - 1)
            return arr[pi]; // If the pivot element is the kth smallest element, return it

        if (pi > k - 1)
            return quickselect(arr, low, pi - 1, k); // If the pivot element's index is greater than k, search in the left subarray
        else
            return quickselect(arr, pi + 1, high, k); // If the pivot element's index is smaller than k, search in the right subarray
    }

    // Return -1 if k is out of bounds
    return -1;
}

int main() {
    // Sample unsorted array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 4; // Find the 4th smallest element

    // Call the Quickselect function to find the kth smallest element
    int kthSmallest = quickselect(arr, 0, n - 1, k);

    if (kthSmallest != -1)
        printf("The %dth smallest element is: %d\n", k, kthSmallest);
    else
        printf("Invalid value of k.");

    return 0;
}

/*
The program demonstrates the Quickselect algorithm, which is a variation of the Quick Sort algorithm used to find the kth smallest (or largest) element in an unsorted array efficiently.
The partition function is responsible for selecting a pivot element and arranging the array elements such that all elements smaller than the pivot are on the left side, and all elements greater than the pivot are on the right side. It returns the index of the pivot element after partitioning.
The quickselect function takes an array arr, its lower and higher indices low and high, and the value k as input. It recursively applies the partitioning process to find the kth smallest element in the array.
The algorithm uses the same logic as Quick Sort but searches for the desired element in only one of the subarrays depending on the pivot's position. If the pivot element's index is equal to k - 1, the kth smallest element is found and returned. Otherwise, the search is continued in the left or right subarray, depending on the pivot's position.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then calls the quickselect function to find the kth smallest element and prints the result.
The printf function is used to display the kth smallest element on the console. If the value of k is out of bounds, it will print an error message.

*/


