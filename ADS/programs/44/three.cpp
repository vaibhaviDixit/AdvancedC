/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome,
the task is to find the minimum number of cuts needed for palindrome partitioning of the given string.

Input: str = “aaaa”
Output: 0
Explanation: The string is already a palindrome.

Input: str = “abcde”
Output: 4

Input: str = “abbac”
Output: 1

*/


#include <bits/stdc++.h>
using namespace std;

// Function to generate all possible palindromic substring
bool generatePalindrome(string& s,
						vector<vector<bool> >& pal)
{
	int n = s.size();

	// Initialize the palindrome matrix for single
	// characters
	for (int i = 0; i < n; i++) {
		pal[i][i] = true;
	}

	// Iterate over different lengths of substrings
	for (int len = 2; len <= n; len++) {
		// Iterate over the starting positions of substrings of current length
		for (int i = 0; i <= n - len; i++) {

			// Calculate the ending position of the
			// substring
			int j = i + len - 1;

			// Check if the characters at the starting and ending positions are equal and if the
			// substring between them is a palindrome or a single character
			if (s[i] == s[j]
				&& (len == 2 || pal[i + 1][j - 1])) {

				// Mark the substring from i to j as a
				// palindrome
				pal[i][j] = true;
			}
		}
	}
}

// Function to calculate the minimum number of cuts required to make all substrings of 's' palindromic
int minCut(string s)
{
	if (s.empty())
		return 0;
	int n = s.size();

	// 2D vector to store whether substring [i, j] is a palindrome
	vector<vector<bool> > pal(n, vector<bool>(n, false));

	generatePalindrome(s, pal);

	// vector to store minimum cuts required to make substring [i, n-1] palindromic
	vector<int> minCutDp(n, INT_MAX);

	// There is no cut required for single character as it is always palindrome
	minCutDp[0] = 0;

	// Iterate over the given string
	for (int i = 1; i < n; i++) {

		// Check if string 0 to i is palindrome.
		// Then minCut require will be 0.
		if (pal[0][i]) {
			minCutDp[i] = 0;
		}
		else {
			for (int j = i; j >= 1; j--) {

				// If s[i] and s[j] are equal and the inner substring [i+1, j-1] is a palindrome or  it has a length of 1
				if (pal[j][i]) {

					// Update the minimum cuts required if cutting at position 'j+1' results in a smaller value
					if (minCutDp[j - 1] + 1 < minCutDp[i])
						minCutDp[i] = minCutDp[j - 1] + 1;
				}
			}
		}
	}

	// Return the minimum cuts required for the entire string 's'
	return minCutDp[n - 1];
}

int main()
{
	string str = "ababbbabbababa";

	int cuts = minCut(str);
	cout << "Minimum cuts required: " << cuts << endl;
	return 0;
}

/*
The generatePalindrome function is defined to generate a matrix pal of size NxN, where N is the length of the input string s. The matrix pal[i][j] is used to determine whether the substring from index i to j in the string s is a palindrome. The function initializes the matrix for single characters (palindromes of length 1).

The function minCut is defined to calculate the minimum number of cuts required to make all substrings of s palindromic. It takes the input string s as an argument.

The function starts by checking if the string s is empty. If it is, the minimum number of cuts required is 0, as there are no substrings to consider.

It initializes several variables and data structures:

n: The length of the input string s.
pal: A 2D vector of boolean values to store whether substring [i, j] is a palindrome.
minCutDp: A vector to store the minimum cuts required to make substring [i, n-1] palindromic, initialized to a large value.
The program calls the generatePalindrome function to populate the pal matrix. It uses dynamic programming to mark substrings as palindromes based on whether the characters at the starting and ending positions are equal and whether the substring between them is a palindrome or a single character.

It initializes minCutDp[0] to 0, as there is no cut required for a single character, which is always a palindrome.

The program then iterates over the string s from the second character (index 1) to the last character (index n-1).

For each index i, it checks if the substring [0, i] is already a palindrome. If it is, then no additional cuts are needed (minCutDp[i] remains 0).

If the substring [0, i] is not a palindrome, the program iterates from index j = i to j = 1 in reverse order. For each j, it checks if s[i] and s[j] are equal and whether the inner substring [i+1, j-1] is a palindrome or has a length of 1. If these conditions are met, it updates minCutDp[i] with the minimum of its current value and minCutDp[j-1] + 1. This means that cutting at position j+1 results in a smaller number of cuts.

After processing all characters in the string, minCutDp[n-1] will contain the minimum number of cuts required to make all substrings of s palindromic.

Finally, the program prints the minimum cuts required.

*/
