/*
Given three numbers n, r and p, compute value of nCr mod p.

Input:  n = 10, r = 2, p = 13
Output: 6

*/

// A Dynamic Programming based solution to compute nCr % p
#include <bits/stdc++.h>
using namespace std;

// Returns nCr % p
int nCrModp(int n, int r, int p)
{
	// Optimization for the cases when r is large
	if (r > n - r)
		r = n - r;

	// The array C is going to store last row of pascal triangle at the end. And last entry of last row is nCr
	int C[r + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // Top row of Pascal Triangle

	// One by constructs remaining rows of Pascal Triangle from top to bottom
	for (int i = 1; i <= n; i++) {

		// Fill entries of current row using previous row values
		for (int j = min(i, r); j > 0; j--)

			// nCj = (n-1)Cj + (n-1)C(j-1);
			C[j] = (C[j] + C[j - 1]) % p;
	}
	return C[r];
}

int main()
{
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is " << nCrModp(n, r, p);
	return 0;
}

/*
The nCrModp Function: This function calculates the binomial coefficient "n choose r" modulo "p" using a dynamic programming-based approach. It takes three parameters: n (the total number of items), r (the number of items to choose), and p (the prime number modulo).

Optimization for Large "r": If r is larger than n - r, the program assigns r the value of n - r. This is an optimization to choose the smaller value for calculation efficiency.

Array C to Store Pascal's Triangle Row: An integer array C of size r + 1 is declared to store the last row of Pascal's triangle. Each element C[j] will represent the binomial coefficient "n-1 choose j".

Base Case: The first element of C is set to 1, as the top row of Pascal's triangle has a single element equal to 1.

Constructing Pascal's Triangle Row: Two nested loops are used to fill the elements of array C. The outer loop iterates from 1 to n, representing the rows of Pascal's triangle. The inner loop iterates from min(i, r) down to 1, representing the columns of Pascal's triangle for that row.

The value C[j] is updated using the formula C[j] = (C[j] + C[j - 1]) % p. This formula is derived from the Pascal's triangle recurrence relation: "nCj = (n-1)Cj + (n-1)C(j-1)".

*/
