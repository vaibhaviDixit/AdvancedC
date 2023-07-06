/*
Given an array of integers, count the number of subarrays whose sum is zero.

Input: {4, 2, -3, 1, 6, -3, -1, 5, 1}
Output: Number of subarrays with zero sum: 2
*/

#include <stdio.h>

// Function to count the number of subarrays with zero sum
int countSubarraysWithZeroSum(int arr[], int n) {
    int count = 0; // Variable to store the count of subarrays
    int sum = 0; // Variable to store the prefix sum

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If the current prefix sum is zero, increment the count
        if (sum == 0) {
            count++;
        }

        // Check for subarrays with zero sum using a nested loop
        for (int j = 0; j < i; j++) {
            if (sum - arr[j] == 0) {
                count++;
            }
        }
    }

    return count; // Return the count of subarrays with zero sum
}

int main() {
    int arr[] = {4, 2, -3, 1, 6, -3, -1, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int subarraysCount = countSubarraysWithZeroSum(arr, n);
    printf("Number of subarrays with zero sum: %d\n", subarraysCount);

    return 0;
}




/*
This program counts the number of subarrays in an array of integers whose sum is zero using the prefix sum array technique.
It iterates through the array, updating the prefix sum and checking if the sum is zero.
It also checks for subarrays with a sum of zero by comparing the prefix sum with previous sums. The program returns the count of subarrays with zero sum.
*/
