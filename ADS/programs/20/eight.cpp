/*
 Find the number of connected components in a given matrix.

 Input:
  {1, 0, 1, 0}
  {1, 1, 0, 0}
  {0, 1, 1, 1}
  {0, 0, 1, 1}

 Output: Number of connected components: 2

*/


#include <iostream>
using namespace std;

const int N = 4;

// Function to perform the depth-first search
void dfs(int matrix[N][N], int row, int col, bool visited[N][N]) {
    if (row < 0 || row >= N || col < 0 || col >= N || matrix[row][col] == 0 || visited[row][col]) {
        return;
    }
    visited[row][col] = true;
    dfs(matrix, row + 1, col, visited);
    dfs(matrix, row - 1, col, visited);
    dfs(matrix, row, col + 1, visited);
    dfs(matrix, row, col - 1, visited);
}

// Function to find the number of connected components
int countConnectedComponents(int matrix[N][N]) {
    bool visited[N][N] = {false};
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                count++;
                dfs(matrix, i, j, visited);
            }
        }
    }
    return count;
}

int main() {
    int matrix[N][N] = {
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
    };
    int connectedComponents = countConnectedComponents(matrix);
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}

/*
This program finds the number of connected components in a given matrix. It performs depth-first search (DFS) starting from each unvisited
1 to find connected regions and counts them as separate components.

*/


