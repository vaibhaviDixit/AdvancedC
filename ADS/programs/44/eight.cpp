/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications,
but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the
product, the result will be the same.


Input:  p[] = {40, 20, 30, 10, 30}
Output: Optimal parenthesization is  ((A(BC))D)
        Optimal cost of parenthesization is 26000

There are 4 matrices of dimensions 40x20, 20x30,
30x10 and 10x30. Let the input 4 matrices be A, B,
C and D.  The minimum number of  multiplications are
obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30}
Output: Optimal parenthesization is (((AB)C)D)
        Optimal cost of parenthesization is 30000

*/


// C++ program to print optimal parenthesization in matrix chain multiplication.
#include <bits/stdc++.h>
using namespace std;

// Function for printing the optimal parenthesization of a matrix chain product
void printParenthesis(int i, int j, int n, int* bracket,
					char& name)
{
	// If only one matrix left in current segment
	if (i == j) {
		cout << name++;
		return;
	}

	cout << "(";

	// Recursively put brackets around subexpression from i to bracket[i][j].
	// Note that "*((bracket+i*n)+j)" is similar to bracket[i][j]
	printParenthesis(i, *((bracket + i * n) + j), n,
					bracket, name);

	// Recursively put brackets around subexpression from bracket[i][j] + 1 to j.
	printParenthesis(*((bracket + i * n) + j) + 1, j, n,
					bracket, name);
	cout << ")";
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
void matrixChainOrder(int p[], int n)
{
	/* For simplicity of the program, one extra
	row and one extra column are allocated in m[][]. 0th row and 0th column of m[][] are not used */
	int m[n][n];

	// bracket[i][j] stores optimal break point in subexpression from i to j.
	int bracket[n][n];

	/* m[i,j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j] =
	A[i..j] where dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (int i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				int q = m[i][k] + m[k + 1][j]
						+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;

					// Each entry bracket[i,j]=k shows where to split the product arr i,i+1....j for the minimum cost.
					bracket[i][j] = k;
				}
			}
		}
	}

	// The first matrix is printed as 'A', next as 'B', and so on
	char name = 'A';

	cout << "Optimal Parenthesization is : ";
	printParenthesis(1, n - 1, n, (int*)bracket, name);
	cout << "\nOptimal Cost is : " << m[1][n - 1];
}


int main()
{
	int arr[] = { 40, 20, 30, 10, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	matrixChainOrder(arr, n);
	return 0;
}

/*
The printParenthesis function is defined to print the optimal parenthesization of the matrix chain product. It takes the following arguments:

i and j: The indices representing the range of matrices to parenthesize.
n: The total number of matrices.
bracket: An integer array that stores the optimal break points in the subexpression.
name: A character variable used to represent matrix names.
Inside printParenthesis, it first checks if i is equal to j, indicating that only one matrix is left in the current segment. In this case, it simply prints the matrix name represented by the character name.

If there is more than one matrix in the segment, it prints an opening parenthesis ( and proceeds to recursively call printParenthesis for the left and right subexpressions, based on the break point stored in the bracket array.

The matrixChainOrder function is defined to calculate the optimal parenthesization and minimum cost of matrix chain multiplication. It takes the following arguments:

p: An array representing the dimensions of the matrices in the chain.
n: The total number of matrices in the chain.
Inside matrixChainOrder, a 2D array m is declared to store the minimum number of scalar multiplications needed to compute the matrix chain product. Additionally, a 2D array bracket is declared to store the optimal break points in the subexpression.

The loop for (int i = 1; i < n; i++) initializes the m array, setting the cost to 0 for multiplying a single matrix (diagonal entries).

The program then uses a nested loop to calculate the minimum cost of multiplying different subexpressions of matrices, considering different break points. It iterates through various chain lengths L and subexpression ranges from i to j.

For each subexpression, the program calculates the cost q of multiplying the matrices at positions i, k, and j, where k is the break point. If q is smaller than the current cost stored in m[i][j], it updates m[i][j] and the corresponding break point bracket[i][j].

After completing the dynamic programming calculations, the optimal parenthesization is printed using the printParenthesis function, starting with matrices 1 to n-1.

The program also displays the optimal cost, which is stored in m[1][n-1].

In the main function, an example array arr representing the dimensions of matrices in the chain is provided. The program calculates and prints the optimal parenthesization and cost for this input.

*/

