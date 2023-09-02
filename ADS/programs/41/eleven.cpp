/*
Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence (LIS) i.e.,
the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.

Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output:1

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: 4

*/

// Dynamic Programming C++ implementation of LIS problem
#include <bits/stdc++.h>
using namespace std;

// lis() returns the length of the longest increasing subsequence in arr[] of size n
int lis(int arr[], int n)
{
	int lis[n];

	lis[0] = 1;

	// Compute optimized LIS values in bottom up manner
	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}

	// Return maximum value in lis[]
	return *max_element(lis, lis + n);
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printf("Length of lis is %d\n", lis(arr, n));
	return 0;
}

/*

The lis Function: This function calculates the length of the longest increasing subsequence (LIS) in an array arr[] of size n. It takes two parameters: an array arr[] and an integer n representing the size of the array.

Array lis: An integer array lis[] of size n is declared to store the length of the longest increasing subsequence ending at index i.

Base Case: The initial value of lis[0] is set to 1, as the LIS of a single element is 1.

Dynamic Programming Calculation: The array lis[] is filled iteratively using a bottom-up approach. The outer loop iterates from index 1 to n-1. For each index i, the inner loop iterates from index 0 to i-1. If the element at index i is greater than the element at index j, and the length of the LIS ending at index i (lis[i]) can be extended by including the element at index j, then lis[i] is updated to lis[j] + 1.

Returning Maximum Length: After filling the lis[] array, the program returns the maximum value among the elements of the lis[] array using the max_element function.

*/
