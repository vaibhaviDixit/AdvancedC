/*
Given n, print the maximum number of composite numbers that sum up to n. First few composite numbers are 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, ………

Input: 90
Output: 22
Explanation: If we add 21 4's, then we
get 84 and then add 6 to it, we get 90.

Input: 10
Output: 2
Explanation: 4 + 6 = 10

*/


// CPP program to split a number into maximum number of composite numbers.
#include <bits/stdc++.h>
using namespace std;

// function to calculate the maximum number of composite numbers adding upto n
int count(int n)
{
	// 4 is the smallest composite number
	if (n < 4)
		return -1;

	// stores the remainder when n is divided
	// by 4
	int rem = n % 4;

	// if remainder is 0, then it is perfectly divisible by 4.
	if (rem == 0)
		return n / 4;

	// if the remainder is 1
	if (rem == 1) {

		// If the number is less than 9, that is 5, then it cannot be expressed as
		// 4 is the only composite number less than 5
		if (n < 9)
			return -1;

		// If the number is greater than 8, and has a remainder of 1, then express n
		// as n-9 a and it is perfectly divisibleby 4 and for 9, count 1.
		return (n - 9) / 4 + 1;
	}


	// When remainder is 2, just subtract 6 from n, so that n is perfectly divisible by 4 and count 1 for 6 which is subtracted.
	if (rem == 2)
		return (n - 6) / 4 + 1;


	// if the number is 7, 11 which cannot be expressed as sum of any composite numbers
	if (rem == 3) {
		if (n < 15)
			return -1;

		// when the remainder is 3, then subtract 15 from it and n becomes perfectly
		// divisible by 4 and we add 2 for 9 and 6, which is getting subtracted to make n perfectly divisible by 4.
		return (n - 15) / 4 + 2;
	}
}

int main()
{
	int n = 90;
	cout << count(n) << endl;

	n = 143;
	cout << count(n) << endl;
	return 0;
}

/*
The count function takes an integer n as input and returns the maximum number of composite numbers that can be added together to form n. If it's not possible to form n using composite numbers, it returns -1.

Inside the count function:

If n is less than 4, it's not possible to form it using composite numbers, so it returns -1.
The program calculates the remainder rem when n is divided by 4.
Based on the remainder rem, the program handles different cases:

If rem is 0, it means n is perfectly divisible by 4, so the function returns n / 4.

If rem is 1:

If n is less than 9, it's not possible to form it using composite numbers, so it returns -1.
Otherwise, the program subtracts 9 from n and divides the result by 4, adding 1. This accounts for the fact that 9 is a composite number, and the rest of the number is divisible by 4.
If rem is 2, the program subtracts 6 from n and divides the result by 4, adding 1. This accounts for the fact that 6 is a composite number, and the rest of the number is divisible by 4.

If rem is 3:

If n is less than 15, it's not possible to form it using composite numbers, so it returns -1.
Otherwise, the program subtracts 15 from n and divides the result by 4, adding 2. This accounts for the fact that 9 and 6 (both composite numbers) are subtracted to make n perfectly divisible by 4.
In the main function, two sample values of n, 90 and 143, are provided. The count function is called for each value, and the program prints the maximum number of composite numbers that can be added together to form n.

*/
