/*
Consider a matrix, where each cell contains either a ‘0’ or a ‘1’, and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are also connected, they form a region. find the size of the largest region.

Input: M[][5] = { {0, 0, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 1}}
Output: 6

Input: M[][5] = { {0, 0, 1, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0 1} }
Output: 4

*/

// C++ Program to find the length of the largest region in boolean 2D-matrix
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

// A function to check if
// a given cell (row, col)
// can be included in DFS
int isSafe(int M[][COL], int row, int col,
		bool visited[][COL])
{
	// row number is in range,
	// column number is in
	// range and value is 1
	// and not yet visited
	return (row >= 0) && (row < ROW) && (col >= 0)
		&& (col < COL)
		&& (M[row][col] && !visited[row][col]);
}

// A utility function to
// do DFS for a 2D boolean
// matrix. It only considers
// the 8 neighbours as
// adjacent vertices
void DFS(int M[][COL], int row, int col,
		bool visited[][COL], int& count)
{
	// These arrays are used
	// to get row and column
	// numbers of 8 neighbours
	// of a given cell
	static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	// Mark this cell as visited
	visited[row][col] = true;

	// Recur for all connected neighbours
	for (int k = 0; k < 8; ++k) {
		if (isSafe(M, row + rowNbr[k], col + colNbr[k],
				visited)) {
			// Increment region length by one
			count++;
			DFS(M, row + rowNbr[k], col + colNbr[k],
				visited, count);
		}
	}
}

// The main function that returns
// largest length region
// of a given boolean 2D matrix
int largestRegion(int M[][COL])
{
	// Make a bool array to mark visited cells.
	// Initially all cells are unvisited
	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));

	// Initialize result as 0 and travesle through the
	// all cells of given matrix
	int result = INT_MIN;
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			// If a cell with value 1 is not
			if (M[i][j] && !visited[i][j]) {
				// visited yet, then new region found
				int count = 1;
				DFS(M, i, j, visited, count);

				// maximum region
				result = max(result, count);
			}
		}
	}
	return result;
}

int main()
{
	int M[][COL] = { { 0, 0, 1, 1, 0 },
					{ 1, 0, 1, 1, 0 },
					{ 0, 1, 0, 0, 0 },
					{ 0, 0, 0, 0, 1 } };

	// Function call
	cout << largestRegion(M);

	return 0;
}

/*
Constants ROW and COL are defined to specify the dimensions of the boolean 2D matrix.

The isSafe function is used to check whether a given cell is valid and can be included in the Depth-First Search (DFS). It ensures that the row and column indices are within bounds and that the cell is not already visited.

The DFS function performs a Depth-First Search starting from a given cell in the matrix. It explores all the connected neighbors (up, down, left, right, and diagonals) of the current cell and marks them as visited.

The largestRegion function is the core of the algorithm. It initializes a boolean array visited to keep track of visited cells. It then iterates through all cells of the matrix and, if an unvisited cell with a value of 1 is found, it initiates a DFS to count the size of the region.

The main for loop iterates through all cells of the matrix, and for each unvisited cell with a value of 1, it initiates a DFS to count the size of the region. It also keeps track of the maximum region size encountered.

The main function:

a. Initializes a sample boolean 2D matrix M.

b. Calls the largestRegion function to find the length of the largest region in the matrix.

c. Prints the result.

*/


