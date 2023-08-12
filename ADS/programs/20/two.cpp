/*
Count the number of paths from the top-left corner to the bottom-right corner of a matrix, moving only down and right.

Input: rows = 3, cols = 3
Output: Number of paths: 6

*/

#include <iostream>
using namespace std;

int countPaths(int rows, int cols) {
    if (rows == 1 || cols == 1) {
        return 1;
    }
    return countPaths(rows - 1, cols) + countPaths(rows, cols - 1);
}

int main() {
    int rows = 3, cols = 3;
    int paths = countPaths(rows, cols);
    cout << "Number of paths: " << paths << endl;
    return 0;
}

/*
This program counts the number of paths from the top-left corner to the bottom-right corner of a matrix using recursion.
It divides the problem into smaller subproblems by considering two possible moves: down or right.

*/
