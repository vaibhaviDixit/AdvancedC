/*
 Implement the Merge Sort algorithm to sort an array of integers in ascending order.

 Input: Unsorted array: 64 34 25 12 22 11 90
 Output: Sorted array: 11 12 22 25 34 64 90

*/


#include <stdio.h>

// Merge Function
// This function takes an array 'arr' and its two subarrays defined by indices 'l', 'm', and 'r'
// It merges the two subarrays in a sorted manner to produce the sorted array.
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // Size of the left subarray
    int n2 = r - m;     // Size of the right subarray

    int L[n1], R[n2];   // Temporary arrays to store the left and right subarrays

    // Copy data to the temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into the original array in sorted order
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[] and R[] if there are any
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort Algorithm
// This function takes an array 'arr' and its starting index 'l' and ending index 'r'
// It divides the array into two halves, recursively sorts them, and then merges the sorted halves.
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate the middle index

        // Recursively sort the left and right halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
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

    // Call the Merge Sort function to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
The program demonstrates the Merge Sort algorithm, which is a popular divide-and-conquer sorting technique.
The merge function is responsible for merging two subarrays, defined by indices l, m, and r, into a single sorted array.
The mergeSort function takes an array arr and its starting and ending indices l and r as input. It divides the array into smaller subarrays, recursively applies mergeSort to each subarray, and then merges them back together using the merge function.
The main function initializes an array with some sample unsorted values and calculates the size of the array.
It then prints the unsorted array, calls the mergeSort function to sort the array, and finally prints the sorted array.
The printf function is used to display the elements of the array on the console.

*/



