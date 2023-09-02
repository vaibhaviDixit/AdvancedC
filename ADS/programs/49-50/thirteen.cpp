/*
Fermat’s little theorem states that if p is a prime number, then for any integer a, the number a p – a is an integer multiple of p.

Here p is a prime number
a^p ≡ a (mod p).

Special Case: If a is not divisible by p, Fermat’s little theorem is equivalent to the statement that a p-1-1 is an integer multiple of p.

a^(p-1) ≡ 1 (mod p)
OR
a^(p-1) % p = 1
Here a is not divisible by p.

--Problem Statement:
Write a C++ program to find modular inverse of a under modulo m using Fermat's little theorem.
Input: a = 3, m = 11
Output: Modular multiplicative inverse is 4

*/

// This program works only if m is prime.
#include <bits/stdc++.h>
using namespace std;

// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(int a, int m)
{
	if (__gcd(a, m) != 1)
		cout << "Inverse doesn't exist";

	else {

		// If a and m are relatively prime, then
		// modulo inverse is a^(m-2) mode m
		cout << "Modular multiplicative inverse is "
			<< power(a, m - 2, m);
	}
}

// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
	if (y == 0)
		return 1;
	int p = power(x, y / 2, m) % m;
	p = (p * p) % m;

	return (y % 2 == 0) ? p : (x * p) % m;
}


int main()
{
	int a = 3, m = 11;
	modInverse(a, m);
	return 0;
}

/*
It defines three functions: power, modInverse, and main.

The power function calculates x raised to the power y under modulo m using a recursive approach. It uses the property that (x^y) % m = ((x^(y/2) % m) * (x^(y/2) % m)) % m. The function computes x^y efficiently by recursively calculating x^(y/2) and then squaring the result.

The modInverse function calculates the modular inverse of a under modulo m. It takes two integer parameters, a and m. The function first checks if a and m are relatively prime by using the __gcd function (a standard library function that calculates the greatest common divisor). If they are not relatively prime (i.e., their GCD is not 1), it prints that the inverse doesn't exist. Otherwise, it calculates and prints the modular multiplicative inverse using Fermat's Little Theorem.

Fermat's Little Theorem states that if p is a prime number and a is any integer not divisible by p, then a^(p-1) ≡ 1 (mod p). Therefore, the modular inverse of a under modulo p is a^(p-2) (mod p)

*/
