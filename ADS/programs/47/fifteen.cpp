/*
Given a paper of size, A x B. Task is to cut the paper into squares of any size. Find the minimum number of squares that can be cut from the paper.

Input  : 13 x 29
Output : 9
Explanation :
2 (squares of size 13x13) +
4 (squares of size 3x3) +
3 (squares of size 1x1)=9

Input  : 4 x 5
Output : 5
Explanation :
1 (squares of size 4x4) +
4 (squares of size 1x1)

*/


// C++ program to find minimum number of squares to cut a paper.
#include<bits/stdc++.h>
using namespace std;

// Returns min number of squares needed
int minimumSquare(int a, int b)
{
	long long result = 0, rem = 0;

	// swap if a is small size side .
	if (a < b)
		swap(a, b);

	// Iterate until small size side is
	// greater than 0
	while (b > 0)
	{
		// Update result
		result += a/b;

		long long rem = a % b;
		a = b;
		b = rem;
	}

	return result;
}

int main()
{
	int n = 10, m = 10;
	cout << minimumSquare(n, m);
	return 0;
}

/*
The minimumSquare function is defined, which calculates the minimum number of squares required to cut a paper with dimensions a x b.

Inside the function:

A result variable of type long long is initialized to store the result (the minimum number of squares).
A rem variable is declared to keep track of the remainder.
The function starts by swapping a and b if a is smaller than b. This ensures that a always represents the larger dimension.
The program enters a loop that continues until the smaller dimension, b, becomes zero.

In each iteration:
The result is updated by adding the integer division of a by b. This represents the number of squares that can be cut from the larger dimension.
The remainder is calculated by taking a % b.
a is updated to b, and b is updated to the remainder rem.
Finally, the result variable holds the minimum number of squares needed to cut the paper into equal-sized squares, and it is returned from the function.

In the main function, sample values for n (length) and m (width) are provided. The minimumSquare function is called with these values, and the result is printed.

*/
