/*
Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons.
Initially, the miner is in the first column but can be in any row. He can move only (right->,right up /,right down\) that is from a given cell,
the miner can move to the cell diagonally up towards the right or diagonally down towards the right. Find out the maximum amount of gold he can
collect.

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12
{(1,0)->(2,1)->(1,2)}

Input: mat[][] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
Output : 16

*/

// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Returns maximum amount of gold that can be collected when journey started from first column and moves
// allowed are right, right-up and right-down
int getMaxGold(int gold[][MAX], int m, int n)
{
	// Create a table for storing intermediate results and initialize all cells to 0. The first row of
	// goldMineTable gives the maximum gold that the miner can collect when starts that row
	int goldTable[m][n];
	memset(goldTable, 0, sizeof(goldTable));

	for (int col=n-1; col>=0; col--)
	{
		for (int row=0; row<m; row++)
		{
			// Gold collected on going to the cell on the right(->)
			int right = (col==n-1)? 0: goldTable[row][col+1];

			// Gold collected on going to the cell to right up (/)
			int right_up = (row==0 || col==n-1)? 0:
							goldTable[row-1][col+1];

			// Gold collected on going to the cell to right down (\)
			int right_down = (row==m-1 || col==n-1)? 0:
							goldTable[row+1][col+1];

			// Max gold collected from taking either of the
			// above 3 paths
			goldTable[row][col] = gold[row][col] +
							max(right, max(right_up, right_down));

		}
	}

	// The max amount of gold collected will be the max
	// value in first column of all rows
	int res = goldTable[0][0];
	for (int i=1; i<m; i++)
		res = max(res, goldTable[i][0]);
	return res;
}


int main()
{
	int gold[MAX][MAX]= { {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, m, n);
	return 0;
}

/*
The getMaxGold function is defined to calculate the maximum amount of gold that can be collected by a miner. It uses dynamic programming and stores intermediate results in the goldTable.

Inside the getMaxGold function:

An array goldTable of size (m x n) is created to store the maximum gold that can be collected when starting from different cells in the grid. It is initialized with all cells set to 0.

A loop runs from the rightmost column (col=n-1) to the leftmost column (col=0).

For each cell in the grid, the program calculates the maximum gold that can be collected by considering three possible directions: right (->), right-up (/), and right-down (). It takes the maximum of these three values and adds the current cell's gold value to it.

The result is stored in the goldTable for the current cell.

After calculating the goldTable, the program finds the maximum value in the first column (starting from the top row) and stores it in the variable res.


*/
