/*
Given a grid of m x n, find the number of unique paths to reach the bottom-right corner from the top-left corner.

Input:
Enter the number of rows in the grid: 3
Enter the number of columns in the grid: 3

Output:
Number of unique paths from top-left to bottom-right: 6

*/


#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of unique paths in a grid
int uniquePaths(int m, int n) {
    // Create a 2D vector to represent the grid
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case: there is only one way to reach any cell in the first row or first column,
    // so initialize the first row and first column to 1
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }

    // Fill the rest of the grid using dynamic programming
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // The number of unique paths to reach a cell (i, j) is the sum of the paths
            // from the cell above (i-1, j) and the cell to the left (i, j-1).
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The result is stored in the bottom-right corner of the grid
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter the number of rows in the grid: ";
    cin >> m;
    cout << "Enter the number of columns in the grid: ";
    cin >> n;

    // Call the uniquePaths function to find the number of unique paths
    int paths = uniquePaths(m, n);

    // Output the result
    cout << "Number of unique paths from top-left to bottom-right: " << paths << endl;

    return 0;
}

/*
The program uses dynamic programming to find the number of unique paths to reach the bottom-right corner from the
top-left corner in a grid of size m x n. The main function uniquePaths takes the dimensions of the grid, m and n, as
input and returns the number of unique paths.

To solve this problem, we create a 2D vector dp to represent the grid. We set the base case for the first row and the
first column to 1 since there is only one way to reach any cell in the first row or first column.
Then, we fill the rest of the grid using dynamic programming. The number of unique paths to reach a cell (i, j) is the sum
of the paths from the cell above (i-1, j) and the cell to the left (i, j-1). Finally, the result is stored in the bottom-right
corner of the grid.

*/




