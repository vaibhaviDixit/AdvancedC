/*
C++ program to compute Totient function for all numbers smaller than or equal to n.

Input: n=12
Output:
Totient of 1 is 1
Totient of 2 is 1
Totient of 3 is 2
Totient of 4 is 2
Totient of 5 is 4
Totient of 6 is 2
Totient of 7 is 6
Totient of 8 is 4
Totient of 9 is 6
Totient of 10 is 4
Totient of 11 is 10
Totient of 12 is 4


*/


#include<iostream>
using namespace std;

// Computes and prints totient of all numbers smaller than or equal to n.
void computeTotient(int n)
{
	// Create and initialize an array to store phi or totient values
	long long phi[n+1];
	for (int i=1; i<=n; i++)
		phi[i] = i; // indicates not evaluated yet
					// and initializes for product
					// formula.

	// Compute other Phi values
	for (int p=2; p<=n; p++)
	{
		// If phi[p] is not computed already,
		// then number p is prime
		if (phi[p] == p)
		{
			// Phi of a prime number p is always equal to p-1.
			phi[p] = p-1;

			// Update phi values of all multiples of p
			for (int i = 2*p; i<=n; i += p)
			{
			// Add contribution of p to its multiple i by multiplying with (1 - 1/p)
			phi[i] = (phi[i]/p) * (p-1);
			}
		}
	}

	// Print precomputed phi values
	for (int i=1; i<=n; i++)
	cout << "Totient of " << i << " is "
		<< phi[i] << endl;
}

int main()
{
	int n = 12;
	computeTotient(n);
	return 0;
}

/*
It defines a function called computeTotient that takes an integer n as input. This function is responsible for computing and printing the totient values for all numbers from 1 to n.

Inside the computeTotient function:

It creates an array named phi of size (n + 1) to store the totient values. The index i of the phi array represents the totient value of i.

It initializes each element of the phi array to its index value. This initialization indicates that the totient values are not evaluated yet, and it initializes them for the product formula.

The program then enters a loop that iterates from p = 2 to n.

For each value of p, it checks if phi[p] is equal to p. If it is, this indicates that p is a prime number.

For prime numbers, the totient value (phi) is updated to p - 1, as Euler's Totient Function for a prime number p is always equal to p - 1.

It then updates the phi values for all multiples of p from 2 * p to n. This update is done using Euler's Totient Function formula: phi[i] = (phi[i] / p) * (p - 1). This formula calculates the totient values for numbers that are multiples of p.

After the loop completes, the phi array contains the totient values for all numbers from 1 to n.

The program prints the precomputed totient values for each number from 1 to n.

*/

