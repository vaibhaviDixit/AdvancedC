/*
Given a maze with obstacles, find a path for a rat to reach its destination from the top-left cell to the bottom-right cell.

Input:
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}

Output:
Path exists. Solution:
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1

*/


// Code for Rat in a Maze

#include <iostream>
#include <vector>

using namespace std;

const int N = 4; // Size of the maze

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, vector<vector<int>>& path) {
    if (x == N - 1 && y == N - 1) {
        path[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        path[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, path))
            return true;

        if (solveMazeUtil(maze, x, y + 1, path))
            return true;

        path[x][y] = 0; // Backtrack if no valid path found
    }

    return false;
}

void printSolution(const vector<vector<int>>& path) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

void solveMaze(int maze[N][N]) {
    vector<vector<int>> path(N, vector<int>(N, 0));

    if (solveMazeUtil(maze, 0, 0, path)) {
        cout << "Path exists. Solution:\n";
        printSolution(path);
    } else {
        cout << "No path exists.";
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}

/*
The Rat in a Maze program uses backtracking recursion to find a path from the top-left cell to the bottom-right cell in a given maze.
The maze is represented as a 2D array with obstacles (0's) and available paths (1's). The isSafe function checks if a cell is a valid path
to move. The solveMazeUtil function is called recursively to explore all possible paths from the current cell to the destination.
If a valid path is found, the function returns true, and the final path is printed using the printSolution function.
If no valid path is found, the function returns false.

*/


