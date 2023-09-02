/*

The Floyd Warshall Algorithm is for solving all pairs of shortest-path problems.
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed Graph.
It is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph.
This algorithm follows the dynamic programming approach to find the shortest path.

Input:
{ 0, 5, INF, 10 }
{ INF, 0, 3, INF }
{ INF, INF, 0, 1 }
{ INF, INF, INF, 0 }

Output:
The following matrix shows the shortest distances between every pair of vertices
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0

*/


#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

/* Define Infinite as a large enough value.This value will be used for vertices not connected to each other */

#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall(int dist[][V])
{

	int i, j, k;

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the above picked source
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest distances between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{

	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	// Function call
	floydWarshall(graph);
	return 0;
}
/*
Function printSolution: This utility function is used to print the solution matrix showing the shortest distances between every pair of vertices.

Function floydWarshall: This function implements the Floyd-Warshall algorithm to find the shortest distances between all pairs of vertices. It takes a 2D array dist as input, where dist[i][j] represents the shortest distance from vertex i to vertex j. The function iterates over all vertices as intermediate vertices (k), and for each pair of vertices (i, j), it updates the shortest distance using the intermediate vertex k if a shorter path is found.

The algorithm iterates over each vertex as the intermediate vertex (k).
For each pair of vertices (i, j), it checks if the distance from i to j can be reduced by going through vertex k. If the path through vertex k is shorter, it updates the value of dist[i][j].
This process is repeated for all vertices, gradually building up the shortest distance matrix.
Main Function:

The main function initializes a 2D array graph representing the weighted adjacency matrix of the graph. It contains the edge weights between each pair of vertices.
It then calls the floydWarshall function with the graph matrix as input to compute the shortest distances between all pairs of vertices.

*/




