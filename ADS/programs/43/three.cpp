/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two
integer arrays, val[0..n-1] and wt[0..n-1] represent values and weights associated with n items respectively. Also given an integer W which represents
knapsack capacity, find out the items such that sum of the weights of those items of a given subset is smaller than or equal to W. You cannot break an item,
either pick the complete item or don’t pick it (0-1 property).

Prerequisite : 0/1 Knapsack

Input : val[] = {60, 100, 120}
        wt[] = {10, 20, 30}
        W = 50
Output : 220 //maximum value that can be obtained
         30 20 //weights 20 and 30 are included.

Input : val[] = {40, 100, 50, 60}
        wt[] = {20, 10, 40, 30}
        W = 60
Output : 200
         30 20 10

*/


// CPP code for Dynamic Programming based solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	// stores the result of Knapsack
	int res = K[n][W];
	cout<< res << endl;

	w = W;
	for (i = n; i > 0 && res > 0; i--) {

		// either the result comes from the top (K[i-1][w]) or from (val[i-1] + K[i-1]
		// [w-wt[i-1]]) as in Knapsack table. If  it comes from the latter one/ it means the item is included.
		if (res == K[i - 1][w])
			continue;
		else {

			// This item is included.
			cout<<" "<<wt[i - 1] ;

			// Since this weight is included its value is deducted
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}

int main()
{
	int val[] = { 200, 500, 320 };
	int wt[] = { 10, 50, 40 };
	int W = 250;
	int n = sizeof(val) / sizeof(val[0]);

	printknapSack(W, wt, val, n);

	return 0;
}

/*
Main Function:

The main function initializes arrays val and wt with values representing the values and weights of each item, respectively.
The integer W represents the maximum weight capacity of the knapsack.
The integer n is calculated as the size of the val array divided by the size of a single element.
The function printknapSack is called with arguments W, wt, val, and n.
Function max:

This is a utility function that returns the maximum of two integers.
Function printknapSack:

This function takes arguments:
W: The maximum weight capacity of the knapsack.
wt[]: Array of item weights.
val[]: Array of item values.
n: Number of items.
The function constructs a 2D array K[][] of dimensions (n + 1) x (W + 1) to store the maximum values that can be obtained for different combinations of items and weights.
It iterates through all items and weight capacities, filling up the K table based on the maximum value achievable at each stage.
After building the K table, the maximum achievable value is stored in res.
The function then reconstructs the selected items by backtracking through the K table, starting from the last cell (n, W). If the value at cell (i, w) is not equal to the value at (i - 1, w), it means the item i is included in the knapsack. The item's weight is printed, and the value and weight are subtracted from res and W respectively.

*/

