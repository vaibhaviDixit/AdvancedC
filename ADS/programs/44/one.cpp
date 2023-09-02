/*
Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.
Example:
ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd


Input: str= pizza
Output: 3

*/

// A Dynamic Programming based program to find minimum number insertions needed to make a string palindrome
#include <bits/stdc++.h>
using namespace std;


// A DP function to find minimum number of insertions
int findMinInsertionsDP(char str[], int n)
{
	// Create a table of size n*n. table[i][j] will store minimum number of insertions needed to convert str[i..j] to a palindrome.
	int table[n][n], l, h, gap;

	// Initialize all table entries as 0
	memset(table, 0, sizeof(table));

	// Fill the table
	for (gap = 1; gap < n; ++gap)
		for (l = 0, h = gap; h < n; ++l, ++h)
			table[l][h] = (str[l] == str[h])?
						table[l + 1][h - 1] :
						(min(table[l][h - 1],
							table[l + 1][h]) + 1);

	// Return minimum number of insertions for str[0..n-1]
	return table[0][n - 1];
}

int main()
{
	char str[] = "pizza";
	cout << findMinInsertionsDP(str, strlen(str));
	return 0;
}

/*
It creates a 2D table called table of size n x n. Each entry table[i][j] will store the minimum number of insertions needed to convert the substring str[i..j] into a palindrome.

The table is initialized with all entries set to 0.

The program then iterates through the string using two nested loops, where gap represents the length of the substring being considered. It starts with a gap of 1 and gradually increases the gap until it covers the entire string.

For each substring of length gap, the program checks if the characters at the two ends (str[l] and str[h]) are equal. If they are equal, no insertions are needed, and the value is copied from table[l + 1][h - 1].

If the characters are not equal, the program calculates the minimum number of insertions needed by taking the minimum of the following two values:

table[l][h - 1]: Minimum insertions needed by excluding the last character.
table[l + 1][h]: Minimum insertions needed by excluding the first character.
The final value in table[0][n - 1] represents the minimum number of insertions needed to make the entire string str a palindrome.

*/
