/*
Given a sorted array of integers, find the index of the last occurrence of a specific element using binary search.

Input: {1, 2, 2, 3, 4, 4, 4, 5}
       target = 4
Output: Last occurrence of element 4 found at index 6

*/
#include <stdio.h>

// Binary search function to find the index of the last occurrence of the target element
int binarySearchLastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            low = mid + 1; // Search for the last occurrence to the right
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result; // -1 if element not found
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int index = binarySearchLastOccurrence(arr, n, target);

    if (index != -1) {
        printf("Last occurrence of element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}
/*
This program modifies the binary search algorithm to find the index of the last occurrence of a specific element in a sorted array.
The binarySearchLastOccurrence function takes the array, its size, and the target element as inputs.
It performs binary search to find the index of the last occurrence of the target element in the array. It maintains a result variable to
store the index of the last occurrence. The main function initializes the array, its size, and the target element.
It calls the binarySearchLastOccurrence function and prints whether the element is found or not along with its index.
*/
