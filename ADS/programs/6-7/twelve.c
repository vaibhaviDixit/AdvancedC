/*

Given an array of integers, find the first missing positive integer. The first missing positive integer is the smallest positive integer that is not present in the array.

Input: Given array: [3, 4, -1, 1]
Output: First missing positive integer: 2

Input: Given array: [3, 4, 2, -1]
Output: First missing positive integer: 1

*/

#include <stdio.h>

// Swap Function
// This function takes two integer pointers 'a' and 'b' as input.
// It swaps the values of 'a' and 'b'.
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// First Missing Positive Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It finds the first missing positive integer in the array and returns it.
int firstMissingPositive(int arr[], int n) {
    // The algorithm aims to place each positive integer in its correct position in the array.
    // For an integer x (1 <= x <= n), the correct position for x is at index (x - 1).

    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            // If the current element is a positive integer and is within the valid range (1 to n),
            // and it is not in its correct position, swap it to its correct position.
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }

    // After rearranging the array, the first missing positive integer will be the first element that does not match its index.

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    // If all positive integers from 1 to n are present in the array, the missing positive integer is (n + 1).

    return n + 1;
}

int main() {
    // Sample array with positive and negative integers
    int arr[] = {3, 4, 2, -1};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the given array
    printf("Given array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the firstMissingPositive function to find the first missing positive integer
    int first_missing = firstMissingPositive(arr, n);

    // Print the first missing positive integer
    printf("\nFirst missing positive integer: %d", first_missing);

    return 0;
}

/*
The program implements the First Missing Positive Algorithm to find the first missing positive integer in a given array.
The firstMissingPositive function takes an array arr and its size n as input and returns the first missing positive integer.
The algorithm rearranges the elements of the array to place each positive integer in its correct position.
It uses the swap function to move the elements to their correct positions.
After rearranging the array, the first missing positive integer will be the first element that does not match its index (i.e., arr[i] != i + 1).
If all positive integers from 1 to n are present in the array, the first missing positive integer is (n + 1).

*/

