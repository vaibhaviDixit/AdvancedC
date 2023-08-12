/*
Given a 2D grid of '1's (land) and '0's (water), count the number of islands.

Input:
{'1', '1', '0', '0', '0'}
{'1', '1', '0', '0', '0'}
{'0', '0', '1', '0', '0'}
{'0', '0', '0', '1', '1'}

Output: Number of islands: 3

*/

#include <iostream>
#include <vector>

using namespace std;

// Helper function to perform depth-first search (DFS) to mark islands
void markIsland(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
    // Base cases for out-of-bound coordinates or water ('0')
    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
        return;
    }

    // Mark the current cell as visited (change '1' to '0')
    grid[row][col] = '0';

    // Perform DFS on neighboring cells
    markIsland(grid, row - 1, col, rows, cols); // Up
    markIsland(grid, row + 1, col, rows, cols); // Down
    markIsland(grid, row, col - 1, rows, cols); // Left
    markIsland(grid, row, col + 1, rows, cols); // Right
}

// Function to count the number of islands in the 2D grid
int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();

    int islandCount = 0;

    // Traverse the grid and for every '1' found (land), mark the island and its neighbors
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1') {
                islandCount++;
                markIsland(grid, i, j, rows, cols);
            }
        }
    }

    return islandCount;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int islands = numIslands(grid);
    cout << "Number of islands: " << islands << endl;

    return 0;
}


/*
The given program counts the number of islands in a 2D grid where '1' represents land and '0' represents water.
An island is a group of adjacent land cells, either horizontally or vertically, forming a connected component.

The markIsland function is a helper function that performs a depth-first search (DFS) to mark an island and all its
neighboring land cells as visited by changing the '1's to '0's.

The numIslands function is the main function that counts the number of islands in the grid. It iterates through every
cell in the grid, and when it finds an unmarked land cell ('1'), it increments the island count and calls the markIsland
function to mark the entire island and its neighbors.

*/





