/*
Given two numbers ‘num’ and ‘divisor’, find remainder when ‘num’ is divided by ‘divisor’. The use of modulo or % operator is not allowed.

Input:  num = 100, divisor = 7
Output: 2

Input:  num = 30, divisor = 9
Output: 3


*/

// C++ program to find remainder without using modulo operator
#include <iostream>
using namespace std;

// This function returns remainder of num/divisor without using % (modulo) operator
int getRemainder(int num, int divisor)
{
	return (num - divisor * (num / divisor));
}

int main()
{
	// cout << 100 %0;
	cout << getRemainder(100, 7);
	return 0;
}

/*
It defines a function getRemainder that takes two integers, num and divisor, as input parameters.

Inside the getRemainder function, it calculates the remainder of num divided by divisor using the following expression:

num - divisor * (num / divisor)
num / divisor calculates the integer quotient of the division.
divisor * (num / divisor) calculates the largest multiple of divisor that is less than or equal to num.
Subtracting this multiple from num gives the remainder.
The getRemainder function returns the calculated remainder.

*/
