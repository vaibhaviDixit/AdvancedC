/*
 C++ program to find number of spanning trees in a graph using Matrix Chain Multiplication

 Input:
 {0, 1, 1, 1}
 {1, 0, 1, 1}
 {1, 1, 0, 1}
 {1, 1, 1, 0}

 Output: 72

 */


#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define MOD 1000000007

// Matrix Multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;
}

// Function to find Nth power of A
void power(int A[MAX][MAX], int N, int result[MAX][MAX])
{
	int temp[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			result[i][j] = (i == j);

	while (N>0)
	{
		if (N%2 == 1)
		{
			multiply(A, result, temp);
			for (int i=0; i<MAX; i++)
				for (int j=0; j<MAX; j++)
					result[i][j] = temp[i][j];
		}

		N = N/2;
		multiply(A, A, temp);
		for (int i=0; i<MAX; i++)
			for (int j=0; j<MAX; j++)
				A[i][j] = temp[i][j];
	}
}

// Function to find number of Spanning
// Trees in a Graph using Matrix Chain
// Multiplication.
int numOfSpanningTree(int graph[][MAX], int V)
{
	int result[MAX][MAX] = {0};
	int temp[MAX][MAX] = {0};

	// Create a copy of graph as the
	// Adjacency matrix will be changed
	// during the process
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			temp[i][j] = graph[i][j];

	// Find (V-2)th power of Adjacency
	// matrix
	power(temp, V-2, result);

	int ans = 0;

	// Find sum of all elements in (V-2)th
	// power
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			ans = (ans + result[i][j])%MOD;

	return ans;
}


int main()
{
	// Let us create the following graph
	// 2 <-> 3
	// |      |
	// 0 <-1-> 1
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	int graph[][MAX] = {
						{0, 1, 1, 1},
						{1, 0, 1, 1},
						{1, 1, 0, 1},
						{1, 1, 1, 0}
					};

	cout << numOfSpanningTree(graph, V);

	return 0;
}

/*
The constants MAX and MOD are defined for matrix dimensions and modulo operation, respectively.

The multiply function performs matrix multiplication between matrices A and B and stores the result in matrix C. This function uses the modulo operation to avoid integer overflow.

The power function computes the Nth power of matrix A using matrix exponentiation. It employs a binary exponentiation technique to optimize the computation.

The numOfSpanningTree function calculates the number of spanning trees in a given graph represented by the adjacency matrix graph.

a. It starts by creating a copy of the graph in the temp matrix.

b. It then computes the (V-2)th power of the temp matrix using the power function. This step is crucial to finding the number of spanning trees.

c. The final count is determined by summing up all the elements of the resulting matrix.

d. The answer is returned after taking the modulo operation using MOD.

In the main function:

a. A sample graph represented by its adjacency matrix graph is provided.

b. The numOfSpanningTree function is called with the graph and the number of vertices V.

The program outputs the calculated number of spanning trees.

*/

