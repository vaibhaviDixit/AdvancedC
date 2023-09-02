/*
Given length of wall w and shelves of two lengths m and n, find the number of each type of shelf to be used and the remaining empty space in the optimal
solution so that the empty space is minimum. The larger of the two shelves is cheaper so it is preferred. However cost is secondary and first priority is
to minimize empty space on wall.

Input : w = 24 m = 3 n = 5
Output : 3 3 0

We use three units of both shelves and 0 space is left.
3 * 3 + 3 * 5 = 24
So empty space  = 24 - 24 = 0
Another solution could have been 8 0 0 but since the larger shelf of length 5 is cheaper the former will be the answer.

Input : w = 29 m = 3 n = 9
Output : 0 3 2

*/


// C++ program to find minimum space and units of two shelves to fill a wall.
#include <bits/stdc++.h>
using namespace std;

void minSpacePreferLarge(int wall, int m, int n)
{
	// for simplicity, Assuming m is always smaller than n initializing output variables
	int num_m = 0, num_n = 0, min_empty = wall;

	// p and q are no of shelves of length m and n rem is the empty space
	int p = wall/m, q = 0, rem=wall%m;
	num_m=p;
	num_n=q;
	min_empty=rem;
	while (wall >= n) {
		// place one more shelf of length n
		q += 1;
		wall = wall - n;
		// place as many shelves of length m
		// in the remaining part
		p = wall / m;
		rem = wall % m;

		// update output variablse if curr
		// min_empty <= overall empty
		if (rem <= min_empty) {
			num_m = p;
			num_n = q;
			min_empty = rem;
		}
	}

	cout << num_m << " " << num_n << " "
		<< min_empty << endl;
}

int main()
{
	int wall = 29, m = 3, n = 9;
	minSpacePreferLarge(wall, m, n);

	wall = 76, m = 1, n = 10;
	minSpacePreferLarge(wall, m, n);
	return 0;
}

/*
The minSpacePreferLarge function takes three parameters:

wall: An integer representing the length of the wall to be filled.
m: An integer representing the length of the first shelf size.
n: An integer representing the length of the second shelf size.
Inside the minSpacePreferLarge function:

The function assumes that 'm' is always smaller than 'n' for simplicity.
Three variables are initialized:
num_m: The number of shelves of length 'm' to be placed.
num_n: The number of shelves of length 'n' to be placed (initially set to 0).
min_empty: The minimum empty space left on the wall (initially set to the total wall length).
The function calculates how many shelves of length 'n' can be placed on the wall and reduces the remaining wall length accordingly. It also calculates how many shelves of length 'm' can be placed in the remaining space.
At each step, the function checks if the current empty space is less than or equal to the minimum empty space seen so far. If this condition is met, it updates the num_m, num_n, and min_empty variables with the current values.
This process continues until it's no longer possible to place a shelf of length 'n' on the wall.
In the main function:

Two test cases are provided:
Test Case 1: A wall with a length of 29 units, shelf sizes 'm' = 3 units and 'n' = 9 units.
Test Case 2: A wall with a length of 76 units, shelf sizes 'm' = 1 unit and 'n' = 10 units.
The minSpacePreferLarge function is called with each test case, and the results (the number of shelves of each size and the remaining empty space) are printed to the console.

*/
