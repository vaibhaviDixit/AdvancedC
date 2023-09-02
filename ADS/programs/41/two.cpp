/*
Write a dynamic programming based function to find nth Catalan number.

Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can be used to find the number of possibilities of various combinations.
The nth term in the sequence denoted Cn, is found in the following formula: \frac{(2n)!}{(n + 1)! n!)}
The first few Catalan numbers for n = 0, 1, 2, 3, … are : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Input: n = 6
Output: 132

Input: n = 8
Output: 1430

*/

#include <iostream>
using namespace std;

// A dynamic programming based function to find nth Catalan number
unsigned long int catalanDP(unsigned int n)
{
	// Table to store results of subproblems
	unsigned long int catalan[n + 1];

	// Initialize first two values in table
	catalan[0] = catalan[1] = 1;

	// Fill entries in catalan[] using recursive formula
	for (int i = 2; i <= n; i++) {
		catalan[i] = 0;
		for (int j = 0; j < i; j++)
			catalan[i] += catalan[j] * catalan[i - j - 1];
	}

	// Return last entry
	return catalan[n];
}


int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalanDP(i) << " ";
	return 0;
}

/*
The catalanDP Function: This function calculates the nth Catalan number using dynamic programming. It takes an unsigned integer parameter n representing the index of the desired Catalan number in the sequence.

Table of Catalan Numbers: An array catalan of size n + 1 is created to store the Catalan numbers. The first two values, catalan[0] and catalan[1], are initialized to 1.

Calculating Catalan Numbers: A loop runs from index 2 to n. For each i, a nested loop iterates from 0 to i - 1. The value of catalan[i] is calculated by summing up the product of catalan[j] and catalan[i - j - 1] for all possible values of j.

Output in main Function: The main function contains a loop that iterates from 0 to 9 (for the first 10 Catalan numbers). Inside the loop, the catalanDP function is called with the loop variable i as an argument, and the calculated Catalan number is printed using cout.

Printing Result: The loop prints the calculated Catalan numbers separated by spaces, resulting in an output like 1 1 2 5 14 42 132 429 1430 4862.

*/
