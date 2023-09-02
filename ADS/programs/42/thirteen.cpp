/*
Given a set of integers, find a distinct sum that can be generated from the subsets of the given sets and print them in increasing order.
It is given that sum of array elements is small.

Input  : arr[] = {1, 2, 3}
Output : 0 1 2 3 4 5 6

Input : arr[] = {2, 3, 4, 5, 6}
Output : 0 2 3 4 5 6 7 8 9 10 11 12
         13 14 15 16 17 18 20

Input : arr[] = {20, 30, 50}
Output : 0 20 30 50 70 80 100

*/


// C++ program to print distinct subset sums of a given array.
#include<bits/stdc++.h>
using namespace std;

// Uses Dynamic Programming to find distinct subset sums
void printDistSum(int arr[], int n)
{
	int sum = 0;
	for (int i=0; i<n; i++)
		sum += arr[i];

	// dp[i][j] would be true if arr[0..i-1] has a subset with sum equal to j.
	bool dp[n+1][sum+1];
	memset(dp, 0, sizeof(dp));

	// There is always a subset with 0 sum
	for (int i=0; i<=n; i++)
		dp[i][0] = true;

	// Fill dp[][] in bottom up manner
	for (int i=1; i<=n; i++)
	{
		dp[i][arr[i-1]] = true;
		for (int j=1; j<=sum; j++)
		{
			// Sums that were achievable
			// without current array element
			if (dp[i-1][j] == true)
			{
				dp[i][j] = true;
				dp[i][j + arr[i-1]] = true;
			}
		}
	}

	// Print last row elements
	for (int j=0; j<=sum; j++)
		if (dp[n][j]==true)
			cout << j << " ";
}


int main()
{
	int arr[] = {2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	printDistSum(arr, n);
	return 0;
}

/*
Main Function:

The main function initializes an array arr containing the input elements.
It calculates the size of the array using sizeof(arr) / sizeof(arr[0]) and stores it in the variable n.
It calls the printDistSum function to find and print the distinct subset sums of the array.
Function printDistSum:

This function takes an array arr and its size n as input.
It calculates the total sum of all elements in the array.
Initializes a 2D boolean array dp of dimensions (n+1) x (sum+1) to store whether a subset sum is achievable or not.
Initializes the first column of the dp array to true because there's always an empty subset with sum 0.
Uses a bottom-up approach to fill the dp array.
For each element arr[i-1] at index i, if a subset sum j can be achieved without considering the current element (dp[i-1][j] is true), then both dp[i][j] and dp[i][j + arr[i-1]] are marked as true. This indicates that a subset sum of j is achievable with and without the current element.
After filling the dp array, it prints the last row elements (subset sums that can be achieved using all elements of the array).

*/


