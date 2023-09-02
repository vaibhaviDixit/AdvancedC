/*
Given three integers a, b, and c representing a linear equation of the form: ax + by = c. The task is to find the initial integral solution of the given
equation if a finite solution exists.


Input: a = 4, b = 18, c = 10
Output: x = -20, y = 5

Explanation: (-20)*4 + (5)*18 = 10

Input: a = 9, b = 12, c = 5
Output: No Solutions exists


*/

#include <bits/stdc++.h>
using namespace std;

// Function to implement the extended euclid algorithm
int gcd_extend(int a, int b,
			int& x, int& y)
{
	// Base Case
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	// Recursively find the gcd
	else {
		int g = gcd_extend(b,
						a % b, x, y);
		int x1 = x, y1 = y;
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}
}

// Function to print the solutions of the given equations ax + by = c
void print_solution(int a, int b, int c)
{
	int x, y;
	if (a == 0 && b == 0) {

		// Condition for infinite solutions
		if (c == 0) {
			cout
				<< "Infinite Solutions Exist"
				<< endl;
		}

		// Condition for no solutions exist
		else {
			cout
				<< "No Solution exists"
				<< endl;
		}
	}
	int gcd = gcd_extend(a, b, x, y);

	// Condition for no solutions exist
	if (c % gcd != 0) {
		cout
			<< "No Solution exists"
			<< endl;
	}
	else {

		// Print the solution
		cout << "x = " << x * (c / gcd)
			<< ", y = " << y * (c / gcd)
			<< endl;
	}
}

int main(void)
{
	int a, b, c;

	// Given coefficients
	a = 4;
	b = 18;
	c = 10;

	// Function Call
	print_solution(a, b, c);
	return 0;
}

/*
It defines a function called gcd_extend to implement the extended Euclidean algorithm. This algorithm not only calculates the greatest common divisor (GCD) of two integers a and b but also finds the values of x and y such that ax + by = gcd(a, b). This function takes four parameters: a, b, x, and y.

In the base case (when b is 0), the function sets x to 1, y to 0, and returns a as the GCD.

In the recursive case, the function calculates the GCD recursively by calling itself with parameters b and a % b. It also calculates temporary variables x1 and y1. Then, it updates x and y using the formula:

x = y1;
y = x1 - (a / b) * y1;
Finally, it returns the GCD.

The print_solution function is responsible for printing the solutions of the linear Diophantine equation ax + by = c. It takes three parameters: a, b, and c.

First, it checks if both a and b are zero. If so, it checks if c is also zero, indicating infinitely many solutions, or if c is nonzero, indicating no solutions.

If a or b is not zero, it calculates the GCD of a and b using the gcd_extend function and stores it in the variable gcd.

It then checks if c is divisible by the GCD. If not, it prints "No Solution exists."

If c is divisible by the GCD, it calculates the values of x and y that satisfy the equation ax + by = c and prints these values.

*/

