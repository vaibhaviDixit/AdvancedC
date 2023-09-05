/*
Given four integers a, b, c, d ( upto 10^6 ). The task is to Find the number of solutions for x < y, where a <= x <= b and c <= y <= d
and x, y integers.


Input: a = 2, b = 3, c = 3, d = 4
Output: 3

Input: a = 3, b = 5, c = 6, d = 7
Output: 6

*/

// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// function to Find the number of solutions for x < y,
// where a <= x <= b and c <= y <= d and x, y integers.
int NumberOfSolutions(int a, int b, int c, int d)
{
	// to store answer
	int ans = 0;

	// iterate explicitly over all possible values of x
	for (int i = a; i <= b; i++)
		if (d >= max(c, i + 1))
			ans += d - max(c, i + 1) + 1;

	// return answer
	return ans;
}

int main()
{
	int a = 2, b = 3, c = 3, d = 4;

	// function call
	cout << NumberOfSolutions(a, b, c, d);

	return 0;
}

/*
int NumberOfSolutions(int a, int b, int c, int d): This is a function named NumberOfSolutions that takes four integers, a, b, c, and d, as arguments and returns an integer. It calculates the number of solutions for the inequality x < y, where x falls within the range [a, b] and y falls within the range [c, d].

Inside the function:

int ans = 0;: It initializes a variable ans to store the count of solutions, starting with 0.

The for loop iterates through all possible values of x in the range [a, b]:

for (int i = a; i <= b; i++)

Inside the loop, it checks whether there are valid values of y in the range [c, d] such that x < y. This condition is checked by ensuring that d is greater than or equal to the maximum of c and i + 1.

If such valid values of y exist, it calculates the number of valid y values that satisfy the inequality x < y as (d - max(c, i + 1) + 1) and adds this count to the ans variable.

After the loop, the function returns the final count of solutions stored in the ans variable.

*/
