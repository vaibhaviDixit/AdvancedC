/*
Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum sum of a rectangle in a given matrix.
    int Kadane(vector<int>& arr) {
        int max_Sum = INT_MIN; // Initialize the maximum sum to a very small value.
        int presum = 0; // Initialize a variable to store the prefix sum.

        // Iterate through the array to find the maximum sum using the Kadane's algorithm.
        for (int i = 0; i < arr.size(); i++) {
            presum += arr[i]; // Calculate the current prefix sum.

            if (presum > max_Sum) {
                max_Sum = presum; // Update the maximum sum if the current sum is greater.
            }

            if (presum < 0) {
                presum = 0; // If the current sum becomes negative, reset it to zero.
            }
        }

        return max_Sum; // Return the maximum sum found using Kadane's algorithm.
    }

    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0)); // Create a 2D DP vector to store prefix sums for each row.

        // Calculate the prefix sums for each row of the input matrix.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (j == 0) {
                    dp[i][j] = M[i][j]; // The first element in each row is the same as the original matrix.
                } else {
                    dp[i][j] = dp[i][j - 1] + M[i][j]; // Calculate the prefix sum by adding the current element with the previous prefix sum.
                }
            }
        }

        vector<int> temp(R, 0); // Create a 1D vector to store the sums of rows between columns left and right.
        int ans = INT_MIN; // Initialize the final answer to a very small value.

        // Iterate through all possible left and right columns.
        for (int left = 0; left < C; left++) {
            for (int right = left; right < C; right++) {
                // Calculate the sum of each row between the left and right columns and store them in the temp array.
                for (int i = 0; i < R; i++) {
                    if (left == 0) {
                        temp[i] = dp[i][right]; // If the left column is the first column, the sum is the same as the prefix sum of the right column.
                    } else {
                        temp[i] = dp[i][right] - dp[i][left - 1]; // Otherwise, subtract the prefix sum of the left column to get the sum between left and right columns.
                    }
                }

                // Find the maximum sum subarray in the temp array using the Kadane's algorithm and update the final answer.
                ans = max(ans, Kadane(temp));
            }
        }

        return ans; // Return the maximum sum of a rectangle in the given matrix.
    }
};

int main() {
    int N, M;
    cin >> N >> M; // Input the dimensions of the matrix.

    vector<vector<int>> v(N, vector<int>(M)); // Create a 2D vector to store the matrix elements.

    // Input the elements of the matrix.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    Solution ob; // Create an object of the Solution class.

    // Call the maximumSumRectangle function to find the maximum sum of a rectangle in the matrix.
    cout << ob.maximumSumRectangle(N, M, v) << "\n"; // Output the result.

    return 0;
}

/*
The Kadane function implements the Kadane's algorithm to find the maximum sum of a subarray in a given vector.
The maximumSumRectangle function takes three parameters: R (number of rows in the matrix), C (number of columns in the matrix), and M (the 2D vector representing the matrix).
The function calculates prefix sums for each row of the matrix using a 2D DP vector dp.
It then iterates through all possible combinations of left and right columns and calculates the sum of each row between them.
The sum of each row between left and right columns is stored in the temp vector.
The function calls the Kadane function to find the maximum sum of a subarray in the temp vector, which corresponds to the maximum sum of a rectangle with the given left and right columns.
The function updates the final answer (ans) to the maximum sum found using Kadane's algorithm for all possible rectangles in the matrix.
In the main function, the user is prompted to enter the dimensions of the matrix (N and M).
A 2D vector v of size N x M is declared to store the elements of the matrix.
The elements of the matrix are input from the user using nested loops.
An object of the Solution class is created (named ob).
The maximumSumRectangle function is called on the object ob, passing the dimensions of the matrix and the 2D vector v.
The maximum sum of a rectangle in the matrix is printed on the console.

*/

