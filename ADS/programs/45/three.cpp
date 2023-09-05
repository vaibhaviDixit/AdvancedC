/*
Given a cost matrix cost[][] and a position (M, N) in cost[][], write a function that returns cost of minimum cost path to reach (M, N) from
(0, 0). Each cell of the matrix represents a cost to traverse through that cell. The total cost of a path to reach (M, N) is the sum of all
the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell,
i.e., from a given cell (i, j), cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed.

Note: You may assume that all costs are positive integers.

Input:
1 2 3
4 8 2
1 5 3

m=2 n=2

Output: 8

*/


// A Dynamic Programming based solution for MCP problem
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int min(int x, int y, int z);

// Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]
int minCostMemoized(int cost[R][C], int m, int n,
					int memo[R][C])
{
	if (n < 0 || m < 0)
		return INT_MAX;
	else if (m == 0 && n == 0)
		return cost[m][n];

	if (memo[m][n] != -1)
		return memo[m][n];

	memo[m][n]
		= cost[m][n]
		+ min(minCostMemoized(cost, m - 1, n - 1, memo),
				minCostMemoized(cost, m - 1, n, memo),
				minCostMemoized(cost, m, n - 1, memo));

	return memo[m][n];
}

// Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]
int minCost(int cost[R][C], int m, int n)
{
	int memo[R][C];
	memset(memo, -1,
		sizeof(memo)); // Initialize memo table with -1

	return minCostMemoized(cost, m, n, memo);
}

// A utility function that returns minimum of 3 integers
int min(int x, int y, int z)
{
	if (x < y)
		return (x < z) ? x : z;
	else
		return (y < z) ? y : z;
}


int main()
{
	int cost[R][C]
		= { { 2, 2, 3 }, { 9, 8, 2 }, { 7, 5, 3 } };

	cout << minCost(cost, 1, 3) << endl;

	return 0;
}

/*
Macros: The code uses macros R and C to represent the number of rows and columns in the matrix, respectively.

The minCostMemoized Function: This function calculates the minimum cost path using a memoized dynamic programming approach.
It takes the matrix cost[][], current row m, current column n, and a memoization table memo[][] as input.

Base Cases: The function checks for base cases: if either m or n goes out of bounds (negative values) or if (m, n) reaches the top-left corner, in which case the cost at that cell is returned.

Memoization: The function checks if the value for the current cell (m, n) is already computed and stored in the memo table. If yes, it returns the memoized value.

Recursion with Memoization: If the value is not memoized, the function calculates the cost of the current cell by adding the value of the current cell in the cost matrix and the minimum cost of moving from three possible directions: left, up, and diagonal.

Storing in Memo Table: The calculated cost is stored in the memo table for the current cell (m, n).

The minCost Function: This function initializes the memo table with -1 using memset and then calls minCostMemoized with the provided arguments.

Utility Function: The min function is a utility function that returns the minimum of three integers.

*/

