/*
Give a positive integer n, find modular multiplicative inverse of all integer from 1 to n with respect to a big prime number, say, ‘prime’.
The modular multiplicative inverse of a is an integer ‘x’ such that.
a x ? 1 (mod prime)

Input : n = 10, prime = 17
Output : 1 9 6 13 7 3 5 15 2 12
Explanation :
For 1, modular inverse is 1 as (1 * 1)%17 is 1
For 2, modular inverse is 9 as (2 * 9)%17 is 1
For 3, modular inverse is 6 as (3 * 6)%17 is 1
.......

Input : n = 5, prime = 7
Output : 1 4 5 2 3

*/

// CPP code to find modular inverse from 1 to n w.r.t a big prime number
#include <iostream>
using namespace std;

// Function to calculate modular inverse using D.P
void modularInverse(int n, int prime)
{
	int dp[n + 1];
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[prime % i] *
			(prime - prime / i) % prime;

	for (int i = 1; i <= n; i++)
		cout << dp[i] << ' ';
}


int main()
{
	int n = 10, prime = 17;
	modularInverse(n, prime);
	return 0;
}

/*
It defines a function called modularInverse that calculates modular inverses and takes two parameters: n (the range of numbers for which modular inverses are calculated) and prime (the prime number with respect to which the inverses are calculated).

Inside the modularInverse function:

It initializes an array dp of size n + 1 to store the modular inverses. The dp array will be used for dynamic programming.

It sets dp[0] and dp[1] to 1 because the modular inverse of 0 and 1 is always 1.

It iterates from i = 2 to n, calculating the modular inverse for each number i. The modular inverse of i modulo prime is calculated as follows:

dp[i] = dp[prime % i] * (prime - prime / i) % prime;
dp[prime % i] represents the modular inverse of prime % i.
prime - prime / i represents the multiplicative inverse of prime / i.
% prime ensures that the result remains within the range of the prime number.
After calculating all the modular inverses, it prints them to the standard output.

*/
