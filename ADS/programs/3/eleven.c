/*
Given a sorted array of distinct integers starting from 0, find the smallest missing element using binary search.

Input:  {0, 1, 2, 3, 5, 6, 7}
Output: Smallest missing element: 4

*/

#include <stdio.h>

// Binary search function to find the smallest missing element in a sorted array
int findSmallestMissingElement(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid) {
            low = mid + 1; // Search on the right side
        } else {
            high = mid - 1; // Search on the left side
        }
    }

    return low; // Smallest missing element
}

int main() {
    int arr[] = {0, 1, 2, 3, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallestMissingElement = findSmallestMissingElement(arr, n);

    printf("Smallest missing element: %d\n", smallestMissingElement);

    return 0;
}

/*
This program demonstrates binary search to find the smallest missing element in a sorted array of distinct integers starting from 0.
The findSmallestMissingElement function takes the sorted array and its size as inputs.
It performs binary search to find the smallest missing element by comparing the elements with their indices.
If an element is equal to its index, the missing element is likely on the right side, so the search range is updated accordingly.
Otherwise, the missing element is likely on the left side, and the search range is updated accordingly. The function returns the smallest missing element.
The main function initializes the array and its size, calls the findSmallestMissingElement function,
and prints the smallest missing element.
*/
