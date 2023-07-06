/*
 Given an array of integers containing only 0s and 1s,
 write a program to find the length of the longest subarray with an equal number of 0s and 1s using the prefix sum array.

 Input: {0, 0, 1, 0, 1, 1, 0}
 Output: Length of Longest Subarray: 6

*/
#include <stdio.h>
#include <limits.h>

// Function to find the length of the longest subarray with equal number of 0s and 1s
int findLongestSubarray(int arr[], int n) {
    int prefixSum = 0;
    int maxLength = 0;
    int prefixSumMap[1000] = {0}; // Map to store prefix sums and their corresponding indices

    for (int i = 0; i < n; i++) {
        prefixSum += (arr[i] == 0) ? -1 : 1; // Calculate the prefix sum by considering 0 as -1 and 1 as 1

        if (prefixSum == 0) {
            maxLength = i + 1; // If prefix sum is 0, the subarray from the beginning till now has equal 0s and 1s
        } else if (prefixSumMap[prefixSum] != 0) {
            int length = i - prefixSumMap[prefixSum] + 1; // Calculate the length of the subarray with the same prefix sum

            if (length > maxLength) {
                maxLength = length; // Update the maximum length if a longer subarray is found
            }
        } else {
            prefixSumMap[prefixSum] = i + 1; // Store the index of the first occurrence of a prefix sum
        }
    }

    return maxLength; // Return the maximum length of a subarray with equal 0s and 1s
}

int main() {
    int arr[] = {0, 0, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxLength = findLongestSubarray(arr, n);

    printf("Length of Longest Subarray: %d\n", maxLength);

    return 0;
}

/*
This program finds the length of the longest subarray with an equal number of 0s and 1s using the prefix sum array.
It maintains a prefixSum variable and a prefixSumMap array to store the prefix sum and its corresponding index.
If the prefix sum becomes zero, it updates the maxLength variable. If the same prefix sum is encountered again, it computes the length of the subarray
and updates the maxLength if necessary. The length of the longest subarray is then printed.
*/
