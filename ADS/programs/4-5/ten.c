/*
Given an array of integers, find the length of the longest bitonic subarray.
Note: An array is said to be bitonic if the elements in the array are first strictly increasing and then strictly decreasing.

Input:  12 4 78 90 45 23
Output: The length of the longest bitonic subarray is: 5

*/

#include <stdio.h>

// Function to find the length of the longest bitonic subarray using Kadane's algorithm.
int longestBitonicSubarray(int arr[], int n)
{
    int inc[n]; // Array to store the lengths of the increasing subarrays.
    int dec[n]; // Array to store the lengths of the decreasing subarrays.

    inc[0] = 1; // Initialize the length of the first increasing subarray as 1.
    dec[n - 1] = 1; // Initialize the length of the last decreasing subarray as 1.

    // Calculate the lengths of the increasing subarrays from left to right.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            inc[i] = inc[i - 1] + 1;
        else
            inc[i] = 1;
    }

    // Calculate the lengths of the decreasing subarrays from right to left.
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
            dec[i] = dec[i + 1] + 1;
        else
            dec[i] = 1;
    }

    int max_length = 1; // Initialize the maximum length as 1.

    // Find the maximum length of the bitonic subarray.
    for (int i = 0; i < n; i++)
    {
        int length = inc[i] + dec[i] - 1;
        if (length > max_length)
            max_length = length;
    }

    return max_length;
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

    int longest_length = longestBitonicSubarray(arr, n);
    printf("The length of the longest bitonic subarray is: %d\n", longest_length);

    return 0;
}
/*
The program uses Kadane's algorithm to find the length of the longest bitonic subarray.
It calculates two arrays, inc and dec, to store the lengths of the increasing and decreasing subarrays, respectively.
It first calculates the lengths of the increasing subarrays from left to right, storing them in the inc array.
Then, it calculates the lengths of the decreasing subarrays from right to left, storing them in the dec array.
Finally, it iterates through the arrays to find the maximum length of the bitonic subarray by adding the lengths of the
increasing and decreasing subarrays at each index.
The maximum length is returned as the result.
*/
