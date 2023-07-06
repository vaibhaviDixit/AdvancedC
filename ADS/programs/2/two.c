/*
Given an array of integers and a subarray length, write a program to find the subarray with the maximum average using the prefix sum array.

Input: {1, 12, -5, -6, 50, 3}
       k=4
Output: Subarray with Maximum Average: 12 -5 -6 50

*/

#include <stdio.h>

// Function to find and print the subarray with the maximum average
void findMaxAverageSubarray(int arr[], int n, int k) {
    int prefixSum[n];
    prefixSum[0] = arr[0];

    // Calculate the prefix sum of the array
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    int maxSum = prefixSum[k - 1]; // Initialize the maximum sum as the sum of the first k elements
    int startIndex = 0; // Initialize the start index of the subarray with maximum average

    // Iterate from k to n to find the subarray with maximum average
    for (int i = k; i < n; i++) {
        int sum = prefixSum[i] - prefixSum[i - k]; // Calculate the sum of the current k-sized subarray

        if (sum > maxSum) {
            maxSum = sum; // Update the maximum sum if a larger sum is found
            startIndex = i - k + 1; // Update the start index of the subarray with maximum average
        }
    }

    printf("Subarray with Maximum Average: ");
    for (int i = startIndex; i < startIndex + k; i++) {
        printf("%d ", arr[i]); // Print the elements of the subarray with maximum average
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 12, -5, -6, 50, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4; // Size of the subarray

    findMaxAverageSubarray(arr, n, k);

    return 0;
}


/*
This program finds the subarray with the maximum average of a given length using the prefix sum array.
It first computes the prefix sum array. Then, it iterates through the array and calculates the sum of each subarray of length k
using the prefix sum array. If the current sum is greater than the maximum sum, it updates the maximum sum and the starting index of the subarray.
Finally, the subarray with the maximum average is printed.
*/
