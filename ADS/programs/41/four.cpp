/*
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

Input: n = 5, k = 2
Output: 10

Input: n = 4, k = 2
Output: 6

*/

// C++ program for space optimized Dynamic Programming Solution of Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
	int C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // nC0 is 1

	for (int i = 1; i <= n; i++)
	{

		// Compute next row of pascal triangle using
		// the previous row
		for (int j = min(i, k); j > 0; j--)
			C[j] = C[j] + C[j - 1];
	}
	return C[k];
}


int main()
{
	int n = 5, k = 2;
	cout << "Value of C(" << n << "," << k << ")"<< "is " <<binomialCoeff(n, k);
	return 0;
}

/*
The binomialCoeff Function: This function calculates the binomial coefficient nCk using a space-optimized dynamic programming approach. It takes two integer parameters, n and k, representing the values for which the binomial coefficient is to be calculated.

Coefficient Array: An integer array C of size k + 1 is declared to store the binomial coefficients. The array is initialized to zeros using the memset function.

Base Case: The value C[0] is set to 1, representing "nC0."

Calculating Coefficients: Two nested loops are used to fill in the C array. The outer loop iterates from 1 to n, representing the rows of Pascal's triangle. The inner loop calculates the next row of coefficients using the previous row.

The inner loop iterates from min(i, k) down to 1, where i represents the current row. This is done to avoid unnecessary calculations when k is smaller than i.
The value at C[j] is updated using the formula C[j] = C[j] + C[j - 1], which is the addition of the element from the current row and the element from the previous row.

*/

