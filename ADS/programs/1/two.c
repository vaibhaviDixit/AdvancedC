/*
Given an array of positive integers and a target sum, find the length of the smallest subarray whose sum is greater than
or equal to the target sum.

Input: {1, 3, 2, 1, 4, 2, 3}
Output: Length of the smallest subarray with sum >= 7 is: 3


*/
#include <stdio.h>
#include <limits.h>

int findSmallestSubarray(int arr[], int n, int targetSum) {
    int minLength = INT_MAX;  // Initialize the minimum length to a very large value
    int windowSum = 0;  // Track the current sum of the sliding window
    int windowStart = 0;  // Starting index of the sliding window

    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        windowSum += arr[windowEnd];  // Add the current element to the window sum

        while (windowSum >= targetSum) {  // Shrink the window until the sum is less than the target
            minLength = (windowEnd - windowStart + 1) < minLength ? (windowEnd - windowStart + 1) : minLength;
            // Update the minimum length if the current length is smaller

            windowSum -= arr[windowStart];  // Remove the element at the window start from the sum
            windowStart++;  // Move the window start ahead
        }
    }

    return minLength == INT_MAX ? 0 : minLength;  // Return the minimum length, or 0 if no subarray is found
}

int main() {
    int arr[] = {1, 3, 2, 1, 4, 2, 3};
    int targetSum = 7;
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    int minLength = findSmallestSubarray(arr, n, targetSum);
    printf("Length of the smallest subarray with sum >= %d is: %d\n", targetSum, minLength);

    return 0;
}

/*
We initialize the minimum length with a large value (INT_MAX) and the window sum and window start index to 0.
We iterate through the array using the window end pointer.
If the window sum is greater than or equal to the target sum, we update the minimum length and move the window start pointer.
We continue this process until the window sum is less than the target sum.
*/
