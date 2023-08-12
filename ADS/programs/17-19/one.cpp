/*
Given a chessboard of size N×N, place N queens on the board such that no two queens attack each other.

Input: Enter the size of the chessboard (N): 4
Output:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

*/

// Code for N-Queens Problem

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N)
{
    if (row == N)
    {
        // Print the solution or store it as required
        return true;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1, N))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0, N))
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.";
    }
}

int main()
{
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;

    solveNQueens(N);

    return 0;
}

/*
The N-Queens problem is a classic example of a backtracking algorithm. It involves placing N queens on an N×N chessboard so that no
two queens attack each other. The isSafe function checks whether it's safe to place a queen in a particular cell, considering the current
state of the board. The solveNQueensUtil function uses recursion to explore all possible placements, and if a valid solution is found,
it is printed or stored accordingly.

*/


