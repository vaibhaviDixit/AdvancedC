/*
Write a Cpp program for  Count of numbers (x) smaller than or equal to n such that n+x = n^x:
here unset bits means zero bits

Input: 15
Output: 1

*/


#include <bits/stdc++.h>
using namespace std;

// function to count number of values less than
// equal to n that satisfy the given condition
int countValues(int n)
{
	// unset_bits keeps track of count of un-set
	// bits in binary representation of n
	int unset_bits=0;
	while (n)
	{
		if ((n & 1) == 0)
			unset_bits++;
		n=n>>1;
	}

	// Return 2 ^ unset_bits i.e. pow(2,count of zero bits)
	return 1 << unset_bits;
}

int main()
{
	int n = 15;
	cout << countValues(n);
	return 0;
}

/*

The countValues function takes an integer 'n' as input and returns the count of values less than or equal to 'n' that satisfy the given condition.

Inside the countValues function, there is a variable named unset_bits initialized to 0. This variable is used to keep track of the count of unset (zero) bits in the binary representation of 'n'.

The program enters a while loop that continues until 'n' becomes zero. In each iteration of the loop:

It checks if the least significant bit of 'n' is unset (i.e., it's zero) using the bitwise AND operation (n & 1) == 0. If the least significant bit is zero, it increments the unset_bits count.
It right-shifts 'n' by one bit (n = n >> 1) to examine the next bit.
After exiting the loop, the program calculates the result by using the formula 1 << unset_bits. This formula calculates 2 raised to the power of the count of unset bits in the binary representation of 'n'.

In the main function:

An integer 'n' is set to 15.
The countValues function is called with 'n' as an argument.
The program prints the result, which is the count of values less than or equal to 15 that satisfy the condition.

*/
