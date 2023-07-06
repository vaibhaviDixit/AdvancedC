/*
Given a sorted array of integers, find the number of times a specific element appears using binary search.

Input: {1, 2, 2, 2, 3, 4, 4, 4, 5}
       target = 2
Output: Number of occurrences of element 2: 3
*/

#include <stdio.h>

// Binary search function to find the number of times an element appears in a sorted array
int countOccurrences(int arr[], int n, int target) {
    int count = 0;
    int first = -1, last = -1;
    int low = 0, high = n - 1;

    // Find the first occurrence of the target element
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            first = mid;
            high = mid - 1; // Search on the left side
        } else if (arr[mid] < target) {
            low = mid + 1; // Search on the right side
        } else {
            high = mid - 1; // Search on the left side
        }
    }

    // Find the last occurrence of the target element
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            last = mid;
            low = mid + 1; // Search on the right side
        } else if (arr[mid] < target) {
            low = mid + 1; // Search on the right side
        } else {
            high = mid - 1; // Search on the left side
        }
    }

    if (first != -1 && last != -1) {
        count = last - first + 1;
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int occurrences = countOccurrences(arr, n, target);

    printf("Number of occurrences of element %d: %d\n", target, occurrences);

    return 0;
}

/*
This program utilizes binary search to find the number of times a specific element appears in a sorted array.
The countOccurrences function takes the sorted array, its size, and the target element as inputs. It performs binary search twice to
find the first and last occurrences of the target element. It updates the search range based on the comparison results.
The function returns the count of occurrences of the target element. The main function initializes the array, its size, and the target element.
It calls the countOccurrences function and prints the number of occurrences of the target element.
*/
