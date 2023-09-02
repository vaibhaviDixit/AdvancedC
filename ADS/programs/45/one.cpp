/*
There are ‘p’ balls of type P, ‘q’ balls of type Q and ‘r’ balls of type R. Using the balls we want to create a straight line such that no two balls of
same type are adjacent.

Input  : p = 1, q = 1, r = 0
Output : 2
There are only two arrangements PQ and QP

Input  : p = 1, q = 1, r = 1
Output : 6

Input  : p = 2, q = 1, r = 1
Output : 12

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

// Function to count the number of arrangements
int countUtil(int p, int q, int r)
{
	int dp[MAX][MAX][MAX];
	memset(dp, 0, sizeof(dp)); // Initializing the DP table with zeros

	// Base cases
	dp[1][0][0] = 1; // If only one 'p' is present
	dp[0][1][0] = 1; // If only one 'q' is present
	dp[0][0][1] = 1; // If only one 'r' is present

	// Fill the DP table
	for (int i = 0; i <= p; i++)
	{
		for (int j = 0; j <= q; j++)
		{
			for (int k = 0; k <= r; k++)
			{
				// Skip the base cases as they are already initialized
				if (i == 1 && j == 0 && k == 0)
					continue;
				if (i == 0 && j == 1 && k == 0)
					continue;
				if (i == 0 && j == 0 && k == 1)
					continue;

				// Update DP values based on previous states
				if (i - 1 >= 0)
					dp[i][j][k] += dp[i - 1][j][k]; // Add the count when using 'p'
				if (j - 1 >= 0)
					dp[i][j][k] += dp[i][j - 1][k]; // Add the count when using 'q'
				if (k - 1 >= 0)
					dp[i][j][k] += dp[i][j][k - 1]; // Add the count when using 'r'
			}
		}
	}

	return dp[p][q][r]; // Return the count of required arrangements
}

int main()
{
	int p = 2, q = 1, r = 1;
	cout<<countUtil(p, q, r);
	return 0;
}



