/*
Let an be a sequence of numbers, which is defined by the recurrence relation a1=1 and an+1/an=2n. The task is to find the value of log2(an)
for a given n.


Input: 5
Output: 10

Explanation:
log2(an) = (n * (n - 1)) / 2
= (5*(5-1))/2
= 10

Input: 100
Output: 4950

*/

// C++ program to find nth term of a given recurrence relation

#include <bits/stdc++.h>

using namespace std;

// function to return required value
int sum(int n)
{

	// Get the answer
	int ans = (n * (n - 1)) / 2;

	// Return the answer
	return ans;
}


int main()
{

	// Get the value of n
	int n = 5;

	// function call to print result
	cout << sum(n);

	return 0;
}

/*
#include <bits/stdc++.h>: This line includes the standard C++ library header, which provides access to various functions and data types used in the program.

using namespace std;: This line allows you to use names from the std namespace without prefixing them with std::.

int sum(int n): This is a function named sum that takes an integer n as an argument and returns an integer. It calculates the sum of the first n natural numbers using a mathematical formula: n * (n - 1) / 2. The result is stored in the ans variable and then returned.

int main(): This is the main function where the program execution begins.

int n = 5;: This line declares an integer variable n and initializes it with the value 5, which represents the number of terms in the recurrence relation.

cout << sum(n);: This line calls the sum function with the value of n (in this case, 5) as an argument and prints the result to the standard output using the cout stream.

*/
