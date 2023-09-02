/*
A Diophantine equation is a polynomial equation, usually in two or more unknowns, such that only the integral solutions are required. An Integral solution is a solution such that all the unknown variables take only integer values.

Given three integers a, b, c representing a linear equation of the form : ax + by = c. Determine if the equation has a solution such that x and y are both integral values.

Input : a = 3, b = 6, c = 9
Output: Possible

Explanation : The Equation turns out to be,
3x + 6y = 9 one integral solution would be
x = 1 , y = 1

Input : a = 3, b = 6, c = 8
Output : Not Possible


*/

// C++ program to check for solutions of diophantine equations
#include <bits/stdc++.h>
using namespace std;

//utility function to find the GCD of two numbers
int gcd(int a, int b)
{
	return (a%b == 0)? abs(b) : gcd(b,a%b);
}

// This function checks if integral solutions are possible
bool isPossible(int a, int b, int c)
{
	return (c%gcd(a,b) == 0);
}


int main()
{
	// First example
	int a = 3, b = 6, c = 9;
	isPossible(a, b, c)? cout << "Possible\n" :
						cout << "Not Possible\n";

	// Second example
	a = 3, b = 6, c = 8;
	isPossible(a, b, c)? cout << "Possible\n" :
					cout << "Not Possible\n";

	// Third example
	a = 2, b = 5, c = 1;
	isPossible(a, b, c)? cout << "Possible\n" :
					cout << "Not Possible\n";

	return 0;
}

/*

It defines a utility function called gcd to calculate the greatest common divisor (GCD) of two integers. This function uses the Euclidean algorithm to find the GCD. The gcd function takes two integers, a and b, as arguments and returns the absolute value of the GCD.

The isPossible function checks if integral solutions are possible for a given Diophantine equation. It takes three integers, a, b, and c, as arguments representing the coefficients of the equation a*x + b*y = c. The function returns true if integral solutions exist, which means that c is divisible by the GCD of a and b. Otherwise, it returns false.

*/

