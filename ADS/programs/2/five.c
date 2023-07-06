/*
Given an array of integers, write a program to find the maximum sum of a subarray and its starting and ending indices using the prefix sum array.

Input: {-2, -3, 4, -1, -2, 1, 5, -3}
Output: Maximum Subarray Sum: 7
        Starting Index: 2
        Ending Index: 6
*/
#include <stdio.h>

// Function to find the maximum subarray sum and its starting and ending indices
void findMaxSubarraySum(int arr[], int n) {
    int prefixSum = 0, maxSum = 0;
    int start = 0, end = -1;
    int tempStart = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If the current prefix sum becomes negative, reset it to 0 and update the temporary start index
        if (prefixSum < 0) {
            prefixSum = 0;
            tempStart = i + 1;
        }
        // If the current prefix sum is greater than the max sum, update the max sum and the start and end indices
        else if (prefixSum > maxSum) {
            maxSum = prefixSum;
            start = tempStart;
            end = i;
        }
    }

    printf("Maximum Subarray Sum: %d\n", maxSum);
    printf("Starting Index: %d\n", start);
    printf("Ending Index: %d\n", end);
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMaxSubarraySum(arr, n);

    return 0;
}
/*
This program finds the maximum sum of a subarray, along with its starting and ending indices, using the prefix sum array.
It iterates through the array and computes the prefix sum. If the prefix sum becomes negative, it resets to zero and updates the tempStart variable.
If a higher sum is encountered, it updates the maxSum, start, and end variables. Finally, the maximum subarray sum and its indices are printed.
*/
