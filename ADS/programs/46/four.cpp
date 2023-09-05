/*
Given a string consisting of only A’s and B’s. We can transform the given string to another string by toggling any character.
Thus many transformations of the given string are possible. The task is to find Weight of the maximum weight transformation.

Weight of a string is calculated using below formula.

Weight of string = Weight of total pairs +
                   weight of single characters -
                   Total number of toggles.

Two consecutive characters are considered as pair only if they
are different.
Weight of a single pair (both character are different) = 4
Weight of a single character = 1

Input: str = "AA"
Output: 3
Transformations of given string are "AA", "AB", "BA" and "BB".
Maximum weight transformation is "AB" or "BA".  And weight
is "One Pair - One Toggle" = 4-1 = 3.

Input: str = "ABB"
Output: 5


*/


// C++ program to find maximum weight transformation of a given string
#include<bits/stdc++.h>
using namespace std;

// Returns weight of the maximum weight transformation
int getMaxRec(string &str, int i, int n,
						int lookup[])
{
	// Base case
	if (i >= n) return 0;

	//If this subproblem is already solved
	if (lookup[i] != -1) return lookup[i];

	// Don't make pair, so weight gained is 1
	int ans = 1 + getMaxRec(str, i + 1, n,
								lookup);

	// If we can make pair
	if (i + 1 < n)
	{
	// If elements are dissimilar, weight gained is 4
	if (str[i] != str[i+1])
		ans = max(4 + getMaxRec(str, i + 2,
								n, lookup), ans);

	// if elements are similar so for making a pair we toggle any of them.
	// Since toggle cost is 1 so overall weight gain becomes 3
	else ans = max(3 + getMaxRec(str, i + 2,
								n, lookup), ans);
	}

	// save and return maximum of above cases
	return lookup[i] = ans;
}

// Initializes lookup table and calls getMaxRec()
int getMaxWeight(string str)
{
	int n = str.length();

	// Create and initialize lookup table
	int lookup[n];
	memset(lookup, -1, sizeof lookup);

	// Call recursive function
	return getMaxRec(str, 0, str.length(),
								lookup);
}

int main()
{
	string str = "AAAAABB";
	cout << "Maximum weight of a transformation of "
		<< str << " is " << getMaxWeight(str);
	return 0;
}

/*

The getMaxRec function is defined to recursively calculate the maximum weight of the transformation. It takes the following parameters:

str: A reference to the input string.
i: The current index in the string.
n: The length of the string.
lookup: An array used for memoization to store intermediate results.
In the getMaxRec function:

The base case checks if the current index i is greater than or equal to the length of the string n. If so, it returns 0, indicating the end of the string.

If the result for the current index i is already calculated and stored in the lookup array (i.e., lookup[i] is not -1), it returns the precomputed result.

If no pair is made, the weight gained is 1, so ans is initialized with 1 plus the result of the recursive call to getMaxRec for the next index i + 1.

If it's possible to make a pair (i.e., i + 1 < n), the program considers two cases:

When elements at indices i and i + 1 are dissimilar, the weight gained is 4. So, it computes the maximum between 4 plus the result of the recursive call to getMaxRec for the index i + 2 and the current ans.

When elements at indices i and i + 1 are similar, the program toggles one of them. Since the toggle cost is 1, the weight gain becomes 3. So, it computes the maximum between 3 plus the result of the recursive call to getMaxRec for the index i + 2 and the current ans.

The maximum weight is calculated and saved in the lookup array for the current index i, and ans is returned.

The getMaxWeight function initializes the lookup table and then calls the getMaxRec function with the input string and other parameters.


*/

