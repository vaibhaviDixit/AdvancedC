/*
Given two strings 'X' and 'Y', find the length of the Longest Common Subsequence (LCS) between them.
The LCS is a subsequence that appears in the same relative order in both strings but not necessarily consecutively.

Input:
X = "AGGTAB"
Y = "GXTXAYB"
Output:
Longest common subsequence length: 4 (LCS is "GTAB")

*/

#include <stdio.h>
#include <string.h>

// LCS Algorithm
// This function takes two strings 'X' and 'Y', and their lengths 'm' and 'n' as input.
// It finds the length of the Longest Common Subsequence (LCS) of 'X' and 'Y' using dynamic programming.
// The function returns the length of the LCS.
int lcs(char X[], char Y[], int m, int n) {
    // Create a 2D array to store the LCS lengths for substrings of 'X' and 'Y'
    int L[m + 1][n + 1];

    // Calculate the LCS lengths using dynamic programming
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    return L[m][n];
}

int main() {
    // Sample strings
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    // Calculate the lengths of the strings
    int m = strlen(X);
    int n = strlen(Y);

    // Call the lcs function to find the length of the Longest Common Subsequence (LCS)
    int longest_common_subseq = lcs(X, Y, m, n);

    // Print the length of the LCS
    printf("Longest common subsequence length: %d", longest_common_subseq);

    return 0;
}

/*
The program implements the Longest Common Subsequence (LCS) Algorithm to find the length of the LCS between two given strings 'X' and 'Y'.
The LCS is a subsequence that appears in the same relative order in both strings, but not necessarily consecutively.
The algorithm uses dynamic programming to calculate the LCS lengths for all possible substrings of 'X' and 'Y'.
It creates a 2D array 'L' to store the LCS lengths, where 'L[i][j]' represents the LCS length for the substring 'X[0...i-1]' and 'Y[0...j-1]'.
The function iterates through all substrings of 'X' and 'Y', filling in the 'L' array based on the LCS lengths of the smaller substrings.
The LCS length for 'X' and 'Y' is stored in 'L[m][n]', where 'm' and 'n' are the lengths of 'X' and 'Y', respectively.

*/


