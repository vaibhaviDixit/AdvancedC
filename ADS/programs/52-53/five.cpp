/*
Given an undirected and connected graph and a number n, count total number of cycles of length n in the graph.
A cycle of length n simply means that the cycle contains n vertices and n edges. And we have to count all such cycles that exist.

Input :  n = 4 edges= 0-1 1-2 2-3 3-4 0-3 1-4
Output : Total cycles = 3

*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices
const int V = 5;

void DFS(bool graph[][V], bool marked[], int n, int vert,
		int start, int& count)
{
	// mark the vertex vert as visited
	marked[vert] = true;

	// if the path of length (n-1) is found
	if (n == 0) {

		// mark vert as un-visited to make
		// it usable again.
		marked[vert] = false;

		// Check if vertex vert can end with
		// vertex start
		if (graph[vert][start] && graph[start][vert]) {
			count++;
			return;
		}
		else
			return;
	}

	// For searching every possible path of
	// length (n-1)
	for (int i = 0; i < V; i++)
		if (!marked[i] && graph[vert][i])

			// DFS for searching path by decreasing
			// length by 1
			DFS(graph, marked, n - 1, i, start, count);

	// marking vert as unvisited to make it
	// usable again.
	marked[vert] = false;
}

// Counts cycles of length N in an undirected
// and connected graph.
int countCycles(bool graph[][V], int n)
{
	// all vertex are marked un-visited initially.
	bool marked[V];
	memset(marked, 0, sizeof(marked));

	// Searching for cycle by using v-n+1 vertices
	int count = 0;
	for (int i = 0; i < V - (n - 1); i++) {
		DFS(graph, marked, n - 1, i, i, count);

		// ith vertex is marked as visited and
		// will not be visited again.
		marked[i] = true;
	}

	return count / 2;
}

int main()
{
	bool graph[][V] = { { 0, 1, 0, 1, 0 },
						{ 1, 0, 1, 0, 1 },
						{ 0, 1, 0, 1, 0 },
						{ 1, 0, 1, 0, 1 },
						{ 0, 1, 0, 1, 0 } };
	int n = 4;
	cout << "Total cycles of length " << n << " are "
		<< countCycles(graph, n);
	return 0;
}

/*
This C++ program calculates the number of cycles of a given length in an undirected and connected graph using Depth-First Search (DFS). The program defines a graph as an adjacency matrix and includes functions to perform DFS and count cycles of the specified length.

The DFS function explores all paths of length n starting from a vertex and increments the count if a cycle is found.

The countCycles function initializes a boolean array to track visited vertices and searches for cycles by using each vertex as the starting point.

The main function creates an example graph using an adjacency matrix and specifies the desired cycle length n. The program then outputs the total number of cycles of length n in the graph. Note that each cycle is counted twice, so the final result is divided by 2.

*/



