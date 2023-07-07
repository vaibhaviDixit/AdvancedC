/*
Given an array of integers, find the length of the longest increasing subarray.

Input: 5 3 1 2 4
Output: The length of the longest increasing subarray is: 3

*/

#include <stdio.h>

// Function to find the length of the longest increasing subarray using Kadane's algorithm.
int longestIncreasingSubarray(int arr[], int n)
{
    int max_length = 1; // Initialize the maximum length as 1.
    int length = 1; // Initialize the length of the current increasing subarray as 1.

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            length++; // Increment the length of the current increasing subarray.

            if (length > max_length)
                max_length = length;
        }
        else
        {
            length = 1; // Reset the length of the current increasing subarray.
        }
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

    int longest_length = longestIncreasingSubarray(arr, n);
    printf("The length of the longest increasing subarray is: %d\n", longest_length);

    return 0;
}


/*
The program uses Kadane's algorithm to find the length of the longest increasing subarray.
It iterates through the array, maintaining two variables: max_length (maximum length of the increasing subarray seen so far)
and length (length of the current increasing subarray). Whenever an element is greater than the previous element, the length
is incremented. If the length becomes greater than max_length, it is updated.
If an element is not greater than the previous element, the length is reset to 1.
The max_length is returned as the result.
*/
