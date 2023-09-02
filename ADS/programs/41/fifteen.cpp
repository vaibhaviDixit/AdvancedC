/*
Given an array arr[] where each element represents the max number of steps that can be made forward from that index.
The task is to find the minimum number of jumps to reach the end of the array starting from index 0.

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 9 -> 9)

Explanation: Jump from 1st element to 2nd element as there is only 1 step.
Now there are three options 5, 8 or 9. If 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10

*/


// C++ program for Minimum number of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

// Returns minimum number of jumps to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
	// jumps[n-1] will hold the result
	int* jumps = new int[n];
	int i, j;

	if (n == 0 || arr[0] == 0)
		return INT_MAX;

	jumps[0] = 0;

	// Find the minimum number of jumps to reach arr[i] from arr[0], and assign this value to jumps[i]
	for (i = 1; i < n; i++) {
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++) {
			if (i <= j + arr[j] && jumps[j] != INT_MAX) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}

int main()
{
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);
	cout << "Minimum number of jumps to reach end is "
		<< minJumps(arr, size);
	return 0;
}

/*

Function Definitions:

int min(int x, int y): This function returns the minimum of two integers x and y.
int minJumps(int arr[], int n): This function takes an array of integers arr representing the jump distances at each position and an integer n indicating the size of the array. It calculates and returns the minimum number of jumps needed to reach the last element.
Main Function:

The main function initializes an array arr with jump distances at each position.
It calculates the size of the array using sizeof(arr) / sizeof(int) and stores it in the size variable.
The minJumps function is called with the array and its size, and the result is printed using cout.
minJumps Function Logic:

An array jumps is created to store the minimum number of jumps required to reach each position.
The first element of the array jumps is set to 0, as no jumps are needed to reach the starting position.
The function iterates through each position from index 1 to index n-1 and calculates the minimum number of jumps required to reach that position.
It does this by checking all the previous positions reachable from the current position and choosing the one that requires the minimum number of jumps.
The calculated minimum number of jumps is stored in the jumps array for the current position.
Finally, the function returns the value of jumps[n-1], which holds the minimum number of jumps needed to reach the end of the array.

*/




