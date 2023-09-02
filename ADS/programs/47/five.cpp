/*
Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians.

Following are a few examples:

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

Write a C++ program to print a fraction in Egyptian Form using Greedy Algorithm

Input:  numerator = 6, denominator = 14
Output: Egyptian Fraction representation of 6/14 is
1/3 + 1/11 + 1/231

*/


#include <bits/stdc++.h>
using namespace std;
void egyptianFraction(int n, int d)
{
//When Both Numerator and denominator becomes zero then we simply return;
	if (d == 0 || n == 0)
		return;
	if (d % n == 0) {
		cout << "1/" << d / n;
		return;
	}
	if (n % d == 0) {
		cout << n / d;
		return;
	}
	if (n > d) {
		cout << n / d << " + ";
		egyptianFraction(n % d, d);
		return;
	}
	int x = d / n + 1;
	cout << "1/" << x << " + ";
	egyptianFraction(n * x - d, d * x);
}
int main()
{
	int numerator = 6, denominator = 14;
	cout << "Egyptian Fraction representation of "
		<< numerator << "/" << denominator << " is"
		<< endl;
	egyptianFraction(numerator, denominator);
	return 0;
}

/*
The egyptianFraction function takes two integers, n (numerator) and d (denominator), as input and prints the Egyptian fraction representation of n/d. It uses a recursive approach to find the unit fractions.

Inside the egyptianFraction function:

The base cases are checked first. If d is 0 or n is 0, the function returns immediately, as there's nothing to calculate.

If d is divisible by n (i.e., d % n == 0), it means that n is a divisor of d, and we can represent it as a single unit fraction 1/(d/n).

If n is divisible by d (i.e., n % d == 0), it means that d is a divisor of n, and we can represent it as an integer value n/d.

If neither of the above conditions is met, it means that n is less than d, and we need to find a unit fraction to add to our representation. We find the largest integer x such that d/n < 1/x. This integer x is calculated as d/n + 1.

We print "1/x + " to represent the unit fraction 1/x, and then recursively call egyptianFraction with the new values of n and d. The new values are calculated as n * x - d and d * x, respectively.

In the main function, sample values for numerator and denominator are provided. The program then calls egyptianFraction to find the Egyptian fraction representation of the given fraction and prints the result.

*/
