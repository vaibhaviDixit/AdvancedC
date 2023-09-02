/*
Given a number x and two positions (from the right side) in the binary representation of x, write a function that swaps n bits at the given two positions
and returns the result. It is also given that the two sets of bits do not overlap.

Input:
x = 47 (00101111)
p1 = 1 (Start from the second bit from the right side)
p2 = 5 (Start from the 6th bit from the right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)


Input:
x = 28 (11100)
p1 = 0 (Start from first bit from right side)
p2 = 3 (Start from 4th bit from right side)
n = 2 (No of bits to be swapped)
Output:
7 (00111)

*/

// C++ Program to swap bits in a given number
#include <bits/stdc++.h>
using namespace std;

int swapBits(unsigned int x, unsigned int p1,
			unsigned int p2, unsigned int n)
{
	/* Move all bits of first set to rightmost side */
	unsigned int set1 = (x >> p1) & ((1U << n) - 1);

	/* Move all bits of second set to rightmost side */
	unsigned int set2 = (x >> p2) & ((1U << n) - 1);

	/* Xor the two sets */
	unsigned int Xor = (set1 ^ set2);

	/* Put the Xor bits back to their original positions */
	Xor = (Xor << p1) | (Xor << p2);

	/* Xor the 'Xor' with the original number so that the
	two sets are swapped */
	unsigned int result = x ^ Xor;

	return result;
}

int main()
{
	int res = swapBits(28, 0, 3, 2);
	cout << "Result = " << res;
	return 0;
}

/*
x: The unsigned integer in which bits need to be swapped.
p1: The position of the first set of bits to be swapped (counting from the right, starting at 0).
p2: The position of the second set of bits to be swapped.
n: The number of bits in each set to be swapped.
Here's how the program works:

The swapBits function starts by moving the bits of the first set to the rightmost side and the bits of the second set to the rightmost side, effectively isolating these two sets of bits.

set1 is obtained by right-shifting x by p1 positions and then using a bitmask of (1U << n) - 1 to extract the rightmost n bits.
set2 is similarly obtained by right-shifting x by p2 positions and applying the same bitmask.
Next, the program computes the XOR (^) of set1 and set2 and stores it in the variable Xor. This XOR operation flips the bits that need to be swapped.

To put the XOR bits back in their original positions, the program left-shifts Xor by p1 positions and also by p2 positions. This positions the XOR bits where they should be after the swap.

Finally, the program performs a bitwise XOR between the original number x and the modified Xor value to swap the two sets of bits.

The main function demonstrates the swapBits function by swapping 2 bits at positions 0 and 3 in the number 28. The result is stored in the variable res and printed to the console.

The program prints "Result = " followed by the value of res.

The program returns 0 to indicate successful execution and then terminates.

*/

