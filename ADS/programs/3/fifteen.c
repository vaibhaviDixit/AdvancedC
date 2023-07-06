/*
Given a 2D matrix where each row is sorted in ascending order and the next row's first element is greater than the
previous row's last element, the task is to determine if a target element exists in the matrix.

Input: { {1, 3, 5, 7}
        {10, 11, 16, 20}
        {23, 30, 34, 60} }
       target=16
Output: Target element 16 exists in the matrix.

*/

#include <stdio.h>
#include <stdbool.h>
#define COLS 4

bool searchMatrix(int matrix[][COLS], int rows, int cols, int target) {
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true;  // Element found
        } else if (matrix[row][col] > target) {
            col--;  // Move left in the current row
        } else {
            row++;  // Move down to the next row
        }
    }

    return false;  // Element not found
}

int main() {
    int matrix[][COLS] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    int target = 16;

    bool exists = searchMatrix(matrix, rows, cols, target);

    if (exists) {
        printf("Target element %d exists in the matrix.\n", target);
    } else {
        printf("Target element %d does not exist in the matrix.\n", target);
    }

    return 0;
}

/*
The program defines a function searchMatrix that takes the 2D matrix, the number of rows, the number of columns,
and the target element as inputs. It uses a two-pointer approach to traverse the matrix. Starting from the top-right corner,
the row and column indices are updated based on a comparison with the target element. If the element is found, the function
returns true; otherwise, it continues the search until it exhausts all rows and columns. If the element is not found, the
function returns false. In the main function, a sample matrix is defined, along with the target element.
The searchMatrix function is called with the
appropriate arguments, and the result is printed based on the return value.
*/
