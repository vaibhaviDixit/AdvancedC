/*
Given a number n, print n-th Fibonacci Number.

Input  : n = 1
Output : 1

Input  : n = 9
Output : 34

Input  : n = 10
Output : 55

*/


// C++ program for Fibonacci Series using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

class Test {

public:
	int fib(int n)
	{

		// Declare an array to storeFibonacci numbers.1 extra to handle case, n = 0
		int f[n + 2];
		int i;

		// 0th and 1st number of the
		// series are 0 and 1
		f[0] = 0;
		f[1] = 1;

		for (i = 2; i <= n; i++) {

			// Add the previous 2 numbers
			// in the series and store it
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};


int main()
{
	Test g;
	int n = 9;

	cout << g.fib(n);
	return 0;
}

/*
Class Definition: The program defines a class called Test, which contains a method fib to calculate the nth Fibonacci number.

The fib Method: This method takes an integer parameter n, representing the position of the desired Fibonacci number in the series. It uses an array f to store the Fibonacci numbers. The array is declared with a size of n + 2 to accommodate values up to the (n+1)th Fibonacci number. The base cases f[0] = 0 and f[1] = 1 are set to initialize the series. Then, a loop iterates from index 2 up to n, calculating each Fibonacci number using the formula f[i] = f[i - 1] + f[i - 2]. This dynamic programming approach avoids redundant calculations and improves efficiency.

main Function: The program's entry point is the main function. An instance of the Test class is created as g.
The variable n is set to 9, indicating that the 9th Fibonacci number is to be computed.

Output: The program prints the result of g.fib(n) using cout, which calculates the 9th Fibonacci number and outputs it to the console.

*/
