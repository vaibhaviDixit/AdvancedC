/*
Rotate a given matrix 90 degrees clockwise.

Input:
{1, 2, 3, 4}
{5, 6, 7, 8}
{9, 10, 11, 12}
{13, 14, 15, 16}

Output:
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4

*/

#include <iostream>
#include <vector>

// Function to recursively rotate the matrix 90 degrees clockwise
void rotateMatrixRecursive(std::vector<std::vector<int>>& matrix, int n, int layer) {
    if (layer >= n / 2) {
        return; // Base case: All layers rotated
    }

    for (int i = layer; i < n - layer - 1; ++i) {
        int temp = matrix[layer][i];
        matrix[layer][i] = matrix[n - i - 1][layer];
        matrix[n - i - 1][layer] = matrix[n - layer - 1][n - i - 1];
        matrix[n - layer - 1][n - i - 1] = matrix[i][n - layer - 1];
        matrix[i][n - layer - 1] = temp;
    }

    rotateMatrixRecursive(matrix, n, layer + 1);
}

int main() {
    // Example matrix (4x4)
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int n = matrix.size(); // Assuming a square matrix
    rotateMatrixRecursive(matrix, n, 0);

    // Print the rotated matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


/*
This program rotates a given matrix 90 degrees clockwise using recursion. It iterates through the matrix and places the elements in the
rotated matrix accordingly.

*/


