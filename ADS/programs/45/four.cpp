/*
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input;
{ 0, 1, 1, 0, 1 }
{ 1, 1, 0, 1, 0 }
{ 0, 1, 1, 1, 0 }
{ 1, 1, 1, 1, 0 }
{ 1, 1, 1, 1, 1 }
{ 0, 0, 0, 0, 0 }

Output:
Maximum size sub-matrix is:
1 1 1
1 1 1
1 1 1

*/

// C++ code for Maximum size square sub-matrix with all 1s
#include <bits/stdc++.h>
#define bool int
#define R 6
#define C 5
using namespace std;

void printMaxSubSquare(bool M[R][C])
{
	int i, j;
	int S[R][C];
	int max_of_s, max_i, max_j;

	/* Set first column of S[][]*/
	for (i = 0; i < R; i++)
		S[i][0] = M[i][0];

	/* Set first row of S[][]*/
	for (j = 0; j < C; j++)
		S[0][j] = M[0][j];

	/* Construct other entries of S[][]*/
	for (i = 1; i < R; i++) {
		for (j = 1; j < C; j++) {
			if (M[i][j] == 1)
				S[i][j]
					= min({ S[i][j - 1], S[i - 1][j],
							S[i - 1][j - 1] })
					+ 1; // better of using min in case of
						// arguments more than 2
			else
				S[i][j] = 0;
		}
	}

	/* Find the maximum entry, and indexes of maximum entry
		in S[][] */
	max_of_s = S[0][0];
	max_i = 0;
	max_j = 0;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (max_of_s < S[i][j]) {
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout << "Maximum size sub-matrix is: \n";
	for (i = max_i; i > max_i - max_of_s; i--) {
		for (j = max_j; j > max_j - max_of_s; j--) {
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	bool M[R][C] = { { 0, 1, 1, 0, 1 }, { 1, 1, 0, 1, 0 },
					{ 0, 1, 1, 1, 0 }, { 1, 1, 1, 1, 0 },
					{ 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 } };

	printMaxSubSquare(M);
}

/*
Macros: The code uses macros bool, R, and C to represent a boolean type and the number of rows and columns in the matrix, respectively.

The printMaxSubSquare Function: This function finds and prints the maximum size square sub-matrix consisting of all 1s. It takes a 2D boolean matrix M as input.

Array S: A 2D integer array S[R][C] is declared to store the size of the largest square sub-matrix ending at each position (i, j).

Initial Fill: The function initializes the first column of S with the corresponding values from the first column of M, and similarly, the first row of S with the values from the first row of M.

Dynamic Programming Calculation: The function iterates through the rest of the matrix and calculates the values of S based on the values of M. If M[i][j] is 1, then the value of S[i][j] is set to the minimum of S[i][j-1], S[i-1][j], and S[i-1][j-1] plus one. If M[i][j] is 0, then S[i][j] is set to 0.

Finding Maximum Entry: The function then finds the maximum entry in the S matrix along with its corresponding indices.

Printing Sub-Matrix: The program prints the sub-matrix by looping over the indices of the maximum entry and printing the corresponding values from M.

*/


