/*
Given a circular sorted array of integers, find a specific element using binary search.

Input:  {7, 8, 9, 10, 2, 3, 4, 5}
Output: Element 3 found at index 5

*/

#include <stdio.h>

// Binary search function to find an element in a circular sorted array
int binarySearchCircular(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        }

        if (arr[mid] <= arr[high]) {
            // Right half is sorted
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1; // Search on the right side
            } else {
                high = mid - 1; // Search on the left side
            }
        } else {
            // Left half is sorted
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1; // Search on the left side
            } else {
                low = mid + 1; // Search on the right side
            }
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {7, 8, 9, 10, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int index = binarySearchCircular(arr, n, target);

    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}

/*
This program uses binary search to find a specific element in a circular sorted array.
A circular sorted array is an array that is sorted in a circular manner. The binarySearchCircular function takes the circular sorted array,
its size, and the target element as inputs. It performs binary search to find the target element. The function compares the middle element
with the last element to determine if the right or left half is sorted. Depending on the sorted half, it adjusts the search range accordingly.
The function returns the index of the target element if found, or -1 if not found. The main function initializes the array, its size, and the
target element.
It calls the binarySearchCircular function and prints whether the element is found or not along with its index.
*/
