/*
 Find the maximum path sum in a matrix starting from the top-left corner and ending at the bottom-right corner.

 Input:
 {1, 2, 3}
 {4, 5, 6}
 {7, 8, 9}

 Output:
 Maximum Path Sum: 29


*/

#include <iostream>
using namespace std;

const int N = 3;

// Function to find the maximum path sum
int findMaxPathSum(int matrix[N][N], int row, int col) {
    if (row == N - 1 && col == N - 1) {
        return matrix[row][col];
    }
    if (row == N - 1) {
        return matrix[row][col] + findMaxPathSum(matrix, row, col + 1);
    }
    if (col == N - 1) {
        return matrix[row][col] + findMaxPathSum(matrix, row + 1, col);
    }
    int rightSum = matrix[row][col] + findMaxPathSum(matrix, row, col + 1);
    int downSum = matrix[row][col] + findMaxPathSum(matrix, row + 1, col);
    return max(rightSum, downSum);
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int maxPathSum = findMaxPathSum(matrix, 0, 0);
    cout << "Maximum Path Sum: " << maxPathSum << endl;
    return 0;
}

/*
This program finds the maximum path sum in a matrix starting from the top-left corner and ending at the bottom-right corner.
It uses recursion to explore all possible paths and returns the maximum sum.

*/

