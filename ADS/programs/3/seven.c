/*
Given a bitonic array of integers, find a peak element using binary search.

Input: {1, 3, 5, 9, 7, 2}
Output: Peak element: 9

*/

#include <stdio.h>

// Binary search function to find a peak element in a bitonic array
int binarySearchBitonicPeak(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid > 0 && mid < n - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; // Peak element found
            } else if (arr[mid - 1] > arr[mid]) {
                high = mid - 1; // Search on the left side
            } else {
                low = mid + 1; // Search on the right side
            }
        } else if (mid == 0) {
            if (arr[mid] > arr[mid + 1]) {
                return mid; // Peak element found
            } else {
                return mid + 1; // Peak is the next element
            }
        } else if (mid == n - 1) {
            if (arr[mid] > arr[mid - 1]) {
                return mid; // Peak element found
            } else {
                return mid - 1; // Peak is the previous element
            }
        }
    }

    return -1; // Peak element not found
}

int main() {
    int arr[] = {1, 3, 5, 9, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = binarySearchBitonicPeak(arr, n);

    if (peakIndex != -1) {
        printf("Peak element: %d\n", arr[peakIndex]);
    } else {
        printf("Peak element not found\n");
    }

    return 0;
}

/*
This program uses binary search to find a peak element in a bitonic array.

A bitonic array is an array that increases monotonically and then decreases monotonically.

The binarySearchBitonicPeak function takes the bitonic array and its size as inputs.
It performs binary search to find a peak element. If the middle element is greater than its adjacent elements, a peak is found.
If the left neighbor is greater, the peak is likely on the left side, so the search range is updated accordingly. Otherwise,
the peak is likely on the right side, and the search range is updated accordingly. Special cases for the first and last elements are also handled.
The function returns the index of a peak element. The main function initializes the array and its size, calls the binarySearchBitonicPeak function,
and prints the peak element if found.
*/
