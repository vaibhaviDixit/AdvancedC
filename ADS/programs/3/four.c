/*
Given a sorted array of integers and a target value, find the element in the array that is closest to the target.

Input: {1, 3, 5, 7, 9}
       target = 4
Output: Closest element to 4 is 5
*/

#include <stdio.h>

// Binary search function to find the element closest to the target
int binarySearchClosest(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // At this point, low > high
    if (low > 0 && (low == n || target - arr[high] < arr[low] - target)) {
        return arr[high];
    } else {
        return arr[low];
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int closest = binarySearchClosest(arr, n, target);

    printf("Closest element to %d is %d\n", target, closest);

    return 0;
}

/*
This program uses binary search to find the element in a sorted array that is closest to a given target value.
The binarySearchClosest function takes the array, its size, and the target value as inputs.
It performs binary search to find the target value or the elements closest to it.
If the target value is found in the array, it returns the target value. Otherwise, it determines which element is closer to the target by
comparing the differences. The main function initializes the array, its size, and the target value.
It calls the binarySearchClosest function and prints the closest element to the target value.
*/
