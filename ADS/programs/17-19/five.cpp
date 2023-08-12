/*
Given a 9x9 Sudoku board, determine if it is a valid Sudoku puzzle.

Input:
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

Output: Valid Sudoku.

*/

// Code for Sudoku Validity

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char num = board[row][col];

            if (num != '.') {
                // Check row
                if (rows[row].count(num) > 0)
                    return false;
                rows[row].insert(num);

                // Check column
                if (cols[col].count(num) > 0)
                    return false;
                cols[col].insert(num);

                // Check box
                int boxIndex = (row / 3) * 3 + col / 3;
                if (boxes[boxIndex].count(num) > 0)
                    return false;
                boxes[boxIndex].insert(num);
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board)) {
        cout << "Valid Sudoku.";
    } else {
        cout << "Invalid Sudoku.";
    }

    return 0;
}

/*
The Sudoku Validity program checks whether a given 9x9 Sudoku board is valid or not. It does this by maintaining three sets for each row,
column, and 3x3 box. For each cell, it checks if the number is already present in the corresponding row, column, and box.
If it is found in any of these sets, then the Sudoku is not valid. The isValidSudoku function iterates through the entire board while
keeping track of the numbers in each row, column, and box using unordered sets.

*/

