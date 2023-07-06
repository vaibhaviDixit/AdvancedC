/*
Given an array of integers and a target sum, write a program to find the length of the smallest
subarray whose sum is greater than the target sum using the prefix sum array.

Input: {1, 4, 45, 6, 10, 19}
       targetsum= 51
Output: Length of Smallest Subarray: 3

*/
#include <stdio.h>
#include <limits.h>

// Function to find the length of the smallest subarray with a sum greater than the target sum
int findSmallestSubarray(int arr[], int n, int targetSum) {
    int prefixSum = 0;
    int minLength = INT_MAX;
    int start = 0;

    // Iterate through the array and calculate the prefix sum
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Shrink the subarray from the start until the prefix sum is smaller than or equal to the target sum
        while (prefixSum > targetSum && start <= i) {
            minLength = (i - start + 1 < minLength) ? i - start + 1 : minLength; // Update the minimum length
            prefixSum -= arr[start]; // Reduce the prefix sum by removing the element at the start
            start++; // Move the start index to the right
        }
    }

    return (minLength == INT_MAX) ? -1 : minLength; // Return -1 if no subarray is found, else return the minimum length
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 51;

    int minLength = findSmallestSubarray(arr, n, targetSum);

    if (minLength == -1) {
        printf("No subarray found!\n");
    } else {
        printf("Length of Smallest Subarray: %d\n", minLength);
    }

    return 0;
}


/*
This program finds the length of the smallest subarray whose sum is greater than a target sum using the prefix sum array.
It maintains a prefixSum variable and a start variable to keep track of the subarray. If the prefixSum becomes greater than the target sum,
it updates the minLength and reduces the prefixSum by subtracting elements from the start of the subarray.
The length of the smallest subarray is then printed.
*/
