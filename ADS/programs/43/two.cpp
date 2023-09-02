/*
Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight
in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible.

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all [It is not possible to put a part of an item into the bag].

Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3

*/


// Here is the top-down approach of dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int index, int** dp)
{
	// base condition
	if (index < 0)
		return 0;
	if (dp[index][W] != -1)
		return dp[index][W];

	if (wt[index] > W) {

		// Store the value of function call stack in table before return
		dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
		return dp[index][W];
	}
	else {
		// Store value in a table before return
		dp[index][W] = max(val[index]
						+ knapSackRec(W - wt[index], wt, val,
										index - 1, dp),
					knapSackRec(W, wt, val, index - 1, dp));

		// Return value of table after storing
		return dp[index][W];
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	// double pointer to declare the table dynamically
	int** dp;
	dp = new int*[n];

	// loop to create the table dynamically
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];

	// loop to initially filled the table with -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(W, weight, profit, n);
	return 0;
}

/*
Main Function:

The main function initializes arrays profit and weight with values representing the profit and weight of each item, respectively.
The integer W represents the maximum weight capacity of the knapsack.
The integer n is calculated as the size of the profit array divided by the size of a single element.
The function knapSack is called with arguments W, weight, profit, and n.
The result of the knapsack problem is printed, which represents the maximum profit that can be obtained within the given weight capacity.
Function knapSackRec:

This function takes arguments:
W: The remaining weight capacity of the knapsack.
wt[]: Array of item weights.
val[]: Array of item values.
index: The current index of the item being considered.
dp: A dynamically allocated table to store computed results for subproblems.
The function uses memoization to store and retrieve previously computed results.
Base cases are checked:
If the current index is negative, return 0 (no items left to consider).
If the current subproblem has already been solved and stored in the dp table, return the stored value.
If the weight of the current item is greater than the remaining capacity (W), the function recursively calls itself with the previous index and the same weight capacity, storing the result in the dp table.
If the weight of the current item can be accommodated, the function computes the maximum profit by either including the item (val[index] + knapSackRec(...)) or excluding it (knapSackRec(...)).
The calculated result is stored in the dp table for future reference.
The function returns the maximum profit for the current subproblem.
Function knapSack:

This function is the driver function for solving the 0-1 Knapsack problem using the top-down approach.
It allocates memory for the dp table using a double pointer (int** dp) to store computed results.
It then initializes the dp table with -1 values.
Finally, it calls the knapSackRec function with appropriate arguments and returns the result.

*/
