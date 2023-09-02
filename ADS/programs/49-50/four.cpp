/*
Given a number n, print all primes smaller than or equal to n.

Input:  n = 10
Output: 2, 3, 5, 7

Input:  n = 20
Output: 2, 3, 5, 7, 11, 13, 17, 19

*/

// C++ program to print primes smaller than n using Sieve of Sundaram.
#include <bits/stdc++.h>
using namespace std;

// Prints all prime numbers smaller
int SieveOfSundaram(int n)
{
	// In general Sieve of Sundaram, produces primes smaller than (2*x + 2) for a number given number x.
	// Since we want primes smaller than n, we reduce n to half
	int nNew = (n-1)/2;

	// This array is used to separate numbers of the form i+j+2ij
	// from others where 1 <= i <= j
	bool marked[nNew + 1];

	// Initialize all elements as not marked
	memset(marked, false, sizeof(marked));

	// Main logic of Sundaram. Mark all numbers of the
	// form i + j + 2ij as true where 1 <= i <= j
	for (int i=1; i<=nNew; i++)
		for (int j=i; (i + j + 2*i*j) <= nNew; j++)
			marked[i + j + 2*i*j] = true;

	// Since 2 is a prime number
	if (n > 2)
		cout << 2 << " ";

	// Print other primes. Remaining primes are of the form
	// 2*i + 1 such that marked[i] is false.
	for (int i=1; i<=nNew; i++)
		if (marked[i] == false)
			cout << 2*i + 1 << " ";
}

int main(void)
{
	int n = 20;
	SieveOfSundaram(n);
	return 0;
}

/*

It defines a function called SieveOfSundaram that takes an integer n as a parameter. This function will find and print all prime numbers smaller than n.

Inside the SieveOfSundaram function:

It calculates a new value nNew by subtracting 1 from n and then dividing the result by 2. This is because the Sieve of Sundaram algorithm works with numbers less than (2*x + 2).

It initializes a boolean array called marked of size nNew + 1 to keep track of marked numbers. Initially, all elements in the marked array are set to false.

It uses a nested loop to iterate through numbers i and j in the range [1, nNew]. For each pair of numbers (i, j) where i <= j, it calculates a number of the form i + j + 2*i*j and marks it as true in the marked array. This step essentially eliminates numbers of this form from the list of potential prime candidates.

After marking numbers according to the Sieve of Sundaram algorithm, the program prints the number 2 as it is the only even prime number.

It then iterates through the marked array to print the remaining prime numbers. The remaining prime numbers are of the form 2*i + 1 for all i where marked[i] is false.

*/


