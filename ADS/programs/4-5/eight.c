/*
Given an array of integers, find the maximum product of a subarray.

Input: -1 -2 3 -4 5
Output: The maximum product of a subarray is: 120

*/

#include <stdio.h>
#define maximum(a,b) (a>b?a:b)
#define minimum(a,b) (a>b?b:a)

// Function to find the maximum product of a subarray using Kadane's algorithm.
int maxProductSubarray(int arr[], int n)
{
    int max_so_far = arr[0]; // Initialize the maximum product as the first element.
    int max_ending_here = arr[0]; // Initialize the maximum product ending at the current position.
    int min_ending_here = arr[0]; // Initialize the minimum product ending at the current position.
    int max_product = arr[0]; // Initialize the maximum product so far.

    for (int i = 1; i < n; i++)
    {
        // Update the maximum and minimum products ending at the current position.
        int temp_max = max_ending_here;
        max_ending_here = maximum(arr[i], maximum(arr[i] * max_ending_here, arr[i] * min_ending_here));
        min_ending_here = minimum(arr[i], minimum(arr[i] * temp_max, arr[i] * min_ending_here));
        // Update the maximum product so far.
        max_product = maximum(max_product, max_ending_here);
    }

    return max_product;
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

    int max_product = maxProductSubarray(arr, n);
    printf("The maximum product of a subarray is: %d\n", max_product);

    return 0;
}

/*
The program uses Kadane's algorithm to find the maximum product of a subarray.
It maintains four variables: max_so_far (maximum product seen so far), max_ending_here
(maximum product ending at the current position), min_ending_here (minimum product ending at the current position),
and max_product (maximum product found so far). The algorithm updates these variables based on the current element and
calculates the maximum product by comparing max_product with max_ending_here.
*/
