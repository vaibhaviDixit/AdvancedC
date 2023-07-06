/*
Given a sorted array of integers, find a specific element using binary search.

Input: {2, 4, 6, 8, 10, 12}
       target = 8
Output: Element 8 found at index 3

*/
#include <stdio.h>

// Binary search function to find the index of the target element
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1; //update left pointer
        } else {
            high = mid - 1; //update right pointer
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int index = binarySearch(arr, n, target);

    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}

/*
This program demonstrates binary search by finding a specific element in a sorted array.
The binarySearch function takes the array, its size, and the target element as inputs.
It uses the binary search algorithm to find the index of the target element in the array.
The main function initializes the array, its size, and the target element.
It calls the binarySearch function and prints whether the element is found or not along with its index.
*/
