/*
Given two numbers N and A, find N-th root of A. In mathematics, Nth root of a number A is a real number that gives A, when we raise it to integer
power N. These roots are used in Number Theory and other advanced branches of mathematics.

Input : A = 81
        N = 4
Output : 3
3^4 = 81


*/


// C++ program to calculate Nth root of a number
#include <bits/stdc++.h>
using namespace std;

// method returns Nth power of A
double nthRoot(int A, int N)
{
	// initially guessing a random number between 0 and 9
	double xPre = rand() % 10;

	// smaller eps, denotes more accuracy
	double eps = 1e-3;

	// initializing difference between two roots by INT_MAX
	double delX = INT_MAX;

	// xK denotes current value of x
	double xK;

	// loop until we reach desired accuracy
	while (delX > eps)
	{
		// calculating current value from previous
		// value by newton's method
		xK = ((N - 1.0) * xPre +
			(double)A/pow(xPre, N-1)) / (double)N;
		delX = abs(xK - xPre);
		xPre = xK;
	}

	return xK;
}

int main()
{
	int N = 4;
	int A = 81;

	double nthRootValue = nthRoot(A, N);
	cout << "Nth root is " << nthRootValue << endl;

	/*
		double Acalc = pow(nthRootValue, N);
		cout << "Error in difference of powers "
			<< abs(A - Acalc) << endl;
	*/

	return 0;
}

/*
The nthRoot function is defined to calculate the Nth root of a given number 'A' using the Newton-Raphson method. It takes two arguments: 'A' (the number for which the Nth root is to be found) and 'N' (the order of the root).

Inside the nthRoot function:

A random initial guess 'xPre' between 0 and 9 is generated to start the Newton-Raphson iteration.

The variable 'eps' represents the desired accuracy, and 'delX' is initialized to INT_MAX to ensure the loop starts.

A loop is used to iteratively refine the estimate of the Nth root until the desired accuracy is achieved.

In each iteration, the current estimate 'xK' is calculated using the Newton-Raphson formula, and 'delX' is updated as the absolute difference between 'xK' and the previous estimate 'xPre'.

*/
