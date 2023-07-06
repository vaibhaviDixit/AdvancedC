/*
 Given a rotated sorted array of integers, find the number of rotations using binary search.

 Input: {5, 6, 7, 8, 9, 1, 2, 3, 4}
 Output: Number of rotations: 5
*/

#include <stdio.h>

// Binary search function to find the number of rotations in a rotated sorted array
int countRotations(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        if (arr[low] <= arr[high]) {
            return low; // Array is not rotated
        }

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid; // Number of rotations
        } else if (arr[mid] <= arr[high]) {
            high = mid - 1; // Search on the left side
        } else if (arr[mid] >= arr[low]) {
            low = mid + 1; // Search on the right side
        }
    }

    return -1; // Invalid input or array not rotated
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int rotations = countRotations(arr, n);

    printf("Number of rotations: %d\n", rotations);

    return 0;

}

/*
This program utilizes binary search to find the number of rotations in a rotated sorted array of integers.
The countRotations function takes the array and its size as inputs.
It performs binary search to find the number of rotations by comparing the elements with their neighbors.
It checks if the array is already sorted or if the mid element is the smallest among its neighbors.
If the conditions are met, it returns the number of rotations. Otherwise, it updates the search range based on
the comparison results. The function returns -1 if the input is invalid or the array is not rotated.
The main function initializes the array and its size, calls the countRotations function, and prints the number of rotations.
*/
