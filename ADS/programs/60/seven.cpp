/*
Given a weighted directed graph, find the shortest distance between every pair of vertices using Floyd-Warshall's algorithm.

Input:
 0, 5, INF, 10
 INF, 0, 3, INF
 INF, INF, 0, 1
 INF, INF, INF, 0

Output:
The following matrix shows the shortest distances between every pair of vertices:

0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0


*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);


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
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
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
			if (dist[i][j] == INF){
				cout << "INF"<< " ";
			}
			else{
				cout << dist[i][j] << " ";
			}
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
This C++ code implements the Floyd-Warshall algorithm, a dynamic programming approach to find the shortest paths between all pairs
of vertices in a weighted graph. The algorithm works for both directed and undirected graphs with positive or negative edge weights,
but it doesn't work correctly for graphs with negative cycles.

*/




