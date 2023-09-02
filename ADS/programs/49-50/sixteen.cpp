/*
Given a large number n and a prime p, how to efficiently compute n! % p?

Input:  n = 5, p = 13
Output: 3
5! = 120 and 120 % 13 = 3

Input:  n = 6, p = 11
Output: 5
6! = 720 and 720 % 11 = 5

*/

// C++ program to Returns n % p using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

// Returns largest power of p that divides n!
int largestPower(int n, int p)
{
	// Initialize result
	int x = 0;

	// Calculate x = n/p + n/(p^2) + n/(p^3) + ....
	while (n) {
		n /= p;
		x += n;
	}
	return x;
}

// Utility function to do modular exponentiation. It returns (x^y) % p
int power(int x, int y, int p)
{
	int res = 1; // Initialize result
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

// Returns n! % p
int modFact(int n, int p)
{
	if (n >= p)
		return 0;

	int res = 1;

	// Use Sieve of Eratosthenes to find all primes smaller than n
	bool isPrime[n + 1];
	memset(isPrime, 1, sizeof(isPrime));
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i)
				isPrime[j] = 0;
		}
	}

	// Consider all primes found by Sieve
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			// Find the largest power of prime 'i' that divides n
			int k = largestPower(n, i);

			// Multiply result with (i^k) % p
			res = (res * power(i, k, p)) % p;
		}
	}
	return res;
}

int main()
{
	int n = 25, p = 29;
	cout << modFact(n, p);
	return 0;
}

/*
It defines three functions:

largestPower: Calculates the largest power of a prime number p that divides n!.
power: Implements modular exponentiation to calculate (x^y) % p.
modFact: Computes n! % p using the prime numbers found by the Sieve of Eratosthenes.
largestPower function:

Initializes x to 0.
Calculates x as the sum of n/p, n/(p^2), n/(p^3), and so on, where n is continuously updated as n/p.
power function:

Calculates (x^y) % p using modular exponentiation. It's an efficient way to compute large powers modulo p.
modFact function:

Checks if n >= p. If n is greater than or equal to p, it returns 0 since n! % p will be 0.
Initializes the result res to 1.
Uses the Sieve of Eratosthenes to find all prime numbers smaller than or equal to n and stores them in the isPrime array.
Loops through all prime numbers found by the sieve.
For each prime number i, it calculates the largest power of i that divides n using the largestPower function.
Multiplies res by (i^k) % p, where k is the largest power of i, using the power function. This step combines the contributions of all prime factors.
Returns the final result res.

*/
