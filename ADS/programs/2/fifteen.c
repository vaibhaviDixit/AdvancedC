/*
Given an array of integers, write a program to find the length of the longest subarray with a sum of zero using the prefix sum array.

Input: {4, 2, -3, 1, 6, -3, -1, 5, 1}
Output: Length of the longest subarray with a sum of zero: 5

Input: {1, 2, 3}
Output: Length of the longest subarray with a sum of zero: 0

*/

#include <stdio.h>

int findLongestSubarray(int arr[], int n) {
    int maxLength = 0;  // Variable to store the length of the longest subarray
    int sum = 0;  // Variable to store the prefix sum
    int prefixSum[n];  // Array to store the prefix sums

    // Initialize the prefix sum array with 0
    prefixSum[0] = 0;

    // Calculate the prefix sum for each element in the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        prefixSum[i + 1] = sum;
    }

    // Find the longest subarray with sum 0
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // If the sum of the subarray is 0 and the length is greater than maxLength, update maxLength
            if (prefixSum[j] - prefixSum[i] == 0 && (j - i) > maxLength) {
                maxLength = j - i;
            }
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {6,8,-8,-6,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int length = findLongestSubarray(arr, n);
    printf("Length of the longest subarray with a sum of zero: %d\n", length);

    return 0;
}

/*
This program finds the length of the longest subarray with a sum of zero using the prefix sum array.
It uses a map (implemented as an array prefixSumMap) to store the prefix sum and its corresponding index.
If the prefix sum becomes zero, it updates the maxLength variable. If the same prefix sum is encountered again,
it computes the length of the subarray and updates the maxLength if necessary.
The length of the longest subarray is then printed.
*/
