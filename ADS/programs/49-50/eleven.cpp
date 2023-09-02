/*
Euler’s Totient function Φ (n) for an input n is the count of numbers in {1, 2, 3, …, n-1} that are relatively prime to n, i.e., the numbers whose GCD
(Greatest Common Divisor) with n is 1.

Φ(1) = 1
gcd(1, 1) is 1

Φ(2) = 1
gcd(1, 2) is 1, but gcd(2, 2) is 2.


Write a C++ program to calculate Euler's Totient Function

Input: 3
Output: 2

Input: 10
Output: 4

*/


#include <iostream>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
	unsigned int result = 1;
	for (int i = 2; i < n; i++)
		if (gcd(i, n) == 1)
			result++;
	return result;
}

int main()
{
	int n;
	for (n = 1; n <= 10; n++)
		cout << "phi("<<n<<") = " << phi(n) << endl;
	return 0;
}

/*
It defines a function called gcd to calculate the greatest common divisor (GCD) of two numbers. The function takes two parameters, a and b, and uses a recursive algorithm to calculate the GCD. It returns the GCD of a and b.

It defines another function called phi to calculate Euler's Totient Function. The function takes an unsigned integer n as input and returns the value of phi(n). The phi function initializes a variable result to 1.

Inside the phi function, there is a loop that iterates from i = 2 to n - 1, inclusive.

For each value of i, it calculates the GCD of i and n using the gcd function.

If the GCD is equal to 1, it means that i and n are coprime (they have no common factors other than 1), so it increments the result variable by 1.

After the loop completes, the result variable contains the value of Euler's Totient Function for the given n, which represents the count of numbers less than n that are coprime with n.

In the main function:

It initializes an integer variable n to iterate over values from 1 to 10.

It enters a loop that runs for each value of n from 1 to 10.

Inside the loop, it calls the phi function with the current value of n and prints the result along with the value of n.

The program prints the Euler's Totient Function values for n ranging from 1 to 10.

*/

