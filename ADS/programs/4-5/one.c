/*
Given an array of integers, find the contiguous subarray with the largest sum.

Input: 2 6 -16 12 3
Output: The largest sum contiguous subarray is: 15


*/
#include <stdio.h>

// Function to find the largest sum contiguous subarray using Kadane's algorithm.
int maxSubarraySum(int arr[], int n)
{
    int max_so_far = arr[0]; // Initialize the maximum sum as the first element.
    int max_ending_here = arr[0]; // Initialize the maximum sum ending at the current position.

    for (int i = 1; i < n; i++)
    {
        // Calculate the maximum sum ending at the current position.
        max_ending_here = max_ending_here + arr[i];
        // If the maximum sum ending at the current position is negative, set it to 0.
        if (max_ending_here < 0)
            max_ending_here = 0;
        // Update the maximum sum so far if the maximum sum ending at the current position is greater.
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    return max_so_far;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubarraySum(arr, n);
    printf("The largest sum contiguous subarray is: %d\n", max_sum);

    return 0;
}
/*
The program uses Kadane's algorithm to find the largest sum contiguous subarray.
It iterates through the array, maintaining two variables: max_so_far (maximum sum seen so far) and max_ending_here
(maximum sum ending at the current position).
The algorithm calculates the maximum sum ending at each position and updates max_so_far if a new maximum is found.
*/
