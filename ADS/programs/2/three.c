/*
Given an array of integers and a target sum, write a program to count the number of subarrays whose sum is equal to the
target sum using the prefix sum array.

Input: {10, 2, -2, -20, 10}
       targetsum= -10

Output: Number of Subarrays: 3

*/

#include <stdio.h>

// Function to count the number of subarrays with a given target sum
int countSubarrays(int arr[], int n, int targetSum) {
    int prefixSum = 0;
    int count = 0;
    int prefixSumMap[1000] = {0}; // Map to store prefix sums and their frequencies

    // Iterate through the array and calculate the prefix sum
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If the current prefix sum is equal to the target sum, increment the count
        if (prefixSum == targetSum) {
            count++;
        }

        // If there is a prefix sum (prefixSum - targetSum) that was encountered before,
        // add its frequency to the count
        if (prefixSumMap[prefixSum - targetSum] != 0) {
            count += prefixSumMap[prefixSum - targetSum];
        }

        // Increment the frequency of the current prefix sum in the prefixSumMap
        prefixSumMap[prefixSum]++;
    }

    return count; // Return the count of subarrays with the target sum
}

int main() {
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = -10;

    int subarrayCount = countSubarrays(arr, n, targetSum);

    printf("Number of Subarrays: %d\n", subarrayCount);

    return 0;
}
/*
This program counts the number of subarrays whose sum is equal to a target sum using the prefix sum array.
It uses a map (implemented as an array prefixSumMap) to store the prefix sum and its frequency.
If the current prefix sum equals the target sum, it increments the count variable.
If the difference between the current prefix sum and the target sum is encountered in the map,
it adds the frequency of that prefix sum to the count.
The count of subarrays is then printed.
*/
