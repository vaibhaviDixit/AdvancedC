/*
Given three numbers n, r and p, compute the value of nCr mod p. Here p is a prime number greater than n. Here nCr is Binomial Coefficient.
Compute nCr%p using Fermat Little Theorem.

Input:  n = 10, r = 2, p = 13
Output: 6
Explanation: 10C2 is 45 and 45 % 13 is 6.

Input:  n = 6, r = 2, p = 13
Output: 2

*/

// A modular inverse based solution to compute nCr % p
#include <bits/stdc++.h>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
unsigned long long power(unsigned long long x, int y, int p)
{
	unsigned long long res = 1; // Initialize result

	x = x % p; // Update x if it is more than or
	// equal to p

	while (y > 0) {

		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
	return power(n, p - 2, p);
}
unsigned long long mul(unsigned long long x,
					unsigned long long y, int p)
{
	return x * 1ull * y % p;
}
unsigned long long divide(unsigned long long x,
						unsigned long long y, int p)
{
	return mul(x, modInverse(y, p), p);
}
// Returns nCr % p using Fermat's little theorem.
unsigned long long nCrModPFermat(unsigned long long n,
								int r, int p)
{
	// If n<r, then nCr should return 0
	if (n < r)
		return 0;
	// Base case
	if (r == 0)
		return 1;
	// if n-r is less calculate nCn-r
	if (n - r < r)
		return nCrModPFermat(n, n - r, p);

	// Fill factorial array so that we can find all factorial of r, n and n-r
	unsigned long long res = 1;
	// keep multiplying numerator terms and dividing denominator terms in res
	for (int i = r; i >= 1; i--)
		res = divide(mul(res, n - i + 1, p), i, p);
	return res;
}

int main()
{
	// p must be a prime greater than n.
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "
		<< nCrModPFermat(n, r, p);
	return 0;
}

/*
It defines several functions: power, modInverse, mul, divide, and nCrModPFermat, as well as the main function.

The power function efficiently calculates x raised to the power y modulo p using an iterative approach. It uses bitwise operations to reduce the time complexity to O(log y).

The modInverse function calculates the modular multiplicative inverse of a number n modulo p. It uses the power function to calculate n^(p-2) % p, which is the modular inverse of n under modulo p. This is based on Fermat's Little Theorem, which states that if p is prime and n is not divisible by p, then n^(p-1) ≡ 1 (mod p), and consequently, n^(p-2) is the modular inverse of n.

The mul and divide functions perform modular multiplication and division, respectively, to avoid integer overflow when dealing with large numbers.

The nCrModPFermat function calculates nCr modulo p using Fermat's Little Theorem and the formula:

nCr % p = (n! * (r!)^(-1) * ((n-r)!)^(-1)) % p

It efficiently computes this value by iteratively multiplying the numerator terms and dividing the denominator terms while keeping the result modulo p.

*/


