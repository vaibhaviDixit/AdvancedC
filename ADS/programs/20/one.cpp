/*
Given a sorted matrix, determine if a target element exists in the matrix.

Input: matrix= {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}
target=5
Output: Element 5 found in the matrix.

*/

#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][3], int target, int row, int col) {
    if (row < 0 || col >= 3) {
        return false;
    }
    if (matrix[row][col] == target) {
        return true;
    }
    if (matrix[row][col] < target) {
        return searchMatrix(matrix, target, row, col + 1);
    }
    return searchMatrix(matrix, target, row - 1, col);
}

int main() {
    int matrix[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int rows = 3, cols = 3;
    int target = 5;
    bool found = searchMatrix(matrix, target, rows - 1, 0);
    if (found) {
        cout << "Element " << target << " found in the matrix." << endl;
    } else {
        cout << "Element " << target << " not found in the matrix." << endl;
    }
    return 0;
}

/*
This program uses recursion to search for a target element in a sorted matrix. It starts from the top-right corner and narrows down the search
based on the comparison of the current element with the target.

*/



