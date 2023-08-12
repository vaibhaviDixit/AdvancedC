/*
Given an array of integers, find the number of inversions present in the array using the Merge Sort algorithm.
An inversion in an array occurs when two elements at indices i and j are out of order, i.e., arr[i] > arr[j] and i < j.
Implement the Merge Sort algorithm with inversion count and return the total number of inversions in the array.

Input: Given array: 1 20 6 4 5
Output: Number of inversions: 5

*/

#include <iostream>
using namespace std;

// Merge Function (same as used in Merge Sort)
// This function takes an array 'arr', a temporary array 'temp', and the indices 'left', 'mid', and 'right'.
// It merges two sorted subarrays arr[left...mid-1] and arr[mid...right] into a single sorted subarray.
// It returns the count of inversions that occurred during the merging process.
long long int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long int inv_count = 0;

    i = left;   // Index for left subarray
    j = mid;    // Index for right subarray
    k = left;   // Index for merged subarray

    // Merge the subarrays while counting inversions
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            // If an element from the right subarray is smaller, it forms an inversion with the remaining elements in the left subarray
            inv_count += (mid - i);
        }
    }

    // Copy the remaining elements of left subarray (if any)
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray (if any)
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the merged elements back to the original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge Sort Algorithm (with inversion count)
// This function takes an array 'arr', a temporary array 'temp', and the indices 'left' and 'right'.
// It sorts the array using the Merge Sort algorithm and returns the count of inversions during the sorting process.
long long int mergeSort(int arr[], int temp[], int left, int right) {
    long long int inv_count = 0;
    int mid;

    if (right > left) {
        mid = (left + right) / 2;

        // Divide and conquer
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Combine the results from both halves
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

int main() {
    // Sample array
    int arr[] = {8,4,2,1};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Temporary array to store merged subarrays during sorting
    int temp[n];

    // Print the given array
    cout << "Given array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Call the Merge Sort function with inversion count to sort the array and count inversions
    long long int inversions = mergeSort(arr, temp, 0, n - 1);

    // Print the number of inversions in the array
    cout << "\nNumber of inversions: " << inversions;

    return 0;
}

/*

The program demonstrates the Merge Sort algorithm with inversion count. It sorts an array and counts the number of inversions that occur during the sorting process.
An inversion in an array occurs when two elements at indices i and j are out of order, i.e., arr[i] > arr[j] and i < j.
The merge function is used to merge two sorted subarrays (arr[left...mid-1] and arr[mid...right]) into a single sorted subarray. It also counts the inversions that occur during the merging process.
The mergeSort function is the Merge Sort algorithm with inversion count. It recursively divides the array into smaller subarrays, sorts them, and then merges them back together while counting the inversions that occur.
The main function initializes an array with some sample values and calculates the size of the array.
It then calls the mergeSort function to sort the array and count the inversions.
The given array is printed before sorting, and the number of inversions is printed after sorting.
The printf function is used to display the elements of the array and the number of inversions on the console.

*/


