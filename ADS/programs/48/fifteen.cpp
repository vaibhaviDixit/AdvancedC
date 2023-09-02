/*
Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set
bit the answer should be -1. Position of set bit ‘1’ should be counted starting with 1 from the LSB side in the binary representation of the number.

Input: N = 2
Output: 2

Input: N = 5
Output: -1

*/

// C++ program to find position of only set bit in a given number
#include <bits/stdc++.h>
using namespace std;

// A utility function to check whether n is power of 2 or not
int isPowerOfTwo(unsigned n)
{
	return n && (!(n & (n - 1)));
}

// Returns position of the only set bit in 'n'
int findPosition(unsigned n)
{
	if (!isPowerOfTwo(n))
		return -1;

	unsigned count = 0;

	// One by one move the only set bit to right till it reaches end
	while (n)
	{
		n = n >> 1;

		// increment count of shifts
		++count;
	}

	return count;
}

int main(void)
{
	int n = 0;
	int pos = findPosition(n);
	(pos == -1) ? cout<<"n = "<<n<<", Invalid number\n" :
					cout<<"n = "<<n<<", Position "<< pos<<endl;

	n = 12;
	pos = findPosition(n);
	(pos == -1) ? cout<<"n = "<<n<<", Invalid number\n" :
			cout<<"n = "<<n<<", Position "<< pos<<endl;

	n = 128;
	pos = findPosition(n);
	(pos == -1) ? cout<<"n = "<<n<<", Invalid number\n" :
				cout<<"n = "<<n<<", Position "<< pos<<endl;

	return 0;
}

/*
It defines a utility function called isPowerOfTwo that checks whether a given integer n is a power of 2 or not. The function returns 1 (true) if n is a power of 2 and 0 (false) otherwise.

The findPosition function takes an unsigned integer n as its parameter and returns the position of the only set bit (1 bit) in n.

Inside the findPosition function:

It first checks whether the input number n is a power of 2 using the isPowerOfTwo function. If n is not a power of 2, it returns -1 to indicate that the input is invalid.

If n is a power of 2, it initializes an unsigned integer variable count to 0. This variable will be used to keep track of the position of the set bit.

It enters a while loop that continues until n becomes zero. Inside the loop:

It right-shifts n by one position using the right shift operator (n >> 1) to move the set bit towards the least significant bit (LSB).

It increments the count variable to keep track of the number of right shifts performed.

After the loop, it returns the value of count, which represents the position of the only set bit.

*/

