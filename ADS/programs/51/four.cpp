/*
Given three integers x1, x2, and x3, we can perform an operation that simultaneously adds 2 to one of them, adds 4 to another, and adds 6 to
the third. We can perform this operation any number of times on any permutation of the indices (1, 2, 3), the task is to determine whether it
is possible to make x1 = x2 = x3 through some sequence of these operations. If it is possible, find the minimum number of times we need to
perform the operation to achieve this goal. If not possible print -1.

Input: x1 = 2, x2 = 8, x3 = 8
Output: 2

Explanation: Initially (x1=2, x2=8, x3=8).
1st step : (x1+6, x2+4, x3+2) makes (8 12 10).
2nd Step:  (x1+6, x2+2, x3+4) makes (14 14 14), thus in two steps we can make triplet equal.

Input: x1 = 5, x2 = 10, x3 = 10
Output: -1

*/

// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

int equalTriplet(int x1, int x2, int x3)
{

	int v = x1 + x2 + x3;

	// Sum of triplet
	if (v % 3) {

		// Cheking is it divisible by 3 or not, if not return -1
		return -1;
	}

	// Cheking all the element x1, x2, x3 and sum/3 is in same parity or not
	if (x1 % 2 != x2 % 2 || x2 % 2 != x3 % 2 || v % 3 != 0
		|| x1 % 2 != v / 3 % 2)
		return -1;
	v /= 3;

	// Returning the sum of abs differnce / 4
	return (abs(x1 - v) + abs(x2 - v) + abs(x3 - v)) / 4;
}


int main()
{
	int x = 10, y = 100, z = 1000;
	int ans = equalTriplet(x, y, z);

	// Function Call
	cout << ans << endl;
}

/*
int equalTriplet(int x1, int x2, int x3): This is a function named equalTriplet that takes three integers, x1, x2, and x3, as arguments and returns an integer. It calculates the minimum number of moves needed to make the three integers equal.

Inside the function:

int v = x1 + x2 + x3;: It calculates the sum of the three integers.

if (v % 3) { return -1; }: This condition checks if the sum is not divisible by 3. If it's not divisible by 3, it means it's impossible to make the integers equal, so the function returns -1.

The next condition checks if all three integers have the same parity (even or odd) and if the sum is divisible by 3. If any of these conditions is not met, it returns -1, indicating that it's not possible to make the integers equal.

v /= 3;: If all conditions are satisfied, the code calculates the target value v by dividing the sum by 3. This is the value that each integer should become equal to.

return (abs(x1 - v) + abs(x2 - v) + abs(x3 - v)) / 4;: Finally, the code calculates and returns the minimum number of moves needed to make the integers equal. It computes the absolute differences between each integer and the target value v, sums them up, and divides by 4 to get the minimum number of moves.

*/
