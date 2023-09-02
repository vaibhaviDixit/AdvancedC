/*
You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the
form S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number
of swaps necessary to make a string balanced.

Input  : []][][
Output : 2

First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate swaps required
long swapCount(string s)
{
	// Keep track of '['
	vector<int> pos;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == '[')
			pos.push_back(i);

	int count = 0; // To count number of encountered '['
	int p = 0; // To track position of next '[' in pos
	long sum = 0; // To store result

	for (int i = 0; i < s.length(); ++i)
	{
		// Increment count and move p to next position
		if (s[i] == '[')
		{
			++count;
			++p;
		}
		else if (s[i] == ']')
			--count;

		// We have encountered an unbalanced part of string
		if (count < 0)
		{
			// Increment sum by number of swaps required i.e. position of next '[' - current position
			sum += pos[p] - i;
			swap(s[i], s[pos[p]]);
			++p;

			// Reset count to 1
			count = 1;
		}
	}
	return sum;
}

int main()
{
	string s = "[]][][";
	cout << swapCount(s) << "\n";

	s = "[[][]]";
	cout << swapCount(s) << "\n";
	return 0;
}

/*
The swapCount function calculates the minimum swaps required. It takes a string s as input and returns the number of swaps needed.

Inside the swapCount function:

A vector pos is used to keep track of the positions of opening brackets ('[') encountered in the string.
A variable count is initialized to 0, which keeps track of the number of opening brackets encountered.
Another variable p is initialized to 0, which tracks the position of the next opening bracket ('[') in the pos vector.
A variable sum is initialized to 0 to store the final result.
The function iterates through the characters of the input string s using a for loop.

If the current character is an opening bracket ('['), the count is incremented, and the p is moved to the next position.
If the current character is a closing bracket (']'), the count is decremented.
Whenever the count becomes negative, it indicates that an unbalanced part of the string is encountered, where a closing bracket (']') appears before its corresponding opening bracket ('[').

In such cases, the program calculates the number of swaps required as the position of the next opening bracket ('[') minus the current position.
The program then performs the swaps to move the current closing bracket (']') to its correct position before the opening bracket ('[').
The p is incremented, and the count is reset to 1 (indicating the presence of an opening bracket).
Finally, the sum variable holds the total number of swaps required to balance the string, and it is returned as the result.

In the main function, two sample strings, s and s2, are provided. The swapCount function is called for each string, and the program prints the number of swaps needed to balance the strings.

*/
