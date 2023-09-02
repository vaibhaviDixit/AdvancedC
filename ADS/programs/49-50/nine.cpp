/*
Given two integers A and M, find the modular multiplicative inverse of A under modulo M.
The modular multiplicative inverse is an integer X such that:

A X = 1 (mod M)

Input: A = 3, M = 11
Output: 4

Explanation: Since (4*3) mod 11 = 1, 4 is modulo inverse of 3(under 11). One might think, 15 also as a valid output as “(15*3) mod 11”
is also 1, but 15 is not in range {1, 2, … 10}, so not valid.

Input:  A = 10, M = 17
Output: 12

*/


// C++ program to find multiplicative modulo inverse using Extended Euclid algorithm.
#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y);

// Function to find modulo inverse of a
void modInverse(int A, int M)
{
	int x, y;
	int g = gcdExtended(A, M, &x, &y);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else {

		// m is added to handle negative x
		int res = (x % M + M) % M;
		cout << "Modular multiplicative inverse is " << res;
	}
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{

	// Base Case
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}

	// To store results of recursive call
	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}
int main()
{
	int A = 3, M = 11;

	// Function call
	modInverse(A, M);
	return 0;
}

/*
It defines a function gcdExtended for calculating the greatest common divisor (GCD) of two integers a and b using the Extended Euclidean Algorithm. The function also computes the values of x and y such that ax + by = gcd(a, b). This function takes four parameters: a, b, x, and y.

In the base case (when a becomes 0), the function sets x to 0 and y to 1 and returns b.

In the recursive case, it calls itself with b % a as the new a and a as the new b. It also receives the values of x1 and y1 from the recursive call.

The function then updates the values of x and y using the results of the recursive call: *x = y1 - (b / a) * x1 and *y = x1.

Finally, it returns the GCD of a and b.

The modInverse function calculates the modular multiplicative inverse of a number A modulo M using the Extended Euclidean Algorithm. It takes two parameters: A and M.

It first calls the gcdExtended function with A and M to calculate the GCD and obtain the values of x and y.

If the GCD is not equal to 1, it prints "Inverse doesn't exist" because a modular multiplicative inverse does not exist in this case.

If the GCD is 1, it calculates the modular multiplicative inverse res by taking (x % M + M) % M. This step ensures that the result is always non-negative.

Finally, it prints the calculated modular multiplicative inverse.

*/


