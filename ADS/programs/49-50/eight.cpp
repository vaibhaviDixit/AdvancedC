/*
Consider two cars A and B, running infinitely (either clockwise or anti-clockwise) on a circular road. Given the speed of both the cars a and b.
If a or b is positive, indicate they are moving in clockwise, Else they are moving in the anti-clockwise direction. The task is to find the number of distinct points they will meet each other at.

Input : a = 1, b = -1
Output : 2

Explanation
Car A is moving clockwise while Car B is moving anti-clockwise but their
speeds are same, so they will meet at two points i.e at the starting point
and diametrically corresponding opposite point on the road.

Input : a = 1, b = 2
Output : 1

*/

// CPP Program to find number of distinct point of meet on a circular road
#include <bits/stdc++.h>
using namespace std;

// Returns the GCD of two number.
int gcd(int a, int b)
{
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

// Returns the number of distinct meeting points.
int numberOfmeet(int a, int b)
{
	int ans;

	// Find the relative speed.
	if (a > b)
		ans = a - b;
	else
		ans = b - a;

	// convert the negative value to positive.
	if (a < 0)
		a = a * (-1);

	if (b < 0)
		b = b * (-1);

	return ans / gcd(a, b);
}

// Driver Code
int main()
{
	int a = 1, b = -1;

	cout << numberOfmeet(a, b) << endl;
	return 0;
}


/*
It defines a function called gcd to calculate the greatest common divisor (GCD) of two integers a and b. This function uses the Euclidean algorithm to calculate the GCD iteratively by finding the remainder of the division operation until the remainder becomes zero. The GCD is returned as the result.

The numberOfmeet function calculates the number of distinct meeting points for two vehicles moving at speeds a and b. It takes two parameters: a (speed of the first vehicle) and b (speed of the second vehicle).

It first calculates the relative speed of the two vehicles by taking the absolute difference between a and b and assigns it to the variable ans.

To ensure that the relative speed is always positive, the program checks if a and b are negative and converts them to positive values.

Finally, it divides the relative speed by the GCD of a and b (calculated using the gcd function) to find the number of distinct meeting points and returns this value.

*/
