/*
A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.

Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one  possible derangement {1, 0}

Input: n = 3
Output: 2

*/

// A Dynamic programming based C++ program to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
	// Create an array to store counts for subproblems
	int der[n + 1] = {0};

	// Base cases
	der[1] = 0;
	der[2] = 1;

	// Fill der[0..n] in bottom up manner using above recursive formula
	for (int i = 3; i <= n; ++i)
		der[i] = (i - 1) * (der[i - 1] +
							der[i - 2]);

	// Return result for n
	return der[n];
}


int main()
{
	int n = 4;
	cout << "Count of Derangements is "
		<< countDer(n);
	return 0;
}

/*
Main Function:

The main function initializes an integer variable n to the value 4, representing the size of the set for which derangements are to be counted.
It calls the function countDer(n) to calculate the count of derangements for the given 'n'.
Finally, it prints the result using the calculated count.
Function countDer:

This function takes an integer n as input, representing the size of the set.
It creates an array der of size (n + 1) to store the counts of derangements for subproblems.
Initializes the base cases: der[1] is set to 0 (since there's only one element and it cannot be in its original position), and der[2] is set to 1 (since there is only one derangement for a set of size 2).
Uses a bottom-up approach to fill the der array using the recurrence relation for derangements: der[i] = (i - 1) * (der[i - 1] + der[i - 2]).
The formula (i - 1) * (der[i - 1] + der[i - 2]) calculates the count of derangements for a set of size i, considering the possibilities where the last element is swapped with any of the previous (i - 1) elements, each with its own derangement count.
Finally, the function returns the count of derangements for the given 'n'.

*/

