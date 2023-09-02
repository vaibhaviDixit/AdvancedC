/*
Given an array arr[] of N integers, the task is to find the longest subarray where all numbers in that subarray are prime.

Input: arr[] = {3, 5, 2, 66, 7, 11, 8}
Output: 3
Explanation:
Maximum contiguous prime number sequence is {2, 3, 5}

Input: arr[] = {1, 2, 11, 32, 8, 9}
Output: 2

*/

// C++ program to find longest subarray of prime numbers
#include <bits/stdc++.h>
using namespace std;

// To store the prime numbers
unordered_set<int> allPrimes;

// Function that find prime numbers
// till limit
void simpleSieve(int limit,
				vector<int>& prime)
{
	bool mark[limit + 1];
	memset(mark, false, sizeof(mark));

	// Find primes using
	// Sieve of Eratosthenes
	for (int i = 2; i <= limit; ++i) {
		if (mark[i] == false) {
			prime.push_back(i);
			for (int j = i; j <= limit;
				j += i) {
				mark[j] = true;
			}
		}
	}
}

// Function that finds all prime numbers in given range using Segmented Sieve
void primesInRange(int low, int high)
{
	// Find the limit
	int limit = floor(sqrt(high)) + 1;

	// To store the prime numbers
	vector<int> prime;

	// Compute all primes less than or equals to sqrt(high) using Simple Sieve
	simpleSieve(limit, prime);

	// Count the elements in the range [low, high]
	int n = high - low + 1;

	// Declaring boolean for the
	// range [low, high]
	bool mark[n + 1];

	// Initialise bool[] to false
	memset(mark, false, sizeof(mark));

	// Traverse the prime numbers till limit
	for (int i = 0; i < prime.size(); i++) {

		int loLim = floor(low / prime[i]);
			loLim
			*= prime[i];

		// Find the minimum number in [low..high] that is a multiple of prime[i]
		if (loLim < low) {
			loLim += prime[i];
		}

		if (loLim == prime[i]) {
			loLim += prime[i];
		}

		// Mark the multiples of prime[i]
		// in [low, high] as true
		for (int j = loLim; j <= high;
			j += prime[i])
			mark[j - low] = true;
	}

	// Element which are not marked in range are Prime
	for (int i = low; i <= high; i++) {
		if (!mark[i - low]) {
			allPrimes.insert(i);
		}
	}
}

// Function that finds longest subarray  of prime numbers
int maxPrimeSubarray(int arr[], int n)
{
	int current_max = 0;
	int max_so_far = 0;

	for (int i = 0; i < n; i++) {

		// If element is Non-prime then updated current_max to 0
		if (!allPrimes.count(arr[i]))
			current_max = 0;

		// If element is prime, then update current_max and max_so_far
		else {
			current_max++;
			max_so_far = max(current_max,
							max_so_far);
		}
	}

	// Return the count of longest subarray
	return max_so_far;
}

int main()
{
	int arr[] = { 1, 2, 4, 3, 29, 11, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Find minimum and maximum element
	int max_el = *max_element(arr, arr + n);
	int min_el = *min_element(arr, arr + n);

	// Find prime in the range
	// [min_el, max_el]
	primesInRange(min_el, max_el);

	// Function call
	cout << maxPrimeSubarray(arr, n);
	return 0;
}

/*
It defines an unordered_set<int> named allPrimes to store all prime numbers that will be used later for checking prime numbers in the array.

The program defines a function called simpleSieve to find prime numbers up to a specified limit using the Sieve of Eratosthenes algorithm. It takes two parameters: limit (the upper limit for finding prime numbers) and prime (a vector to store prime numbers).

Inside the simpleSieve function:

It initializes a boolean array called mark of size limit + 1 to keep track of numbers that have been marked as non-prime.
It iterates through numbers from 2 to limit. For each prime number i encountered:
If mark[i] is false, it marks all multiples of i as true in the mark array, indicating that they are non-prime.
It adds i to the prime vector since it's a prime number.
The program defines another function called primesInRange that finds all prime numbers within a specified range [low, high]. It takes two parameters: low and high.

Inside the primesInRange function:

It calculates the limit as the square root of high and adds 1 to it.
It initializes a vector called prime to store prime numbers using the simpleSieve function to calculate primes up to the limit.
It calculates the number of elements in the range [low, high] and stores it in n.
It creates a boolean array named mark of size n + 1 to track whether numbers in the range are prime.
It initializes all elements of the mark array to false.
The primesInRange function then proceeds to iterate through the prime numbers found in the prime vector and marks the multiples of each prime number as non-prime in the mark array within the specified range [low, high].

Finally, the program defines a function named maxPrimeSubarray that takes an integer array arr and its size n. This function finds the longest subarray of prime numbers within the given array.

Inside the maxPrimeSubarray function:

It initializes current_max and max_so_far to 0. These variables will keep track of the length of the current subarray of prime numbers and the maximum length encountered so far.
It iterates through the elements of the input array arr.
If an element in the array is not a prime number (i.e., not found in the allPrimes set), it resets current_max to 0.
If an element is a prime number, it increments current_max and updates max_so_far if current_max exceeds the previous maximum.

*/
