/*
Given two strings, S1 and S2, the task is to find the length of the Longest Common Subsequence, i.e. longest subsequence present in both of the strings.

A longest common subsequence (LCS) is defined as the longest subsequence which is common in all given input sequences.

Input: S1 = “AGGTAB”, S2 = “GXTXAYB”
Output: 4
Explanation: The longest subsequence which is present in both strings is “GTAB”.

Input: S1 = “BD”, S2 = “ABCD”
Output: 2

*/

// Dynamic Programming C++ implementation of LCS problem
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(string X, string Y, int m, int n)
{

	// Initializing a matrix of size (m+1)*(n+1)
	int L[m + 1][n + 1];

	// Following steps build L[m+1][n+1] in bottom up fashion. Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
	return L[m][n];
}

int main()
{
	string S1 = "AGGTAB";
	string S2 = "GXTXAYB";
	int m = S1.size();
	int n = S2.size();

	// Function call
	cout << "Length of LCS is " << lcs(S1, S2, m, n);

	return 0;
}

/*

The lcs Function: This function calculates the length of the longest common subsequence (LCS) between two strings, X and Y. It takes four parameters: two strings X and Y, and two integers m and n representing the lengths of the strings.

Matrix L: A 2D integer array L of size (m + 1) x (n + 1) is declared to store the lengths of LCS for various substrings of X and Y.

Base Cases: The matrix L is initialized in a bottom-up manner using two nested loops. The outer loop iterates from 0 to m, representing the indices of string X. The inner loop iterates from 0 to n, representing the indices of string Y. The base cases are set as follows:

When either i or j is 0, L[i][j] is set to 0, as there's no common subsequence with an empty string.
Dynamic Programming Calculation: The matrix L is filled iteratively based on the characters in strings X and Y. If the characters at indices i - 1 in X and j - 1 in Y match (X[i - 1] == Y[j - 1]), then L[i][j] is set to L[i - 1][j - 1] + 1, representing an extension of the LCS. If the characters don't match, L[i][j] is set to the maximum of L[i - 1][j] and L[i][j - 1], representing a choice between continuing the LCS from the previous row or the previous column.

*/




