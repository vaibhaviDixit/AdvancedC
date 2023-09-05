/*
Given three integers X, Y and N, the task is to find the Nth term of the series f[i] = f[i – 1] – f[i – 2], i > 1 where f[0] = X and f[1] = Y.

Input: X = 2, Y = 3, N = 3
Output: -2
The series will be 2 3 1 -2 -3 -1 2 and f[3] = -2

Input: X = 3, Y = 7, N = 8
Output: 4

*/


// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the Nth term of the given series
int findNthTerm(int x, int y, int n)
{
	int f[6];

	// First and second term of the series
	f[0] = x;
	f[1] = y;

	// Find first 6 terms
	for (int i = 2; i <= 5; i++)
		f[i] = f[i - 1] - f[i - 2];

	// Return the Nth term
	return f[n % 6];
}

int main()
{
	int x = 2, y = 3, n = 3;
	cout << findNthTerm(x, y, n);

	return 0;
}

/*
int findNthTerm(int x, int y, int n): This is a function named findNthTerm that takes three integer arguments: x (the first term of the series), y (the second term of the series), and n (the position of the term to be found). It calculates and returns the Nth term of the series based on the given recurrence relation.

Inside the function:

int f[6];: It declares an array f of size 6 to store the first 6 terms of the series. This size is chosen because the recurrence relation will repeat every 6 terms.

The first two terms of the series f[0] and f[1] are initialized with x and y, respectively.

The for loop iterates from i = 2 to i = 5 to calculate the next 4 terms of the series based on the recurrence relation f[i] = f[i - 1] - f[i - 2].

After calculating the first 6 terms of the series, the function returns the Nth term using the formula f[n % 6]. Since the series repeats every 6 terms, it uses the remainder of n when divided by 6 to find the corresponding term within the first 6 terms.

*/
