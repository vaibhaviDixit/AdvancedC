/*
Compute the parity of a number using XOR and table look-up
Parity of a number refers to whether it contains an odd or even number of 1-bits. The number has “odd parity”, if it contains odd number of 1-bits and is
“even parity” if it contains even number of 1-bits.

1 --> parity of the set is odd
0 --> parity of the set is even
Examples:

Input : 254
Output : Odd Parity
Explanation : Binary of 254 is 11111110.
There are 7 ones. Thus, parity is odd.

Input : 1742346774
Output : Even

*/

// CPP program to illustrate Compute the parity of a number using XOR
#include <bits/stdc++.h>

// Generating the look-up table while pre-processing
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

// LOOK_UP is the macro expansion to generate the table
unsigned int table[256] = { LOOK_UP };

// Function to find the parity
int Parity(int num)
{
	// Number is considered to be of 32 bits
	int max = 16;

	// Dividing the number into 8-bit chunks while performing X-OR
	while (max >= 8) {
		num = num ^ (num >> max);
		max = max / 2;
	}

	// Masking the number with 0xff (11111111)to produce valid 8-bit result
	return table[num & 0xff];
}

int main()
{
	unsigned int num = 1742346774;

	// Result is 1 for odd parity, 0 for even parity
	bool result = Parity(num);

	// Printing the desired result
	result ? std::cout << "Odd Parity" :
			std::cout << "Even Parity";

	return 0;
}

/*

Macro Definitions:

The program defines macros P2(n), P4(n), and P6(n) to generate lookup tables for computing parity. These macros expand to the bitwise XOR of n with various bit patterns to calculate parity.
The LOOK_UP macro combines these patterns to create a lookup table for 8-bit values (0 to 255). This table is stored in the table array.
An unsigned integer array table is declared and initialized with the computed lookup values using the LOOK_UP macro.

The Parity function takes an integer num as input and returns the parity of that number.

It assumes that the number is represented using 32 bits.
The function divides the number into 8-bit chunks and iteratively applies XOR operations to calculate the parity.
It initializes max to 16 (half of 32) and iteratively performs XOR operations by shifting the number to the right by max.
The result is masked with 0xff (11111111 in binary) to produce a valid 8-bit result.
The final result is obtained from the lookup table table based on the masked 8-bit value.
In the main function:

An unsigned integer num is initialized with the value 1742346774.
The program calls the Parity function with num as an argument to calculate the parity.

The result of the parity calculation is stored in a boolean variable result. It will be true for odd parity and false for even parity.

The program prints the result to the console using std::cout. If result is true, it prints "Odd Parity"; otherwise, it prints "Even Parity."

*/

