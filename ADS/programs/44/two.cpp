/*
Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text (not partial text). The wildcard pattern can include the characters ‘?’ and ‘*’

‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Input:
str = "baaabab"
pattern = "*****ba*****ab"

Output: Yes

*/


// C++ program to implement wildcard pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

// Function that matches input str with given wildcard pattern
bool strmatch(char str[], char pattern[], int n, int m)
{
	// empty pattern can only match with empty string
	if (m == 0)
		return (n == 0);

	// lookup table for storing results of subproblems
	bool lookup[n + 1][m + 1];

	// initialize lookup table to false
	memset(lookup, false, sizeof(lookup));

	// empty pattern can match with empty string
	lookup[0][0] = true;

	// Only '*' can match with empty string
	for (int j = 1; j <= m; j++)
		if (pattern[j - 1] == '*')
			lookup[0][j] = lookup[0][j - 1];

	// fill the table in bottom-up fashion
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// Two cases if we see a '*'
			// a) We ignore ‘*’ character and move to next character in the pattern, i.e., ‘*’ indicates an empty sequence.
			// b) '*' character matches with ith character in input
			if (pattern[j - 1] == '*')
				lookup[i][j]
					= lookup[i][j - 1] || lookup[i - 1][j];

			// Current characters are considered as matching in two cases
			// (a) current character of pattern is '?'
			// (b) characters actually match
			else if (pattern[j - 1] == '?'
					|| str[i - 1] == pattern[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1];

			// If characters don't match
			else
				lookup[i][j] = false;
		}
	}

	return lookup[n][m];
}

int main()
{
	char str[] = "baaabab";
	char pattern[] = "*baaaba*";
	// char pattern[] = "ba*****ab";
	// char pattern[] = "ba*ab";
	// char pattern[] = "a*ab";
	// char pattern[] = "a*****ab";
	// char pattern[] = "*a*****ab";
	// char pattern[] = "ba*ab****";
	// char pattern[] = "****";
	// char pattern[] = "*";
	// char pattern[] = "aa?ab";
	// char pattern[] = "b*b";
	// char pattern[] = "a*a";
	// char pattern[] = "baaabab";
	// char pattern[] = "?baaabab";
	// char pattern[] = "*baaaba*";

	if (strmatch(str, pattern, strlen(str),
				strlen(pattern)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

/*
The strmatch function takes four arguments: 'str' (the input string), 'pattern' (the wildcard pattern to match against), 'n' (the length of 'str'), and 'm' (the length of 'pattern').

It initializes a lookup table lookup of size (n+1) x (m+1) to store the results of subproblems. The idea is to fill this table to determine if 'str' matches 'pattern' using dynamic programming.

The lookup table is initialized as 'false' for all entries. However, lookup[0][0] is set to 'true' because an empty pattern matches an empty string.

The program then handles the '' character in the pattern. It iterates through 'pattern' and sets lookup[0][j] to 'true' for all consecutive '' characters in the pattern. This means that '*' can match an empty sequence or any sequence of characters.

The dynamic programming table lookup is filled in a bottom-up fashion. For each character in 'str' and 'pattern', the program checks the following cases:

If the current character in 'pattern' is '', it can match either an empty sequence (ignoring '') or the current character in 'str'.
If the current character in 'pattern' is '?' (a wildcard for any character) or if the characters in 'str' and 'pattern' match, it considers them as matching.
If the characters don't match and the current character in 'pattern' is not '*', it's marked as 'false.'
Finally, the function returns the value of lookup[n][m], which indicates whether the entire 'str' matches the entire 'pattern' according to the wildcard rules.

In the main function, there are several test cases for demonstrating how the wildcard pattern matching works with different patterns and strings. It prints "Yes" if there's a match and "No" otherwise.

*/

