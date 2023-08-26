/*
Consider a Binary Heap of size N. We need to find the height of it.

Input : N = 6
Output : 2

*/

// CPP program to find height of complete binary tree from total nodes.
#include <bits/stdc++.h>
using namespace std;

int height(int N)
{
	return floor(log2(N));
}

int main()
{
	int N = 2;
	cout << height(N);
	return 0;
}

/*
This C++ program calculates and prints the height of a complete binary tree based on the total number of nodes provided.
The height of a complete binary tree is determined by the formula floor(log2(N)), where N is the total number of nodes in the tree.
The log2 function calculates the base-2 logarithm, and the floor function rounds down to the nearest integer.
The program demonstrates this calculation for a given value of N (in this case, N = 2) and outputs the computed height of the complete binary tree.

*/
