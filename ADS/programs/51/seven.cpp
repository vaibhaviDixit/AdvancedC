/*
Given integers n, a, b and c, the task is to find the maximum value of x + y + z such that ax + by + cz = n.

Input:
n = 10
a = 5
b = 3
c = 4
Output:
3
Explanation:
x = 0, y = 2 and z = 1

Input:
n = 50
a = 8
b = 10
c = 2
Output:
25

*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum value of (x + y + z) such that (ax + by + cz = n)
int maxResult(int n, int a, int b, int c)
{
	int maxVal = 0;

	// i represents possible values of a * x
	for (int i = 0; i <= n; i += a)
	{
		// j represents possible values of b * y
		for (int j = 0; j <= n - i; j += b)
		{
			float z = (float)(n - (i + j)) / (float)(c);

			// If z is an integer
			if (floor(z) == ceil(z))
			{
				int x = i / a;
				int y = j / b;
				maxVal = max(maxVal, x + y + (int)z);
			}
		}
	}

	return maxVal;
}


int main()
{
	int n = 10, a = 5, b = 3, c = 4;

	// Function Call
	cout << maxResult(n, a, b, c);

	return 0;
}

/*

int maxResult(int n, int a, int b, int c): This is a function named maxResult that takes four integer arguments: n (the target value), a, b, and c (coefficients of x, y, and z in the equation ax + by + cz = n). It calculates and returns the maximum value of the expression (x + y + z) while satisfying the given equation.

Inside the function:

int maxVal = 0;: It initializes a variable maxVal to store the maximum value of (x + y + z) found so far, starting with 0.

The program uses nested loops to iterate through possible values of x and y. The outer loop (i) represents possible values of a * x, and the inner loop (j) represents possible values of b * y.

float z = (float)(n - (i + j)) / (float)(c);: It calculates the value of z based on the given equation. It computes z as (n - (i + j)) / c and stores it as a floating-point number.

The program checks if z is an integer by comparing its floor and ceiling values. If they are equal, it means z is an integer, and the equation ax + by + cz = n can be satisfied.

If z is an integer, the program calculates the values of x, y, and z by dividing i, j, and z by a, b, and c respectively. It then calculates the expression (x + y + z) and updates maxVal if the calculated value is greater than the current maxVal.

Finally, the function returns the maximum value maxVal.

*/
