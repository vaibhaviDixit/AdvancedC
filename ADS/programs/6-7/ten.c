/*
Given an array of integers, find the length of the longest increasing subsequence (LIS). An increasing subsequence is a subsequence where
the elements are in strictly increasing order, but not necessarily contiguous. Implement the LIS algorithm using Dynamic Programming and
return the length of the longest increasing subsequence in the given array.

Input: Given array: [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: Length of the longest increasing subsequence: 6 (The LIS is [10, 22, 33, 50, 60, 80])

*/

#include <stdio.h>

// LIS Algorithm
// This function takes an array 'arr' and its size 'n' as input.
// It computes the length of the longest increasing subsequence in the array.
// It returns the length of the longest increasing subsequence.
int lis(int arr[], int n) {
    int lis[n];
    int max_len = 1; // Variable to store the maximum length of LIS found so far.

    // Initialize LIS values for all indexes as 1 (minimum length is 1 for each element).
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    // Compute LIS values in a bottom-up manner.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If the current element (arr[i]) is greater than the previous element (arr[j]),
            // and the LIS value ending at the current element is less than LIS value ending at the previous element plus one,
            // then update the LIS value ending at the current element.
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
        // Update the maximum length of LIS found so far.
        if (lis[i] > max_len)
            max_len = lis[i];
    }

    return max_len; // Return the length of the longest increasing subsequence.
}

int main() {
    // Sample array
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the given array
    printf("Given array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the LIS function to find the length of the longest increasing subsequence
    int longest_subseq = lis(arr, n);

    // Print the length of the longest increasing subsequence
    printf("\nLength of the longest increasing subsequence: %d", longest_subseq);

    return 0;
}

/*
The program demonstrates the Longest Increasing Subsequence (LIS) algorithm using Dynamic Programming.
The LIS algorithm finds the length of the longest increasing subsequence in a given array.
The lis function takes an array arr and its size n as input and returns the length of the longest increasing subsequence.
The algorithm uses a dynamic programming approach. It maintains an array lis of the same size as the input array to store the length of the LIS ending at each index.
The LIS value for each index is initialized to 1 since the minimum length of any subsequence is 1 (the element itself).
The algorithm iterates through the array and compares each element with the elements before it. If the current element is greater than the previous element and its LIS value can be extended, it updates the LIS value for the current index.
Finally, the maximum length of the LIS found is returned, which represents the length of the longest increasing subsequence in the array.
The main function initializes an array with some sample values and calculates the size of the array.
It then calls the lis function to find the length of the longest increasing subsequence and prints the result.
The given array is printed before finding the LIS, and the length of the longest increasing subsequence is printed afterward.


*/
