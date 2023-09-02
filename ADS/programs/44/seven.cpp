
/*
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the
most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by
putting parenthesis in following way (A(BC))D.
The minimum is 20*30*10 + 40*20*10 + 40*10*30

Input: arr[] = {1, 2, 3, 4, 3}
Output: 30

*/

// See the Cormen book for details of the following algorithm
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{

	/* For simplicity of the program, one extra row and one extra column are
	allocated in m[][]. 0th row and 0th column of m[][] are not used */
	int m[n][n];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of scalar multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}

/*
The MatrixChainOrder function is defined to solve the Matrix Chain Multiplication Problem. It takes two arguments:

p[]: An array representing the dimensions of matrices. The i-th matrix has dimensions p[i-1] x p[i]. The array p has n elements, where n is the number of matrices in the chain.
n: The number of matrices in the chain.
Inside MatrixChainOrder, a 2D array m[n][n] is declared to store the minimum number of scalar multiplications needed to compute the product of matrices in various sub-chains.

The program uses a series of nested loops to calculate the minimum number of scalar multiplications for all possible sub-chains of matrices. The outermost loop iterates over the chain length L (from 2 to n-1), representing the number of matrices in a sub-chain.

The inner loops consider different sub-chains of matrices within the current chain length L. For each sub-chain, it calculates the cost of parenthesizing the matrices in different ways and selects the one with the minimum cost.

The cost q for parenthesizing matrices i to j in a sub-chain is calculated as the sum of three parts:

The cost of parenthesizing matrices i to k (inclusive) where i <= k <= j.
The cost of parenthesizing matrices k+1 to j (inclusive) where i <= k <= j.
The cost of multiplying the resulting matrices A[i..k] and A[k+1..j] together, which is p[i-1] x p[k] x p[j].
The program initializes the m array with appropriate base cases (e.g., when multiplying a single matrix, the cost is 0).

After calculating the minimum cost for all possible sub-chains, the final result is stored in m[1][n-1], which represents the minimum cost for the entire chain of matrices.

In the main function, an example array arr representing the dimensions of matrices is provided. The program then calls MatrixChainOrder to find the minimum number of multiplications required to compute the product of these matrices and displays the result.

*/
