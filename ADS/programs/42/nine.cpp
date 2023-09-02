/*
The partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same.

Input: arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

Input: arr[] = {1, 5, 3}
Output: false

*/

// A Dynamic Programming based  C++ program to partition problem
#include <bits/stdc++.h>
using namespace std;

// Returns true if arr[] can be partitioned in two subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
	int sum = 0;
	int i, j;

	// Calculate sum of all elements
	for (i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 != 0)
		return false;

	bool part[sum / 2 + 1][n + 1];

	// initialize top row as true
	for (i = 0; i <= n; i++)
		part[0][i] = true;

	// initialize leftmost column, except part[0][0], as 0
	for (i = 1; i <= sum / 2; i++)
		part[i][0] = false;

	// Fill the partition table in bottom up manner
	for (i = 1; i <= sum / 2; i++) {
		for (j = 1; j <= n; j++) {
			part[i][j] = part[i][j - 1];
			if (i >= arr[j - 1])
				part[i][j] = part[i][j]
							|| part[i - arr[j - 1]][j - 1];
		}
	}

	/* // uncomment this part to print table
	for (i = 0; i <= sum/2; i++)
	{
	for (j = 0; j <= n; j++)
		cout<<part[i][j];
	cout<<endl;
	} */

	return part[sum / 2][n];
}

int main()
{
	int arr[] = { 3, 1, 1, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	if (findPartiion(arr, n) == true)
		cout << "Can be divided into two subsets of equal sum";
	else
		cout << "Can not be divided into two subsets of equal sum";
	return 0;
}

/*

Function findPartition:

This function takes an integer array arr and the number of elements n as parameters.
It calculates the total sum of all elements in the array to determine if equal subsets are possible.
If the sum is odd, the array cannot be partitioned into two subsets of equal sum, and the function returns false.
It initializes a 2D array part to store dynamic programming results, where part[i][j] represents whether a subset of sum i can be formed using the first j elements of the array.
The top row of the part array is initialized to true because an empty subset can always have a sum of 0.
The leftmost column (except part[0][0]) is initialized to false because no subset can be formed using a non-zero sum with zero elements.
The rest of the array is filled using a bottom-up approach, where part[i][j] is set to true if either the subset can be formed using the first j-1 elements or by including the j-th element and checking if a subset of sum i - arr[j-1] can be formed.
The final result is stored in part[sum/2][n], where sum is the total sum of the array elements.

*/

