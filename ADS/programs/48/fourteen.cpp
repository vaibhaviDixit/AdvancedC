/*
Given a positive integer n, write a function to find if it is a power of 2 or not using bit manipulation.

Input : n = 4
Output : Yes
Explanation: 22 = 4

Input : n = 32
Output : Yes
Explanation: 25 = 32

*/

#include <bits/stdc++.h>
using namespace std;

/* Function to check if x is power of 2*/
bool isPowerOfTwo(int n)
{
	/* First x in the below expression is for the case when
	* x is 0 */
	int cnt = 0;
	while (n > 0) {
		if ((n & 1) == 1) {
			cnt++;
		}
		n = n >> 1; // keep dividing n by 2 using right
					// shift operator
	}

	if (cnt == 1) { // if cnt = 1 only then it is power of 2
		return true;
	}
	return false;
}

int main()
{
	// Function call
	isPowerOfTwo(31) ? cout << "Yes\n" : cout << "No\n";
	isPowerOfTwo(64) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

/*
It defines a function called isPowerOfTwo that takes an integer n as its parameter and returns a boolean value (true or false) indicating whether n is a power of 2 or not.

Inside the isPowerOfTwo function:

It initializes an integer variable cnt to 0. This variable will be used to count the number of set bits (1s) in the binary representation of n.

It enters a while loop that continues as long as n is greater than 0.

Inside the loop:

It checks whether the least significant bit (LSB) of n is set to 1 using the bitwise AND operation (n & 1). If the result is 1, it means there is a set bit in the binary representation of n, so it increments the cnt variable.

It then right-shifts n by one position using the right shift operator (n >> 1). This operation effectively divides n by 2, discarding its LSB.

After the loop, it checks whether cnt is equal to 1. If cnt is 1, it means there is only one set bit in the binary representation of n, which indicates that n is a power of 2. In this case, the function returns true. Otherwise, it returns false

*/
