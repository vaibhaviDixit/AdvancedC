/*
Given a 2D array, find the maximum sum submatrix in it. For example, in the following 2D array, the maximum sum submatrix is highlighted with blue
rectangle and sum of all elements in this submatrix is 29.

Input:
{ 1, 2, -1, -4, -20 }
{ -8, -3, 4, 2, 1 }
{ 3, 8, 10, 1, 3 }
{ -4, -1, 1, 7, -6 }

Output:
(Top, Left) (1, 1)
(Bottom, Right) (3, 3)
Max sum is: 29

*/


// Program to find maximum sum subarray in a given 2D array
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

// Implementation of Kadane's algorithm for 1D array. The function returns the maximum
// sum and stores starting and ending indexes of the maximum sum subarray at addresses
// pointed by start and finish pointers respectively.
int kadane(int* arr, int* start, int* finish, int n)
{
	// initialize sum, maxSum and
	int sum = 0, maxSum = INT_MIN, i;

	// Just some initial value to check for all negative values case
	*finish = -1;

	// local variable
	int local_start = 0;

	for (i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum) {
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	// There is at-least one non-negative number
	if (*finish != -1)
		return maxSum;

	// Special Case: When all numbers in arr[] are negative
	maxSum = arr[0];
	*start = *finish = 0;

	// Find the maximum element in array
	for (i = 1; i < n; i++) {
		if (arr[i] > maxSum) {
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

// The main function that finds maximum sum rectangle in M[][]
void findMaxSum(int M[][COL])
{
	// Variables to store the final output
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop,
		finalBottom;

	int left, right, i;
	int temp[ROW], sum, start, finish;

	// Set the left column
	for (left = 0; left < COL; ++left) {
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));

		// Set the right column for the left column set by outer loop
		for (right = left; right < COL; ++right) {

			// Calculate sum between current left and right for every row 'i'
			for (i = 0; i < ROW; ++i)
				temp[i] += M[i][right];

			// Find the maximum sum subarray in temp[].The kadane() function also sets values of start and finish. So 'sum' is sum of
			// rectangle between (start, left) and (finish, right) which is the maximum sum with boundary columns strictly as left and right.
			sum = kadane(temp, &start, &finish, ROW);

			// Compare sum with maximum sum so far.
			// If sum is more, then update maxSum and
			// other output values
			if (sum > maxSum) {
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	// Print final values
	cout << "(Top, Left) (" << finalTop << ", " << finalLeft
		<< ")" << endl;
	cout << "(Bottom, Right) (" << finalBottom << ", "
		<< finalRight << ")" << endl;
	cout << "Max sum is: " << maxSum << endl;
}

int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
						{ -8, -3, 4, 2, 1 },
						{ 3, 8, 10, 1, 3 },
						{ -4, -1, 1, 7, -6 } };

	// Function call
	findMaxSum(M);

	return 0;
}

/*
The program defines ROW and COL constants to specify the dimensions of the 2D array M.

The kadane function is an implementation of Kadane's algorithm for 1D arrays. It calculates the maximum sum subarray in a 1D array and also determines the starting and ending indexes of that subarray. This function takes the following parameters:

arr: The input 1D array.
start and finish: Pointers to variables that store the starting and ending indexes of the maximum sum subarray.
n: The size of the input array.
In the main function, the program initializes the 2D array M with example values.

The findMaxSum function is used to find the maximum sum subarray within the 2D array M. It uses a nested loop structure to iterate through the columns in the array, effectively treating it as a series of 1D arrays.

The outer loop (left variable) sets the left boundary of the subarray, and the inner loop (right variable) sets the right boundary.

Within the inner loop, the program calculates a temporary array temp that stores the cumulative sum of each row's elements between the left and right boundaries.

The kadane function is called with the temp array, which calculates the maximum sum subarray within the rows of the 2D array for the current left and right boundaries.

The program keeps track of the maximum sum and its corresponding boundaries (finalLeft, finalRight, finalTop, finalBottom) as it iterates through the columns and rows.

Once the loop finishes, the program prints the coordinates of the top-left and bottom-right corners of the maximum sum subarray, as well as the maximum sum itself.

*/
