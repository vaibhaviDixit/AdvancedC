/*
 Given an m x n matrix of non-negative integers representing the height of each unit cell, determine the list of grid
 coordinates where water can flow to both the Pacific and Atlantic oceans.

 Input:
 {1, 2, 2, 3, 5},
 {3, 2, 3, 4, 4},
 {2, 4, 5, 3, 1},
 {6, 7, 1, 4, 5},
 {5, 1, 1, 2, 4}

 Output:
 List of grid coordinates where water can flow to both the Pacific and Atlantic oceans:
(0, 4) (1, 3) (1, 4) (2, 2) (3, 0) (3, 1) (4, 0)

*/

#include <iostream>
#include <vector>

using namespace std;

// Helper function to perform DFS to find the reachable cells from a given cell
void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int row, int col) {
    // Mark the cell as visited
    visited[row][col] = true;

    int m = matrix.size();
    int n = matrix[0].size();

    // Define the possible directions to move (up, down, left, right)
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Perform DFS in all four directions
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        // Check if the new cell is within bounds and has a higher or equal height
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol] && matrix[newRow][newCol] >= matrix[row][col]) {
            dfs(matrix, visited, newRow, newCol);
        }
    }
}

// Function to find the list of grid coordinates where water can flow to both the Pacific and Atlantic oceans
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> result;

    if (matrix.empty() || matrix[0].empty()) {
        return result;
    }

    int m = matrix.size();
    int n = matrix[0].size();

    // Create two 2D vectors to keep track of visited cells for each ocean
    vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
    vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));

    // Perform DFS for each row on the left (Pacific) and right (Atlantic) borders
    for (int i = 0; i < m; i++) {
        dfs(matrix, pacificVisited, i, 0);
        dfs(matrix, atlanticVisited, i, n - 1);
    }

    // Perform DFS for each column on the top (Pacific) and bottom (Atlantic) borders
    for (int i = 0; i < n; i++) {
        dfs(matrix, pacificVisited, 0, i);
        dfs(matrix, atlanticVisited, m - 1, i);
    }

    // Find the cells that can flow to both the Pacific and Atlantic oceans
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                result.push_back({i, j});
            }
        }
    }

    return result;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    // Find the list of grid coordinates where water can flow to both oceans
    vector<vector<int>> result = pacificAtlantic(matrix);

    // Print the result
    cout << "List of grid coordinates where water can flow to both the Pacific and Atlantic oceans:\n";
    for (const auto& coord : result) {
        cout << "(" << coord[0] << ", " << coord[1] << ") ";
    }

    return 0;
}

/*
The given C++ program implements the Pacific Atlantic Water Flow problem using Depth-First Search (DFS) to determine the
list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

The pacificAtlantic function takes a 2D matrix representing the heights of each unit cell as input and returns a vector
of vectors containing the coordinates where water can flow to both oceans. It creates two 2D vectors (pacificVisited and
atlanticVisited) to keep track of visited cells for each ocean. It performs DFS for each row on the left (Pacific) and
right (Atlantic) borders, and for each column on the top (Pacific) and bottom (Atlantic) borders to mark the cells that
are reachable from each ocean. Finally, it finds the cells that can be reached from both oceans and stores their coordinates
in the result vector. The result is then printed to the console.

*/



