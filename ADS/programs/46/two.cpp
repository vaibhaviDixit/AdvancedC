/*

Given a sorted array key [0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches for keys[i].
Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is the level of that node multiplied by its frequency. The level of the root is 1.

Input:  keys[] = {10, 12}, freq[] = {34, 50}
Output: Cost of Optimal BST is 118

There can be following two possible BSTs
        10                       12
          \                     /
           12                 10
          I                     II
Frequency of searches of 10 and 12 are 34 and 50 respectively.
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118


Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
Output: Cost of Optimal BST is 142

*/


#include <bits/stdc++.h>
using namespace std;

// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j);

/* A Dynamic Programming based function that calculates
minimum cost of a Binary Search Tree. */
int optimalSearchTree(int keys[], int freq[], int n)
{
	/* Create an auxiliary 2D matrix to store results
	of subproblems */
	int cost[n][n];

	/* cost[i][j] = Optimal cost of binary search tree
	that can be formed from keys[i] to keys[j].
	cost[0][n-1] will store the resultant cost */

	// For a single key, cost is equal to frequency of the key
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	// Now we need to consider chains of length 2, 3, ... .
	// L is chain length.
	for (int L = 2; L <= n; L++)
	{
		// i is row number in cost[][]
		for (int i = 0; i <= n-L+1; i++)
		{
			// Get column number j from row number i and
			// chain length L
			int j = i+L-1;
			cost[i][j] = INT_MAX;
			int off_set_sum = sum(freq, i, j);

			// Try making all keys in interval keys[i..j] as root
			for (int r = i; r <= j; r++)
			{
			// c = cost when keys[r] becomes root of this subtree
			int c = ((r > i)? cost[i][r-1]:0) +
					((r < j)? cost[r+1][j]:0) +
					off_set_sum;
			if (c < cost[i][j])
				cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}

// A utility function to get sum of array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}


int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
	return 0;
}

/*

The optimalSearchTree function is defined to calculate the minimum cost of constructing an optimal binary search tree.

Inside the optimalSearchTree function:

An array cost of size (n x n) is created to store the minimum cost of constructing a BST for different ranges of keys.
The base case is handled where cost[i][i] is set to the frequency of the key at index i.
The program iterates through chains of keys of increasing length (L), starting from 2 and going up to n.

For each chain length and starting position (i), the program calculates the minimum cost for constructing a BST with keys in the range [i, i+L-1].

To calculate this cost, the program considers each key in the range [i, i+L-1] as a potential root and recursively calculates the cost for the left and right subtrees.

The minimum cost for each possibility is stored in the cost[i][j] table.

After processing all chain lengths and starting positions, the minimum cost of constructing an optimal BST for the entire set of keys is stored in cost[0][n-1].

The sum function is used to calculate the sum of frequencies of keys in a given range (i to j).

*/



