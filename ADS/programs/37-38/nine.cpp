/*
Given an array of distinct integers, find if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c and d are distinct elements.
If there are multiple answers, then print any of them. Use hashing technique.

Input:   {3, 4, 7, 1, 2, 9, 8}
Output:  (3, 8) and (4, 7)

Input:   {3, 4, 7, 1, 12, 9};
Output:  (4, 12) and (7, 9)

*/

#include<bits/stdc++.h>
using namespace std;

bool findPairs(int arr[], int n)
{
	// Create an empty Hash to store mapping from sum to pair indexes
	map<int, pair<int, int> > Hash;

	// Traverse through all possible pairs of arr[]
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			// If sum of current pair is not in hash,
			// then store it and continue to next pair
			int sum = arr[i] + arr[j];
			if (Hash.find(sum) == Hash.end())
				Hash[sum] = make_pair(i, j);

			else // Else (Sum already present in hash)
			{
				// Find previous pair
				pair<int, int> pp = Hash[sum];// pp->previous pair

				// Since array elements are distinct, we don't
				// need to check if any element is common among pairs
				cout << "(" << arr[pp.first] << ", " << arr[pp.second]
					<< ") and (" << arr[i] << ", " << arr[j] << ")";
				return true;
			}
		}
	}

	cout << "No pairs found";
	return false;
}

int main()
{
	int arr[] = {3, 4, 7, 1, 2, 9, 8};
	int n = sizeof arr / sizeof arr[0];
	findPairs(arr, n);
	return 0;
}

/*
findPairs() Function: This is the main function that finds pairs of elements in the array that satisfy the condition a + b = c + d.
It takes an integer array arr[] and its size n as arguments.

Hash Map: The code uses a map<int, pair<int, int>> named Hash to store pairs of elements whose sum is the key.

Nested Loop: The code uses nested loops to iterate through all possible pairs of elements in the array.

Checking Sum in Hash: For each pair (i, j) of elements, it calculates the sum sum = arr[i] + arr[j] and checks whether this sum is present in the Hash.

Storing Pairs: If the sum is not present in the Hash, the current pair (i, j) is stored in the Hash with the sum as the key.

Finding Desired Pair: If the sum is already present in the Hash, it means a previous pair with the same sum was found. The previous pair (pp.first, pp.second) and the current pair (i, j) together satisfy the condition a + b = c + d. The program prints both pairs and returns true.

*/

