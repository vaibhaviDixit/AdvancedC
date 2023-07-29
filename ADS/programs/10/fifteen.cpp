/*

Given two integer arrays A and B, find the maximum length of a subarray that appears in both arrays.

Input: A = {1, 2, 3, 2, 1}, B = {3, 2, 1, 4, 7}
Output: Maximum length of a common subarray: 3

*/

#include <iostream>
#include <vector>
using namespace std;

int findMaxLengthOfCommonSubarray(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();

    // Initialize the dp table with all elements set to zero
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;

    // Iterate through the arrays A and B
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Check if elements are equal
            if (A[i - 1] == B[j - 1]) {
                // Extend the common subarray
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
            // If elements are not equal, dp[i][j] remains zero
        }
    }

    return maxLength;
}

int main() {
    vector<int> A = {1, 2, 3, 2, 1};
    vector<int> B = {3, 2, 1, 4, 7};

    int maxLength = findMaxLengthOfCommonSubarray(A, B);
    cout << "Maximum length of a common subarray: " << maxLength << endl;

    return 0;
}

/*
To solve this problem, we can use dynamic programming. We will create a 2D table to store the lengths of the common subarrays of A and B. Let's call this table 'dp'. The dp[i][j] will represent the length of the longest common subarray ending at A[i-1] and B[j-1].

We will initialize the dp table with all elements set to zero. Then, we will iterate through the arrays A and B, and for each pair of elements (A[i] and B[j]), we will check if they are equal. If they are equal, it means we can extend the common subarray ending at A[i-1] and B[j-1], so we set dp[i][j] to dp[i-1][j-1] + 1. If they are not equal, dp[i][j] remains zero, as there is no common subarray that ends at A[i-1] and B[j-1].

The answer to the problem will be the maximum value in the dp table.

*/


