/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input: arr = {1, 5, 8, 9, 10, 17, 17, 20}
Output: Maximum Obtainable Value is 22

*/

// A Dynamic Programming solution for Rod cutting problem

#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Returns the best obtainable price for a rod of length n and price[] as prices of different pieces */
int cutRod(int price[], int n)
{
    int val[n+1];
    val[0] = 0;
    int i, j;

// Build the table val[] in bottom up manner and return the last entry from the table
    for (i = 1; i<=n; i++)
    {
        int max_val = INT_MIN;
        for (j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i-j-1]);
        val[i] = max_val;
    }

    return val[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout <<"Maximum Obtainable Value is "<<cutRod(arr, size);
    getchar();
    return 0;
}

/*
The cutRod Function: This function calculates the maximum obtainable value by cutting a rod of length n using the given price array. It takes two parameters: an array price[] representing the prices of different pieces of the rod and an integer n representing the length of the rod.

val Array: An integer array val[] of size n + 1 is created to store the maximum obtainable value for rods of varying lengths.

Base Case: The value val[0] is set to 0, representing the case where the rod length is zero (no value can be obtained).

Building the val Table: Two nested loops iterate over possible rod lengths and sublengths. The outer loop iterates from 1 to n, representing the current rod length. The inner loop iterates from 0 to i - 1, representing the possible sublengths.

The maximum value between the current max_val and price[j] + val[i - j - 1] is calculated and stored in max_val. This accounts for the case where the rod is divided into two parts: one of length j and the other of length i - j - 1. The price of both parts is added to the previously calculated maximum value for the remaining length.

The val[i] is set to max_val, representing the maximum obtainable value for a rod of length i.

Output in main Function: The main function initializes an array arr[] representing the prices for different lengths of the rod. It calculates the size of the array using sizeof(arr) / sizeof(arr[0]). The cutRod function is called with the array and size, and the result is printed using cout.

*/
