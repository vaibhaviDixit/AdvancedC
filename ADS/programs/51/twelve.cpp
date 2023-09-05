/*
Given a positive integer n. The task is to find the sum of square of Binomial Coefficient i.e
nC02 + nC12 + nC22 + nC32 + ……… + nCn-22 + nCn-12 + nCn2


Input : n = 4
Output : 70

Input : n = 5
Output : 252


*/


// CPP Program to find the sum of square of binomial coefficient.
#include<bits/stdc++.h>
using namespace std;

// function to return product of number from start to end.
int factorial(int start, int end)
{
	int res = 1;
	for (int i = start; i <= end; i++)
		res *= i;

	return res;
}

// Return the sum of square of binomial coefficient
int sumofsquare(int n)
{
	return factorial(n+1, 2*n)/factorial(1, n);
}

int main()
{
	int n = 4;
	cout << sumofsquare(n) << endl;
	return 0;
}

/*

The factorial function is defined to calculate the factorial of a range of numbers from start to end (inclusive). It iteratively multiplies all the numbers within the specified range and returns the result.

The sumofsquare function calculates the sum of squares of binomial coefficients for a given value of 'n.' It uses the factorial function to calculate C(n+1, 2n) divided by C(1, n), where C(n, k) represents the binomial coefficient.

In the main function:

An integer variable 'n' is declared and initialized with the value 4 (you can change this value as needed).

The sumofsquare function is called with the value of 'n,' and the result is printed to the standard output using cout.

*/
