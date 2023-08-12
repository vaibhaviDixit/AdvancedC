/*
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to
find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000

*/


#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1 . . . n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int mini = INT_MAX;
	int count;

	// Place parenthesis at different places
	// between first and last matrix,
	// recursively calculate count of multiplications
	// for each parenthesis placement
	// and return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		mini = min(count, mini);
	}

	// Return minimum count
	return mini;
}

int main()
{
	int arr[] = { 10,30,5,60 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, 1, N - 1);
	return 0;
}

/*
This program uses a recursive approach to solve the Matrix Chain Multiplication problem, which aims to find the minimum number of scalar
multiplications needed to multiply a chain of matrices together. The function MatrixChainOrder is a recursive function that returns the minimum
number of multiplications needed for the chain of matrices from index 'i' to 'j'.

The main function initializes an array arr representing the dimensions of matrices and calls the MatrixChainOrder function to find the minimum
number of multiplications needed. The output is then displayed on the console.

*/




