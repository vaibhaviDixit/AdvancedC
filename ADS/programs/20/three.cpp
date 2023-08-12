/*
Find the transpose of a given matrix.

Input:
Original Matrix:
1 2 3
4 5 6
7 8 9

Output:
Transpose Matrix:
1 4 7
2 5 8
3 6 9

*/

#include <iostream>
#include <vector>

// Function to recursively find the transpose of the matrix
void transposeMatrixRecursive(const std::vector<std::vector<int>>& matrix,
                              std::vector<std::vector<int>>& transpose,
                              int row, int col) {
    // Base case: If row and col are out of bounds, return
    if (row == matrix.size()) {
        return;
    }

    // Store the element in the transpose matrix
    transpose[col][row] = matrix[row][col];

    // Move to the next row and column
    if (col == matrix[0].size() - 1) {
        transposeMatrixRecursive(matrix, transpose, row + 1, 0);
    } else {
        transposeMatrixRecursive(matrix, transpose, row, col + 1);
    }
}

int main() {
    // Example matrix (3x3)
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Create a matrix to store the transpose
    std::vector<std::vector<int>> transpose(cols, std::vector<int>(rows, 0));

    // Find the transpose of the matrix using recursion
    transposeMatrixRecursive(matrix, transpose, 0, 0);

    // Display the transpose matrix
    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nTranspose Matrix:" << std::endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << transpose[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


/*
This program finds the transpose of a given matrix using recursion. It iterates through the matrix and swaps the rows and columns to construct
the transposed matrix.

*/



