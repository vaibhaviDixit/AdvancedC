/*
Given are N boards of with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of
the board. The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards,
say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Input: N = 4, A = {10, 10, 10, 10}, K = 2
Output : 20

*/

// A DP based CPP program for painter's partition problem
#include <climits>
#include <iostream>
using namespace std;

// function to calculate sum between two indices in array
int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

// bottom up tabular dp
int findMax(int arr[], int n, int k)
{
	// initialize table
	int dp[k + 1][n + 1] = { 0 };

	// base cases
	// k=1
	for (int i = 1; i <= n; i++)
		dp[1][i] = sum(arr, 0, i - 1);

	// n=1
	for (int i = 1; i <= k; i++)
		dp[i][1] = arr[0];

	// 2 to k partitions
	for (int i = 2; i <= k; i++) { // 2 to n boards
		for (int j = 2; j <= n; j++) {

			// track minimum
			int best = INT_MAX;

			// i-1 th separator before position arr[p=1..j]
			for (int p = 1; p <= j; p++)
				best = min(best, max(dp[i - 1][p],
									sum(arr, p, j - 1)));

			dp[i][j] = best;
		}
	}

	// required
	return dp[k][n];
}

int main()
{
	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << findMax(arr, n, k) << endl;
	return 0;
}

/*
The sum function is defined to calculate the sum of elements in an array between two indices (from and to).

The findMax function is defined to solve the Painter's Partition Problem. It takes three arguments:

arr[]: An array representing the time required to paint each board.
n: The number of boards.
k: The number of painters available.
Inside the findMax function, a 2D table dp[k+1][n+1] is initialized to store the minimum time required. Each cell dp[i][j] represents the minimum time required for i painters to paint j boards.

The program initializes the base cases:

When there is only one painter (k=1), the time required to paint the first i boards is the sum of times of those boards.
When there is only one board (n=1), the time required by any number of painters is the time to paint that single board.
The program then iterates from i=2 to k (representing 2 to k painters) and from j=2 to n (representing 2 to n boards).

For each combination of i and j, it calculates the minimum time required by considering different positions to add a separator (divider) between the boards.

The best variable keeps track of the minimum maximum time among all possible separator positions. It starts with a maximum value (INT_MAX).

The program iterates through all possible separator positions p from 1 to j. For each separator position, it calculates the maximum time required for the previous partition (dp[i-1][p]) and the time required to paint the current partition (sum(arr, p, j-1)).

The minimum of these two values is taken as the new value for best.

After calculating best for all separator positions, the program sets dp[i][j] to the minimum best value, representing the minimum time required for i painters to paint j boards optimally.

Finally, the program returns dp[k][n], which represents the minimum time required for k painters to paint n boards optimally.

In the main function, an example array arr is provided, representing the time required to paint each board. The program is set to find the minimum time required for 3 painters to paint the boards, and the result is printed.

*/


