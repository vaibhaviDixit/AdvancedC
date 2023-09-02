/*
A stable tower of height n is a tower consisting of exactly n tiles of unit height stacked vertically in such a way,
that no bigger tile is placed on a smaller tile.

Input : n = 3, m = 3, k = 1.
Output : 1
Possible sequences: { 1, 2, 3}.
Hence answer is 1.

Input : n = 3, m = 3, k = 2.
Output : 7

*/


// CPP program to find number of ways to make stable tower of given height.
#include <bits/stdc++.h>
using namespace std;
#define N 100

int possibleWays(int n, int m, int k)
{
	int dp[N][N];
	int presum[N][N];
	memset(dp, 0, sizeof dp);
	memset(presum, 0, sizeof presum);

	// Initializing 0th row to 0.
	for (int i = 1; i < n + 1; i++) {
		dp[0][i] = 0;
		presum[0][i] = 1;
	}

	// Initializing 0th column to 0.
	for (int i = 0; i < m + 1; i++)
		presum[i][0] = dp[i][0] = 1;

	// For each row from 1 to m
	for (int i = 1; i < m + 1; i++) {

		// For each column from 1 to n.
		for (int j = 1; j < n + 1; j++) {

			// Initializing dp[i][j] to presum of (i - 1, j).
			dp[i][j] = presum[i - 1][j];
			if (j > k) {
				dp[i][j] -= presum[i - 1][j - k - 1];
			}
		}

		// Calculating presum for each i, 1 <= i <= n.
		for (int j = 1; j < n + 1; j++)
			presum[i][j] = dp[i][j] + presum[i][j - 1];
	}

	return dp[m][n];
}

int main()
{
	int n = 3, m = 3, k = 2;
	cout << possibleWays(n, m, k) << endl;
	return 0;
}

/*
Function possibleWays:

This function takes three input parameters: n (height of the tower), m (number of available blocks), and k (maximum consecutive blocks that can be placed).
It calculates and returns the number of ways to construct a stable tower with the given height and constraints using the available blocks.
The function initializes two 2D arrays dp and presum to store dynamic programming results and prefix sums.
It iterates over rows and columns of the arrays to calculate the number of ways to build the tower using dynamic programming.
The base cases initialize the 0th row and 0th column to 0 or 1, depending on the situation.
For each cell (i, j), the value is calculated based on the previous rows' presum values. The value is adjusted by subtracting the presum from a certain position to account for the constraint k.
The presum array is updated to store prefix sums for each row.
The final result is stored in dp[m][n].
Main Function:

The main function initializes three integers n, m, and k representing the height of the tower, the number of blocks, and the constraint k.
It calls the possibleWays function with these values and prints the result.

*/

