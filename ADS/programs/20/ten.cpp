/*
Find the length of the longest increasing path in a given matrix.

Input:
{9, 9, 4}
{6, 6, 8}
{2, 1, 1}

Output:
Longest Increasing Path Length: 4

*/

#include <iostream>
#include <vector>
using namespace std;

const int N = 3;

int dfs(int matrix[N][N], int row, int col, vector<vector<int>>& cache) {
    if (cache[row][col] != -1) {
        return cache[row][col];
    }
    int longestPath = 1;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && matrix[newRow][newCol] > matrix[row][col]) {
            longestPath = max(longestPath, 1 + dfs(matrix, newRow, newCol, cache));
        }
    }
    cache[row][col] = longestPath;
    return longestPath;
}

int longestIncreasingPath(int matrix[N][N]) {
    vector<vector<int>> cache(N, vector<int>(N, -1));
    int maxPath = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxPath = max(maxPath, dfs(matrix, i, j, cache));
        }
    }
    return maxPath;
}

int main() {
    int matrix[N][N] = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1},
    };
    int result = longestIncreasingPath(matrix);
    cout << "Longest Increasing Path Length: " << result << endl;
    return 0;
}

/*
This program finds the length of the longest increasing path in a given matrix. It uses depth-first search (DFS) with memoization to
explore all possible paths from each cell and returns the maximum path length.

*/
