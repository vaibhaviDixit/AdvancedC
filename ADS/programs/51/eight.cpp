/*
Given three integers A, B and C. In an infinite sequence, A is the first number, C is the common difference (Si – Si – 1 = C).
The task is to check if the number B will appear in the sequence or not.

Input: A = 1, B = 7, C = 3
Output: Yes
The sequence will be 1, 4, 7, 10, …

Input: A = 1, B = -4, C = 5
Output: No

*/


// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if
// the sequence will contain B
bool doesContainB(int a, int b, int c)
{
	if (a == b)
		return true;

	if ((b - a) * c > 0 && (b - a) % c == 0)
		return true;

	return false;
}


int main()
{
	int a = 1, b = 7, c = 3;

	if (doesContainB(a, b, c))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

/*
bool doesContainB(int a, int b, int c): This is a function named doesContainB that takes three integer arguments: a (the starting integer), b (the target integer), and c (the increment/decrement value). It determines if the sequence starting from 'a' will contain 'b' based on the specified pattern of increments and decrements. It returns a boolean value (true if 'b' is contained, false otherwise).

Inside the function:

if (a == b) return true;: This condition checks if 'a' is already equal to 'b'. If they are equal, it means the sequence already contains 'b', and the function returns true.

(b - a) * c > 0 && (b - a) % c == 0: This condition checks if the difference between 'b' and 'a' has the same sign as 'c' (indicating the same direction of increments/decrements) and if the difference is divisible by 'c'. If both conditions are met, it means 'b' will be reached in the sequence, and the function returns true. Otherwise, it returns false.

If none of the above conditions are met, the function returns false, indicating that 'b' will not be reached in the sequence.

*/
