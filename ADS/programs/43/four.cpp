/*
Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.

Note: N is always positive i.e greater than zero

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100

Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}
Output : 110

*/

/* A Naive recursive implementation of unbounded Knapsack problem */

#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int unboundedKnapsack(int W, int wt[], int val[], int idx,
					vector<vector<int> >& dp)
{

	// Base Case
	// if we are at idx 0.
	if (idx == 0) {
		return (W / wt[0]) * val[0];
	}
	// If the value is already calculated then we will previous calculated value
	if (dp[idx][W] != -1)
		return dp[idx][W];
	// There are two cases either take element or not take. If not take then

	int notTake= 0 + unboundedKnapsack(W, wt, val, idx - 1, dp);
	// if take then weight = W-wt[idx] and index will remain same.
	int take = INT_MIN;
	if (wt[idx] <= W) {
		take = val[idx]
			+ unboundedKnapsack(W - wt[idx], wt, val,
								idx, dp);
	}
	return dp[idx][W] = max(take, notTake);
}


int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);
	vector<vector<int> > dp(n, vector<int>(W + 1, -1));
	cout << unboundedKnapsack(W, wt, val, n - 1, dp);
	return 0;
}

/*

Main Function:

The main function initializes the maximum weight capacity of the knapsack W, the arrays val and wt representing the values and weights of each item respectively, and the integer n representing the number of items.
A 2D vector dp of size n x (W + 1) is created to store the results of subproblems. It is initialized with -1 to indicate that the values have not been calculated yet.
The function unboundedKnapsack is called with arguments W, wt, val, n - 1, and dp. The last argument n - 1 represents the index of the last item in the arrays.
Function unboundedKnapsack:

This function implements the naive recursive approach to solve the unbounded knapsack problem.
It takes arguments:
W: The remaining weight capacity of the knapsack.
wt[]: Array of item weights.
val[]: Array of item values.
idx: The current index of the item being considered.
dp: 2D vector to store results of subproblems.
The base case occurs when the index idx reaches 0. In this case, the maximum value that can be obtained is (W / wt[0]) * val[0] since we can take as many instances of the first item as possible within the weight capacity.
If the value at dp[idx][W] is not -1, it means that the value for this state has already been calculated, and it is returned.
Otherwise, the function calculates two values:
notTake: Represents the maximum value without considering the current item. It calls the unboundedKnapsack function recursively with the index reduced by 1.
take: Represents the maximum value by considering the current item. It checks if the weight of the current item is less than or equal to the remaining capacity W. If it is, it calls the function recursively with the same index and a reduced capacity W - wt[idx].
The function returns the maximum of take and notTake as the result and stores it in the dp table for the given index and remaining capacity.

*/
