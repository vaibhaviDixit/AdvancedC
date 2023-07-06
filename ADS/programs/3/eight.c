/*
Given a rotated sorted array of integers, find the smallest element using binary search.

Input: {4, 5, 6, 7, 0, 1, 2}
Output:Smallest element: 0

*/

#include <stdio.h>

// Binary search function to find the smallest element in a rotated sorted array
int findSmallestElement(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1; // Search on the right side
        } else {
            high = mid; // Search on the left side
        }
    }

    return arr[low]; // Smallest element
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallestElement = findSmallestElement(arr, n);

    printf("Smallest element: %d\n", smallestElement);

    return 0;
}

/*
This program demonstrates binary search to find the smallest element in a rotated sorted array.
A rotated sorted array is an array that has been rotated at an unknown pivot point.
The findSmallestElement function takes the rotated sorted array and its size as inputs.
It performs binary search by comparing the middle element with the last element.
If the middle element is greater than the last element, the smallest element is likely on the right side, so the search range is updated accordingly.
Otherwise, the smallest element is likely on the left side, and the search range is updated accordingly. The function returns the smallest element.
The main function initializes the array and its size, calls the findSmallestElement function, and prints the smallest element.
*/
