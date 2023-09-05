/*
Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum, the task is to find the
number of ways to make sum by using different denominations.

Note: Assume that you have an infinite supply of each type of coin.

Input: sum = 4, coins[] = {1,2,3},
Output: 4
Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}.

Input: sum = 10, coins[] = {2, 5, 3, 6}
Output: 5

*/

#include <bits/stdc++.h>

using namespace std;

// Returns total distinct ways to make sum using n coins of different denominations
int count(vector<int>& coins, int n, int sum)
{
	// 2d dp array where n is the number of coin
	// denominations and sum is the target sum
	vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));

	// Represents the base case where the target sum is 0, and there is only one way to make change: by not selecting any coin
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {

			// Add the number of ways to make change without using the current coin,
			dp[i][j] += dp[i - 1][j];

			if ((j - coins[i - 1]) >= 0) {

				// Add the number of ways to make change
				// using the current coin
				dp[i][j] += dp[i][j - coins[i - 1]];
			}
		}
	}
	return dp[n][sum];
}


int main()
{
	vector<int> coins{ 1, 2, 3 };
	int n = 3;
	int sum = 5;
	cout << count(coins, n, sum);
	return 0;
}

/*
The count Function: This function calculates the total distinct ways to make a given sum using a set of different coin denominations. It takes three parameters: a reference to a vector of integers coins (denoting the coin denominations), an integer n (the number of coin denominations), and an integer sum (the target sum).

2D DP Array: A 2D vector dp of size (n + 1) x (sum + 1) is created to store the dynamic programming table. Each cell dp[i][j] represents the number of ways to make a sum of j using the first i coin denominations.

Base Case: The base case dp[0][0] is initialized to 1 because there is only one way to make change for a sum of 0: by not selecting any coin.

Dynamic Programming Loop: Two nested loops iterate over the coin denominations and the target sum, respectively. For each denomination i and sum j, the following steps are performed:

The value dp[i][j] is updated by adding the number of ways to make change without using the current coin (which is dp[i - 1][j]).
If subtracting the current coin's value (coins[i - 1]) from the current sum (j) results in a valid index, the value dp[i][j] is further updated by adding the number of ways to make change using the current coin (which is dp[i][j - coins[i - 1]]).

*/


