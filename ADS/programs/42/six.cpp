/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.


Input:
N = 1, K = 2
Output: 2

Input:
N = 2, K = 10
Output: 4

*/

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Function to get minimum number of trials needed in worst case with n eggs and k floors */
int eggDrop(int n, int k)
{
	/* A 2D table where entry eggFloor[i][j] will represent minimum number of trials needed for i eggs and j floors. */
	int eggFloor[n + 1][k + 1];
	int res;
	int i, j, x;

	// We need one trial for one floor and 0 trials for 0 floors
	for (i = 1; i <= n; i++) {
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}

	// We always need j trials for one egg and j floors.
	for (j = 1; j <= k; j++)
		eggFloor[1][j] = j;

	// Fill rest of the entries in table using optimal substructure property
	for (i = 2; i <= n; i++) {
		for (j = 2; j <= k; j++) {
			eggFloor[i][j] = INT_MAX;
			for (x = 1; x <= j; x++) {
				res = 1
					+ max(eggFloor[i - 1][x - 1],
							eggFloor[i][j - x]);
				if (res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}
		}
	}

	// eggFloor[n][k] holds the result
	return eggFloor[n][k];
}

int main()
{
	int n = 2, k = 36;
	cout << "\nMinimum number of trials in worst case with "<< n << " eggs and " << k << " floors is "
		<< eggDrop(n, k)<<endl;
	return 0;
}

/*
Utility Function max: This function is used to return the maximum of two integers.

Function eggDrop:

This function takes two input parameters: n (number of eggs) and k (number of floors).
It calculates and returns the minimum number of trials needed to determine the highest safe floor from which an egg can be dropped without breaking.
It uses dynamic programming to find the solution efficiently.
The function initializes a 2D array eggFloor of size (n + 1) x (k + 1) to store the results of subproblems.
The base cases are filled: eggFloor[i][1] (minimum trials for 1 floor) is 1, and eggFloor[i][0] (minimum trials for 0 floors) is 0.
The base cases for 1 egg and j floors are filled: eggFloor[1][j] (minimum trials for 1 egg and j floors) is j (as you need to try all floors sequentially).
The remaining entries in the table are filled using the optimal substructure property. For each egg i and each floor j, a loop is used to try all possible dropping points (x from 1 to j). The result res is calculated as 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]), representing one trial plus the maximum of the cases when the egg breaks or doesn't break. The minimum res is stored in eggFloor[i][j].
Main Function:

The main function initializes n to 2 (number of eggs) and k to 36 (number of floors).
It calls the eggDrop function with the given values of n and k and prints the result, which represents the minimum number of trials in the worst case scenario.

*/
