/*
Given a string ‘S’, find the length of the Longest Palindromic Subsequence in it.

The Longest Palindromic Subsequence (LPS) is the problem of finding a maximum-length subsequence of a given string that is also a Palindrome.

Input: S = “BBABCBCAB”
Output: 7

*/


// A Dynamic Programming based C++ program for LPS problem  Returns the length of the longest palindromic subsequence
#include <algorithm>
#include <cstring> // for memset
#include <iostream>
#include <string>

using namespace std;

int longestPalinSubseq(string S)
{
	string R = S;
	reverse(R.begin(), R.end());

	// dp[i][j] will store the length of the longest
	// palindromic subsequence for the substring
	// starting at index i and ending at index j
	int dp[S.length() + 1][R.length() + 1];

	// Initialize dp array with zeros
	memset(dp, 0, sizeof(dp));

	// Filling up DP table based on conditions discussed in the above approach
	for (int i = 1; i <= S.length(); i++) {
		for (int j = 1; j <= R.length(); j++) {
			if (S[i - 1] == R[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	// At the end, DP table will contain the LPS So just return the length of LPS
	return dp[S.length()][R.length()];
}

int main()
{
	string s = "pizzalovepizza";
	cout << "The length of the LPS is "
		<< longestPalinSubseq(s) << endl;

	return 0;
}

/*
Function longestPalinSubseq:

This function takes a string S as input.
It creates a reversed string R by reversing the characters of S.
It declares a 2D array dp where dp[i][j] will store the length of the longest palindromic subsequence for the substring starting at index i in S and ending at index j in R.
The DP array is initialized with zeros using the memset function.
The DP array is filled based on the following conditions:
If the characters at positions i and j in S and R match, increment dp[i][j] by 1 and set it to the value of dp[i - 1][j - 1].
If the characters do not match, update dp[i][j] to the maximum of dp[i][j - 1] and dp[i - 1][j].
At the end of the loop, dp[S.length()][R.length()] will contain the length of the LPS.
Main Function:

The main function initializes a string s with a sample input.
It calls the longestPalinSubseq function with the string s to calculate and print the length of the Longest Palindromic Subsequence (LPS).

*/


