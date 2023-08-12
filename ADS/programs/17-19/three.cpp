/*
Given a 2D board and a word, find if the word exists in the grid. The word can be constructed from adjacent characters
(vertically or horizontally) in the grid.

Input:
 board= {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}

Enter the word to search: BCE
Output: Word found in the board.

*/

// Code for Word Search

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int& index, const string& word) {
    return (row >= 0 && row < board.size() &&
            col >= 0 && col < board[0].size() &&
            board[row][col] == word[index]);
}

bool searchWord(vector<vector<char>>& board, int row, int col, int index, const string& word) {
    if (index == word.length())
        return true;

    if (!isSafe(board, row, col, index, word))
        return false;

    char temp = board[row][col];
    board[row][col] = '#'; // Mark cell as visited

    // Explore all 4 directions
    bool found = searchWord(board, row + 1, col, index + 1, word) ||
                 searchWord(board, row - 1, col, index + 1, word) ||
                 searchWord(board, row, col + 1, index + 1, word) ||
                 searchWord(board, row, col - 1, index + 1, word);

    board[row][col] = temp; // Restore the original character

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (board[row][col] == word[0] && searchWord(board, row, col, 0, word))
                return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word;
    cout << "Enter the word to search: ";
    cin >> word;

    if (exist(board, word)) {
        cout << "Word found in the board.";
    } else {
        cout << "Word not found in the board.";
    }

    return 0;
}

/*
The Word Search program uses a backtracking algorithm to find a given word in a 2D board of characters.
It explores all possible paths in the board starting from each character that matches the first character of the word.
The searchWord function performs the recursive exploration while ensuring that each character of the word is found in adjacent positions
(horizontally or vertically) on the board.
The exist function searches for the word in the entire board and returns true if the word is found, and false otherwise.

*/



