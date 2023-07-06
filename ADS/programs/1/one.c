/*
Given an array of integers and a positive integer K, find the maximum sum of any contiguous subarray of size K.

Input: {4, 2, 1, 7, 8, 1, 2, 8, 1, 0}
       k=3
Output: 16

*/

#include <stdio.h>

int findMaxSum(int arr[], int n, int k) {
    int windowSum = 0, maxSum = 0;

    // Calculate the sum of the first window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    maxSum = windowSum;

    // Slide the window and update the maximum sum
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    return maxSum;
}

int main() {
    int arr[] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = findMaxSum(arr, n, k);
    printf("Maximum sum of a subarray of size %d is: %d\n", k, maxSum);

    return 0;
}
/*
We use the sliding window technique to solve this problem efficiently.
We initialize the window sum with the sum of the first window (of size K).
We slide the window by adding the next element and subtracting the previous element.
At each step, we compare the window sum with the maximum sum and update it if necessary.
*/
