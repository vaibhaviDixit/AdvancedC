/*
The Euclidean algorithm is a way to find the greatest common divisor of two positive integers. GCD of two numbers is the largest number that divides both
of them. A simple way to find GCD is to factorize both numbers and multiply common prime factors.
Write a C++ program to find GCD using Euclidean Algorithm

Input: 10 15
Output: GCD(10, 15) = 5

Input: 35 10
Output: GCD(35, 10) = 5

Input: 31 2
Output: GCD(31, 2) = 1

*/

// C++ program to demonstrate Basic Euclidean Algorithm

#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	int a = 10, b = 15;

	// Function call
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	a = 35, b = 10;
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	a = 31, b = 2;
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	return 0;
}

/*
It defines a function called gcd that calculates and returns the GCD of two integers, a and b. This function uses the recursive implementation of the Euclidean algorithm.

Inside the gcd function:

If a is equal to 0, it returns b as the GCD. This is the base case of the recursion.

If a is not equal to 0, it recursively calls the gcd function with arguments b % a and a. This step repeatedly calculates the remainder of b divided by a and uses the result as the new value of a, while b becomes the old value of a. The recursion continues until a becomes 0, at which point the GCD is found.

*/
