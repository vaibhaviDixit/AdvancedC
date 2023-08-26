/*
Write a C++ program to generate a graph for a given fixed degree sequence. This algorithm generates a undirected graph for the given degree sequence.
It does not include self-edge and multiple edges.

Input : degrees[] = {2, 2, 1, 1}
Output :  (0)  (1)  (2)  (3)
    (0)    0    1    1    0
    (1)    1    0    0    1
    (2)    1    0    0    0
    (3)    0    1    0    0

*/

// C++ program to generate a graph for a given fixed degrees
#include <bits/stdc++.h>
using namespace std;

// A function to print the adjacency matrix.
void printMat(int degseq[], int n)
{
	// n is number of vertices
	int mat[n][n];
	memset(mat, 0, sizeof(mat));

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			// For each pair of vertex decrement
			// the degree of both vertex.
			if (degseq[i] > 0 && degseq[j] > 0) {
				degseq[i]--;
				degseq[j]--;
				mat[i][j] = 1;
				mat[j][i] = 1;
			}
		}
	}

	// Print the result in specified format
	cout << "\n"
		<< setw(3) << "	 ";
	for (int i = 0; i < n; i++)
		cout << setw(3) << "(" << i << ")";
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << setw(4) << "(" << i << ")";
		for (int j = 0; j < n; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
}

int main()
{
	int degseq[] = { 2, 2, 1, 1, 1 };
	int n = sizeof(degseq) / sizeof(degseq[0]);
	printMat(degseq, n);
	return 0;
}

/*
The function printMat takes two parameters: an array degseq[] representing the degree sequence and an integer n representing the number of vertices in the graph.

Inside the printMat function:

It initializes a matrix mat to represent the adjacency matrix of the graph and sets all its elements to 0.
The program iterates through pairs of vertices and checks if the degrees of both vertices are greater than 0. If so, it decrements the degrees of both vertices and sets the corresponding entry in the adjacency matrix to 1.
After constructing the adjacency matrix, the program prints the matrix in a formatted manner. It prints the vertex labels at the top and left side of the matrix for reference.
The main function:

Initializes an array degseq with the given fixed degree sequence.
Calculates the number of vertices n using the size of the degseq array.
Calls the printMat function with the degseq array and the number of vertices as arguments.

*/


