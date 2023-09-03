/*
Given a number N, generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit.

Input: N = 2
Output: 00 01 11 10

Input: N = 3
Output: 000 001 011 010 110 111 101 100

*/

#include <bits/stdc++.h>
using namespace std;

void GreyCode(int n)
{
	// power of 2
	for (int i = 0; i < (1 << n); i++)
	{
		// Generating the decimal values of gray code then using
		// bitset to convert them to binary form
		int val = (i ^ (i >> 1));

		// Using bitset
		bitset<32> r(val);

		// Converting to string
		string s = r.to_string();
		cout << s.substr(32 - n) << " ";
	}
}


int main()
{
	int n;
	n = 1;

	// Function call
	GreyCode(n);

	return 0;
}

/*
It defines a function called GreyCode that takes an integer parameter n, representing the number of bits for the Gray code sequence.

Inside the GreyCode function:

It iterates from 0 to 2^n - 1 (inclusive), which corresponds to all possible values of an n-bit Gray code.

For each iteration, it calculates the Gray code value using the formula (i ^ (i >> 1)). This formula XORs the current iteration value i with a right-shifted version of i. This operation generates the Gray code value.

It then converts the decimal Gray code value into its binary representation using the bitset<32> class. This class allows converting decimal values into binary strings of fixed length (32 bits in this case).

After converting the decimal Gray code value to binary, it converts it to a string and takes a substring starting from the 32 - n position. This step is done to ensure that the output displays only the relevant n bits of the Gray code, as the bitset might include leading zeros.

Finally, it prints each generated Gray code as a binary string followed by a space.

In the main function:

It declares an integer variable n and assigns it a value of 4, indicating that the Gray code should be generated for 4 bits.

It calls the GreyCode function with the value of n

*/
