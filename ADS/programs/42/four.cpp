/*
Given a grid of size m * n, let us assume you are starting at (1, 1) and your goal is to reach (m, n). At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space are marked as 1 and 0 respectively in the grid.

Input: [[0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]]
Output : 2

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int path(vector<vector<int> >& dp,
		vector<vector<int> >& grid, int i, int j)
{
	if (i < n && j < m && grid[i][j] == 1)
		return 0;
	if (i == n - 1 && j == m - 1)
		return 1;
	if (i >= n || j >= m)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int left = path(dp, grid, i + 1, j);
	int right = path(dp, grid, i, j + 1);
	return dp[i][j] = left + right;
}
int uniquePathsWithObstacles(vector<vector<int> >& grid)
{
	n = grid.size();
	m = grid[0].size();
	if (n == 1 && m == 1 && grid[0][0] == 0)
		return 1;
	if (n == 1 && m == 1 && grid[0][0] == 1)
		return 0;
	vector<vector<int> > dp(n, vector<int>(m, -1));

	path(dp, grid, 0, 0);

	if (dp[0][0] == -1)
		return 0;
	return dp[0][0];
}

signed main()
{
	vector<vector<int> > v{ { 0, 0, 0 },
							{ 0, 1, 0 },
							{ 0, 0, 0 } };
	cout << uniquePathsWithObstacles(v) << " \n";
	return 0;
}

/*

Headers and Definitions:

The program includes the necessary header file #include <bits/stdc++.h> and defines the int data type as long long.
The program uses the std namespace.
Global Variables:

Two global variables, n and m, represent the dimensions of the grid.
Recursive Function path:

This function recursively calculates the number of unique paths from cell (i, j) to the bottom-right corner.
If i and j are within the grid and the cell is not an obstacle (denoted by a value of 1), the function returns 0 (no path can be taken from an obstacle cell).
If (i, j) is the bottom-right corner, the function returns 1 (a path has been found).
If i or j goes beyond the grid's boundaries, the function returns 0.
The function uses memoization by checking if the result for the current cell (i, j) is already calculated and stored in the dp array. If yes, it returns the stored result.
Otherwise, it recursively calculates the number of paths by considering the paths going downward (i + 1, j) and rightward (i, j + 1), and stores the result in the dp array before returning it.
Function uniquePathsWithObstacles:

This function takes a 2D vector grid as input, where grid[i][j] represents whether cell (i, j) is an obstacle (1) or not (0).
It calculates the dimensions of the grid n and m.
It handles the special cases when the grid has only one cell and that cell is either an obstacle or not.
It initializes a 2D vector dp of size n x m to store the results of subproblems and fills it with -1 values.
The path function is called to calculate the number of unique paths, starting from the top-left corner (0, 0).
Main Function:

The main function initializes a 2D vector v representing the grid with obstacle information.
It calls the uniquePathsWithObstacles function with the grid and prints the result.

*/


