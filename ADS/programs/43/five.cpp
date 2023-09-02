/*

Given a two strings S and T, find the count of distinct occurrences of T in S as a subsequence.

Input: S = banana, T = ban
Output: 3
Explanation: T appears in S as below three subsequences.
[ban], [ba  n], [b   an]

*/

/* C/C++ program to count number of times S appears as a subsequence in T */
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t,
	vector<vector<int> >& dp)
{
	if (t.size() - j > s.size() - i)
		return 0;

	if (j == t.size()) {
		return 1;
	}

	if (i == s.size()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = f(i + 1, j + 1, s, t, dp)
						+ f(i + 1, j, s, t, dp);
	}

	return dp[i][j] = f(i + 1, j, s, t, dp);
}

int findSubsequenceCount(string s, string t)
{
	vector<vector<int> > dp(s.size(),
							vector<int>(t.size(), -1));
	return f(0, 0, s, t, dp);
}


int main()
{
	string T = "za";
	string S = "pizzapizza";
	cout << findSubsequenceCount(S, T) << endl;
	return 0;
}

/*
Function f:

This is a recursive function that uses dynamic programming with memoization to find the count of occurrences of subsequence S in T.
It takes four arguments: i, j, s, and t.
i and j represent the current positions in strings s and t, respectively.
s is the subsequence we're looking for.
t is the target string in which we're searching for the subsequence.
It first checks if the remaining length of t is less than the remaining length of s. If so, it's not possible to form the subsequence anymore, so it returns 0.
If j reaches the end of string t, it means we've successfully formed the subsequence once, so it returns 1.
If i reaches the end of string s, it means we've exhausted all characters of the subsequence, so it returns 0.
If the value is already calculated in the DP table, it returns the cached value.
If the characters at the current positions i and j match, it recursively adds the result of two cases:
Incrementing both i and j to continue matching the subsequence.
Incrementing only i to skip the current character in s.
If the characters don't match, it only increments i and continues searching in t.
Function findSubsequenceCount:

This function initializes the DP table with -1.
It then calls the function f with initial positions i = 0 and j = 0, along with strings s and t, to get the count of subsequence occurrences.
It returns the final count.
Main Function:

In the main function, two strings T (target string) and S (subsequence) are defined.
The findSubsequenceCount function is called with strings S and T, and the result is printed.

*/

