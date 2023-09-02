/*
Given two strings ‘X’ and ‘Y’, find the length of longest common substring. Expected space complexity is linear.

Input : X = "abcdxyz", Y = "xyzabcd"
Output : 4

*/

// Space optimized CPP implementation of longest common substring.
#include <bits/stdc++.h>
using namespace std;

// Function to find longest common substring.
int LCSubStr(string X, string Y)
{
	// Find length of both the strings.
	int m = X.length();
	int n = Y.length();

	// Variable to store length of longest
	// common substring.
	int result = 0;

	// Matrix to store result of two consecutive rows at a time.
	int len[2][n];

	// Variable to represent which row of matrix is current row.
	int currRow = 0;

	// For a particular value of i and j, len[currRow][j] stores length of longest common substring in string X[0..i] and Y[0..j].
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				len[currRow][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1]) {
				len[currRow][j] = len[1 - currRow][j - 1] + 1;
				result = max(result, len[currRow][j]);
			}
			else {
				len[currRow][j] = 0;
			}
		}

		// Make current row as previous row and previous
		// row as new current row.
		currRow = 1 - currRow;
	}

	return result;
}

int main()
{
	string X = "dominos";
	string Y = "domestic";

	cout << LCSubStr(X, Y);
	return 0;
}

/*
LCSubStr Function:

This function takes two input strings X and Y.
It finds the length of the longest common substring between the two strings.
The function uses a dynamic programming approach and a rolling array to optimize space usage.
The function iterates through each character of strings X and Y using two loops.
It uses a matrix len of size 2 x n to store the length of the longest common substring between substrings of X and Y. The rolling array technique is used to optimize memory usage.
The currRow variable is used to indicate which row of the matrix is the current row.
For each character at indices i and j, the function checks if they are equal. If they are equal, it updates len[currRow][j] to be the length of the longest common substring up to the previous characters plus 1.
The result variable is updated to store the maximum length of the common substring encountered so far.
If the characters at indices i and j are not equal, the length of the common substring is set to 0.
After processing a row, the currRow is toggled between 0 and 1 to efficiently switch between rows in the matrix.
The function returns the maximum length of the common substring found.
Main Function:

The main function initializes two strings X and Y with the values "dominos" and "domestic".
It calls the LCSubStr function with the two strings and prints the result, which is the length of the longest common substring.

*/




