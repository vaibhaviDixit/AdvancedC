/*
Given a number n, print all primes smaller than n. For example, if the given number is 10, output 2, 3, 5, 7.
Use Segmented Sieve

Input: n= 100
Output:
Primes smaller than 100:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

*/


// C++ program to print all primes smaller than n using segmented sieve
#include <bits/stdc++.h>
using namespace std;

// This functions finds all primes smaller than 'limit' using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit, vector<int> &prime)
{
	// Create a boolean array "mark[0..n-1]" and initialize all entries of it as true. A value in mark[p] will
	// finally be false if 'p' is Not a prime, else true.
	vector<bool> mark(limit + 1, true);

	for (int p=2; p*p<limit; p++)
	{
		// If p is not changed, then it is a prime
		if (mark[p] == true)
		{
			// Update all multiples of p
			for (int i=p*p; i<limit; i+=p)
				mark[i] = false;
		}
	}

	// Print all prime numbers and store them in prime
	for (int p=2; p<limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
			cout << p << " ";
		}
	}
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
	// Compute all primes smaller than or equal to square root of n using simple sieve
	int limit = floor(sqrt(n))+1;
	vector<int> prime;
	prime.reserve(limit);
	simpleSieve(limit, prime);

	// Divide the range [0..n-1] in different segments We have chosen segment size as sqrt(n).
	int low = limit;
	int high = 2*limit;

	// While all segments of range [0..n-1] are not processed, process one segment at a time
	while (low < n)
	{
		if (high >= n)
		high = n;

		// To mark primes in current range. A value in mark[i] will finally be false if 'i-low' is Not a prime, else true.
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find primes in current range
		for (int i = 0; i < prime.size(); i++)
		{
			// Find the minimum number in [low..high] that is a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3, we start with 33.
			int loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];

			/* Mark multiples of prime[i] in [low..high]:
				We are marking j - low for j, i.e. each number
				in range [low, high] is mapped to [0, high-low]
				so if range is [50, 100] marking 50 corresponds
				to marking 0, marking 51 corresponds to 1 and
				so on. In this way we need to allocate space only
				for range */
			for (int j=loLim; j<high; j+=prime[i])
				mark[j-low] = false;
		}

		// Numbers which are not marked as false are prime
		for (int i = low; i<high; i++)
			if (mark[i - low] == true)
				cout << i << " ";

		// Update low and high for next segment
		low = low + limit;
		high = high + limit;
	}
}

int main()
{
	int n = 100;
	cout << "Primes smaller than " << n << ":\n";
	segmentedSieve(n);
	return 0;
}

/*
It defines a function called simpleSieve to find all prime numbers smaller than a specified limit using the simple sieve of Eratosthenes algorithm. The prime numbers are stored in a vector named prime.

Inside the simpleSieve function:

It creates a boolean array named mark of size limit + 1, where limit is the square root of the specified limit n. All entries in the mark array are initialized to true. The value in mark[p] will be set to false if p is not a prime number, otherwise, it remains true.

It iterates through all numbers from 2 up to the square root of the limit limit (i.e., p*p < limit).

For each prime number p, it updates all multiples of p by setting their corresponding entries in the mark array to false.

It prints and stores all prime numbers in the prime vector.

The segmentedSieve function takes an integer n as input and finds all prime numbers smaller than n. It works as follows:

It calculates the limit as the square root of n using the floor(sqrt(n)) function and adds 1 to it.

It calls the simpleSieve function to compute all prime numbers smaller than or equal to the limit. These primes are stored in the prime vector.

It divides the range [0, n-1] into different segments. Each segment has a size equal to limit. The low variable represents the lower bound of the current segment, and the high variable represents the upper bound of the current segment.

While the lower bound low is less than n, it processes one segment at a time. Inside the loop:

It initializes a boolean array named mark of size limit + 1 and sets all entries to true.

It uses the prime numbers obtained from the simpleSieve to mark the multiples of those primes within the current segment. This is done by calculating the minimum multiple of each prime within the segment and setting the corresponding entry in the mark array to false.

It iterates through the current segment and prints the numbers that are still marked as true in the mark array. These numbers are prime numbers within the segment.

It updates the low and high variables to move to the next segment.

*/


