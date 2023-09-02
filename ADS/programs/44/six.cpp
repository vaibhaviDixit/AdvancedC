/*
Given an array of positive distinct integer denoting the crossing time of ‘n’ people. These ‘n’ people are standing at one side of bridge.
Bridge can hold at max two people at a time. When two people cross the bridge, they must move at the slower person’s pace.
Find the minimum total time in which all persons can cross the bridge.

Note: Slower person space is given by larger time.

Input:  Crossing Times = {10, 20, 30}
Output: 60

Input: Crossing Times = [1, 2, 5, 8}
Output: 15

*/


// C++ program to find minimum time required to  send people on other side of bridge
#include <bits/stdc++.h>
using namespace std;

/* Global dp[2^20][2] array, in dp[i][j]-- 'i' denotes mask in which 'set bits' denotes
total people standing at left side of bridge and 'j' denotes the turn that represent on which side we have to send people either
from left to right(0) or from right to left(1) */
int dp[1 << 20][2];

/* Utility function to find total time required
to send people to other side of bridge */
int findMinTime(int leftmask, bool turn, int arr[], int& n)
{

	// If all people has been transferred
	if (!leftmask)
		return 0;

	int& res = dp[leftmask][turn];

	// If we already have solved this subproblem, return the answer.
	if (~res)
		return res;

	// Calculate mask of right side of people
	int rightmask = ((1 << n) - 1) ^ leftmask;

	/* if turn == 1 means currently people are at
	right side, thus we need to transfer
	people to the left side */
	if (turn == 1) {
		int minRow = INT_MAX, person;
		for (int i = 0; i < n; ++i) {

			// Select one people whose time is less
			// among all others present at right side
			if (rightmask & (1 << i)) {
				if (minRow > arr[i]) {
					person = i;
					minRow = arr[i];
				}
			}
		}

		// Add that person to answer and recurse for next
		// turn after initializing that person at left side
		res = arr[person]
			+ findMinTime(leftmask | (1 << person),
							turn ^ 1, arr, n);
	}
	else {

		// __builtin_popcount() is inbuilt gcc function which will count total set bits in 'leftmask'
		if (__builtin_popcount(leftmask) == 1) {
			for (int i = 0; i < n; ++i) {

				// Since one person is present at left
				// side, thus return that person only
				if (leftmask & (1 << i)) {
					res = arr[i];
					break;
				}
			}
		}
		else {

			// try for every pair of people by sending them to right side

			// Initialize the result with maximum value
			res = INT_MAX;
			for (int i = 0; i < n; ++i) {

				// If ith person is not present then skip the rest loop
				if (!(leftmask & (1 << i)))
					continue;

				for (int j = i + 1; j < n; ++j) {
					if (leftmask & (1 << j)) {

						// Find maximum integer(slowest person's time)
						int val = max(arr[i], arr[j]);

						// Recurse for other people after un-setting the ith and jth bit of left-mask
						val += findMinTime(
							leftmask ^ (1 << i) ^ (1 << j),
							turn ^ 1, arr, n);
						// Find minimum answer among all chosen values
						res = min(res, val);
					}
				}
			}
		}
	}
	return res;
}

// Utility function to find minimum time
int findTime(int arr[], int n)
{
	// Find the mask of 'n' peoples
	int mask = (1 << n) - 1;

	// Initialize all entries in dp as -1
	memset(dp, -1, sizeof(dp));

	return findMinTime(mask, 0, arr, n);
}


int main()
{
	int arr[] = { 10, 20, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findTime(arr, n);
	return 0;
}

/*
The global dp array is defined with dimensions [1 << 20][2]. This array is used for dynamic programming, where dp[i][j] represents the minimum time required to send people to the other side of the bridge. i denotes a mask in which set bits represent the total number of people standing at the left side of the bridge, and j denotes the turn, where 0 represents sending people from left to right, and 1 represents sending people from right to left.

The findMinTime function is defined to calculate the minimum time required to send people across the bridge. It takes the following arguments:

leftmask: A bitmask representing the people currently on the left side of the bridge.
turn: A boolean variable representing the current turn (0 for left to right, 1 for right to left).
arr[]: An array representing the walking times of individual people.
n: The number of people.
Inside the findMinTime function, the base case checks if all people have been transferred (leftmask is zero). If so, it returns 0 as there is no time required.

The program uses dynamic programming to solve subproblems efficiently. It stores the results in the dp array to avoid recomputation of the same subproblems.

For each turn, the program calculates the mask representing the people on the right side of the bridge (rightmask).

If it's the right-to-left turn (turn == 1), the program selects the person with the minimum walking time from the right side and adds their walking time to the result. Then, it recursively calls findMinTime with the updated leftmask and turn.

If it's the left-to-right turn (turn == 0), there are two cases:

If there's only one person on the left side (__builtin_popcount(leftmask) == 1), it selects that person as the result.
If there are multiple people on the left side, it tries all possible pairs of people to cross together and recursively calls findMinTime for each pair. It selects the pair that minimizes the maximum walking time.
The program returns the minimum time required for all people to cross the bridge.

In the main function, an example array arr is provided, representing the walking times of people. The program is set to find the minimum time required to send them all to the other side, and the result is printed.

*/

