/*
Given an array of integers, find the largest sum contiguous subarray that contains prime numbers.

Input: 2 5 7 4 9
Output: The largest sum contiguous subarray with prime numbers is: 14

Input: 4 3 2 9 8
Output: The largest sum contiguous subarray with prime numbers is: 5

*/
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime.
bool isPrime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Function to find the largest sum contiguous subarray with prime numbers using Kadane's algorithm.
int maxSubarraySumWithPrimes(int arr[], int n)
{
    int max_so_far = 0;
    int max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            max_ending_here += arr[i];

            if (max_ending_here < 0)
                max_ending_here = 0;

            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
        }
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

    int max_sum = maxSubarraySumWithPrimes(arr, n);
    printf("The largest sum contiguous subarray with prime numbers is: %d\n", max_sum);

    return 0;
}

/*
The program checks if a number is prime using the isPrime function.
It then uses Kadane's algorithm to find the largest sum contiguous subarray that contains prime numbers.
The algorithm iterates through the array and keeps track of the maximum sum, considering only prime numbers.
The maximum sum found is returned as the result.
*/
