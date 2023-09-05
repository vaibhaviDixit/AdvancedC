/*
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Input  : n = 3
Output : 4
Explanation:
{1}, {2}, {3} : all single
{1}, {2, 3} : 2 and 3 paired but 1 is single.
{1, 2}, {3} : 1 and 2 are paired but 3 is single.
{1, 3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1, 2} and {2, 1} are considered same.

*/


// C++ program for solution of friends pairing problem
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways n people can remain single or paired up.
int countFriendsPairings(int n)
{
	int dp[n + 1];

	// Filling dp[] in bottom-up manner using
	// recursive formula explained above.
	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}

int main()
{
	int n = 4;
	cout << countFriendsPairings(n) << endl;
	return 0;
}

/*
The countFriendsPairings function is defined to calculate the number of ways 'n' people can remain single or pair up. It uses dynamic programming to store and compute the counts.

Inside the countFriendsPairings function:

An array dp[] of size (n + 1) is created to store the counts of ways for each value of 'n.'

A loop runs from 0 to 'n' to fill the dp[] array with counts.

For each value of 'i' in the loop:

If 'i' is less than or equal to 2, it means there are 0, 1, or 2 people, and they can remain single or pair up in 'i' ways.

For values of 'i' greater than 2, the count is calculated using the recursive formula explained in the comments.

*/
