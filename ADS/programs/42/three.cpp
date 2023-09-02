/*
The problem is to count all unique possible paths from the top left to the bottom right of a M X N matrix with the constraints that from each
cell you can either move only to the right or down

Input:  M = 2, N = 2
Output: 2
Explanation: There are two paths
(0, 0) -> (0, 1) -> (1, 1)
(0, 0) -> (1, 0) -> (1, 1)

Input:  M = 2, N = 3
Output: 3

*/


// A C++ program to count all possible paths from top left to bottom right
#include <bits/stdc++.h>
using namespace std;

// Returns count of possible paths to reach cell at row number m and column number n from the topmost leftmost cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
	// Create a 2D table to store results of subproblems
	int count[m][n];

	// Count of paths to reach any cell in first column is 1
	for (int i = 0; i < m; i++)
		count[i][0] = 1;

	// Count of paths to reach any cell in first row is 1
	for (int j = 0; j < n; j++)
		count[0][j] = 1;

	// Calculate count of paths for other cells in bottom-up manner using the recursive solution
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++)

			// By uncommenting the last part the code calculates the total possible paths if the diagonal Movements are allowed
			count[i][j]
				= count[i - 1][j]
				+ count[i][j - 1]; //+ count[i-1][j-1];
	}
	return count[m - 1][n - 1];
}

int main()
{
	cout << numberOfPaths(2, 3);
	return 0;
}

/*
numberOfPaths Function:

This function takes two input parameters: m (number of rows) and n (number of columns) of the grid.
The function calculates and returns the count of possible paths to reach the cell at row m and column n from the top-left cell (cell at 1, 1).
It uses dynamic programming to solve the problem efficiently.
A 2D array count of size m x n is used to store the results of subproblems.
The base case is initialized: the count of paths to reach any cell in the first column or first row is set to 1, as there's only one way to move to cells along the boundary.
The function iterates through the remaining cells in a bottom-up manner and calculates the count of paths to each cell.
The count of paths to the current cell (i, j) is the sum of the counts of paths from the cell above (i-1, j) and the cell to the left (i, j-1).
The commented code (+ count[i-1][j-1]) in the inner loop calculates the total possible paths if diagonal movements are allowed along with right and downward movements.
After iterating through all cells, the function returns the count of paths to the bottom-right cell (m-1, n-1).
Main Function:

The main function calls the numberOfPaths function with m = 2 (number of rows) and n = 3 (number of columns).
It prints the result, which represents the number of possible paths to reach the bottom-right cell from the top-left cell.

*/

