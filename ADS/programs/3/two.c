/*
 Given a sorted array of integers, find the index of the first occurrence of a specific element using binary search.

 Input:  {1, 2, 2, 3, 4, 4, 4, 5}
         target = 4
 Output: First occurrence of element 4 found at index 4
*/

#include <stdio.h>

// Binary search function to find the index of the first occurrence of the target element
int binarySearchFirstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; // Search for the first occurrence to the left
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

    int index = binarySearchFirstOccurrence(arr, n, target);

    if (index != -1) {
        printf("First occurrence of element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}

/*
This program extends the binary search algorithm to find the index of the first occurrence of a specific element in a sorted array.
The binarySearchFirstOccurrence function takes the array, its size, and the target element as inputs. Ituses binary search to find the
index of the first occurrence of the target element in the array. It maintains a result variable to store the index of the first occurrence.
The main function initializes the array, its size, and the target element.
It calls the binarySearchFirstOccurrence function and prints whether the element is found or not along with its index.
*/
