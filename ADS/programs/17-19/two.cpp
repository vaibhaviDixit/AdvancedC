/*
 Given a partially filled 9×9 Sudoku grid, solve the puzzle and fill the empty cells.

Input:
Enter the Sudoku grid (0 for empty cells):
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Output:
Sudoku Solved:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

*/


#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

bool findUnassignedLocation(vector<vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafeInRow(vector<vector<int>>& grid, int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

bool isSafeInColumn(vector<vector<int>>& grid, int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

bool isSafeInBox(vector<vector<int>>& grid, int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return false;
        }
    }
    return true;
}

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    return isSafeInRow(grid, row, num) &&
           isSafeInColumn(grid, col, num) &&
           isSafeInBox(grid, row - row % 3, col - col % 3, num);
}

bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    if (!findUnassignedLocation(grid, row, col))
        return true; // Sudoku solved successfully

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; // Unassign if the current choice didn't lead to a solution
        }
    }

    return false; // Backtrack
}

void printGrid(const vector<vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N));
    cout << "Enter the Sudoku grid (0 for empty cells):\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Sudoku Solved:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists.";
    }

    return 0;
}

/*
The Sudoku Solver program uses a backtracking algorithm to solve a given partially filled 9x9 Sudoku grid.
The solveSudoku function recursively explores all possible placements of numbers in empty cells, ensuring that the same number is not
repeated in the same row, column, or 3x3 box. The program prints the solved Sudoku grid if a solution exists; otherwise,
it displays a message indicating that no solution is possible.

*/


