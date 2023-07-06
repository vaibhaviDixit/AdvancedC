/*
Given an array of integers, find the length of the longest subarray that forms a mountain pattern.

Note: A mountain pattern array is a sequence of numbers that exhibits a specific pattern resembling a mountain.
In this pattern, the elements in the array first increase and then decrease. The increasing part of the array represents the
ascending slope of the mountain, while the decreasing part represents the descending slope.

Input: {2, 3, 4, 5, 2, 1, 0}
Output: Length of the longest mountain subarray: 7

*/

#include <stdio.h>

// Function to find the length of the longest mountain subarray
int findLongestMountain(int arr[], int n) {
    int maxLength = 0; // Variable to store the length of the longest mountain subarray

    // Iterate through the array
    for (int i = 1; i < n - 1; i++) {
        int length = 1; // Initialize the length of the current mountain subarray

        // Check if the current element is the peak of a mountain
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            // Traverse the left side of the peak
            int j = i;
            while (j > 0 && arr[j] > arr[j - 1]) {
                length++;
                j--;
            }

            // Traverse the right side of the peak
            int k = i;
            while (k < n - 1 && arr[k] > arr[k + 1]) {
                length++;
                k++;
            }

            // Update the maximum length if the current mountain subarray is longer
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {2, 3, 4, 5, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int longestMountainLength = findLongestMountain(arr, n);
    printf("Length of the longest mountain subarray: %d\n", longestMountainLength);

    return 0;
}
/*
The given C program finds the length of the longest subarray that forms a mountain pattern in an array of integers.
A mountain pattern is a sequence of integers where there is an increasing sequence of numbers followed by a decreasing sequence
of numbers.

The function findLongestMountain takes an array arr and its size n as input. It initializes the maxLength variable to 0,
which will store the length of the longest mountain subarray found.

The program then iterates through the array from index 1 to n-2 (excluding the first and last elements).
For each index i, it checks if the current element arr[i] is the peak of a mountain.
To be a peak, arr[i] must be greater than its adjacent elements arr[i-1] and arr[i+1].

If arr[i] is a peak, the program proceeds to traverse the left side and the right side of the peak to calculate the length of
the mountain subarray. It uses two nested while loops: one to traverse the left side and another to traverse the right side.
In each loop, it increments the length variable and moves to the adjacent elements until the sequence of increasing or decreasing
numbers ends.

After traversing the left and right sides, the program checks if the length of the current mountain subarray is longer than
the maxLength found so far. If it is, the maxLength is updated.

Finally, the function returns the maxLength as the length of the longest mountain subarray.

In the main function, an example array arr is defined, and the function findLongestMountain is called with the array and its size.
The length of the longest mountain subarray is printed to the console.

*/
