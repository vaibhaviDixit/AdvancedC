/*
Given an array of integers, find the maximum sum of any contiguous subarray.

Input: {-2, -3, 4, -1, -2, 1, 5, -3}
Output: Maximum subarray sum: 7
*/

#include <stdio.h>

int maxSubarraySum(int arr[], int n) {
    int maxSum = 0;  // Variable to store the maximum sum
    int sum = 0;  // Variable to store the prefix sum

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    return maxSum;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, n);
    printf("Maximum subarray sum: %d\n", maxSum);

    return 0;
}
/*
This program finds the maximum sum of any contiguous subarray in an array of integers using the prefix sum array technique.
It iterates through the array, updating the prefix sum and keeping track of the maximum sum encountered so far.
If the sum becomes negative, it is reset to zero. The program then returns the maximum sum.
*/
