/*
Given an array of integers, find a peak element using binary search.

Input: {1, 3, 5, 7, 4, 2}
Output: Peak element: 7
*/

#include <stdio.h>

// Binary search function to find a peak element
int binarySearchPeak(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low; // Peak element index
}

int main() {
    int arr[] = {1, 3, 5, 7, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = binarySearchPeak(arr, n);

    printf("Peak element: %d\n", arr[peakIndex]);

    return 0;
}

/*
This program utilizes binary search to find a peak element in an array of integers.

A peak element is an element that is greater than its neighbors.

The binarySearchPeak function takes the array and its size as inputs and performs binary search to find a peak element.
It compares the middle element with its adjacent elements to determine if it is a peak. If the middle element is greater than its right neighbor,
the peak is likely on the left side, so the search range is updated accordingly. Otherwise, the peak is likely on the right side, and the search range
is updated accordingly. The function returns the index of a peak element.
The main function initializes the array and its size, calls the binarySearchPeak function, and prints the peak element.

*/
