/*
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided. There is also an
attractive offer by the candy store. We can buy a single candy from the store and get at most K other candies (all are different types) for free.

Find the minimum amount of money we have to spend to buy all the N different candies.
Find the maximum amount of money we have to spend to buy all the N different candies.
In both cases, we must utilize the offer and get the maximum possible candies back. If k or more candies are available, we must take k candies for every candy purchase. If less than k candies are available, we must take all candies for a candy purchase.

Input :
price[] = {3, 2, 1, 4}
k = 2
Output :
Min = 3, Max = 7

*/

// C++ implementation to find the minimum and maximum amount
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum amount to buy all candies
int findMinimum(int arr[], int n, int k)
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		// Buy current candy
		res += arr[i];

		// And take k candies for free from the last
		n = n - k;
	}
	return res;
}

// Function to find the maximum amount to buy all candies
int findMaximum(int arr[], int n, int k)
{
	int res = 0, index = 0;

	for (int i = n - 1; i >= index; i--)
	{
		// Buy candy with maximum amount
		res += arr[i];

		// And get k candies for free from
		// the starting
		index += k;
	}
	return res;
}

int main()
{
	int arr[] = { 8, 7, 1,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	sort(arr, arr + n);

	// Function call
	cout << findMinimum(arr, n, k) << " "
		<< findMaximum(arr, n, k) << endl;
	return 0;
}

/*

Two functions are defined:

findMinimum: This function calculates the minimum amount required to buy all candies. It takes the following parameters:

arr[]: An array representing the prices of candies.
n: The number of candies available.
k: The number of candies you can buy for the price of one.
Inside the function:
An integer variable res is initialized to 0, which will store the minimum amount.
A loop iterates through the array arr[], buying each candy at its price and reducing the available candies by k after each purchase.
The function returns res, which represents the minimum amount required.
findMaximum: This function calculates the maximum amount required to buy all candies. It takes the same parameters as the findMinimum function.
Inside the function:

An integer variable res is initialized to 0, which will store the maximum amount.
An integer variable index is initialized to 0, representing the index of the candies you start buying from.
A loop iterates through the array arr[] in reverse order, buying each candy at its price and increasing the starting index by k after each purchase.
The function returns res, which represents the maximum amount required.
In the main function:

An integer array arr[] is defined, representing the prices of candies.
The number of candies n is calculated using sizeof(arr) / sizeof(arr[0]).
The value of k is set to 2, indicating that you can buy 2 candies and get 2 more for free.
The arr[] array is sorted in ascending order using sort.
The findMinimum and findMaximum functions are called with the arr[], n, and k as arguments.
The program prints both the minimum and maximum amounts required to buy all candies to the console.

*/
