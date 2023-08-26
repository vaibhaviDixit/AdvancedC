/*
 Write a CPP program to find shortest distance in a multistage graph.

 Input:
    {{INF, 1, 2, 5, INF, INF, INF, INF}
	{INF, INF, INF, INF, 4, 11, INF, INF}
	{INF, INF, INF, INF, 9, 5, 16, INF}
	{INF, INF, INF, INF, INF, INF, 2, INF}
	{INF, INF, INF, INF, INF, INF, INF, 18}
	{INF, INF, INF, INF, INF, INF, INF, 13}
	{INF, INF, INF, INF, INF, INF, INF, 2}
	{INF, INF, INF, INF, INF, INF, INF, INF}}

 Output: 9

*/


#include<bits/stdc++.h>
using namespace std;

#define N 8
#define INF INT_MAX

// Returns shortest distance from 0 to
// N-1.
int shortestDist(int graph[N][N]) {

	// dist[i] is going to store shortest
	// distance from node i to node N-1.
	int dist[N];

	dist[N-1] = 0;

	// Calculating shortest path for
	// rest of the nodes
	for (int i = N-2 ; i >= 0 ; i--)
	{

		// Initialize distance from i to
		// destination (N-1)
		dist[i] = INF;

		// Check all nodes of next stages
		// to find shortest distance from
		// i to N-1.
		for (int j = i ; j < N ; j++)
		{
			// Reject if no edge exists
			if (graph[i][j] == INF)
				continue;

			// We apply equation to
			// distance to target through j.
			// and compare with minimum distance
			// so far.
			dist[i] = min(dist[i], graph[i][j] +
										dist[j]);
		}
	}

	return dist[0];
}


int main()
{
	// Graph stored in the form of an adjacency Matrix
	int graph[N][N] =
	{{INF, 1, 2, 5, INF, INF, INF, INF},
	{INF, INF, INF, INF, 4, 11, INF, INF},
	{INF, INF, INF, INF, 9, 5, 16, INF},
	{INF, INF, INF, INF, INF, INF, 2, INF},
	{INF, INF, INF, INF, INF, INF, INF, 18},
	{INF, INF, INF, INF, INF, INF, INF, 13},
	{INF, INF, INF, INF, INF, INF, INF, 2},
	{INF, INF, INF, INF, INF, INF, INF, INF}};

	cout << shortestDist(graph);
	return 0;
}

/*
The program defines constants: N represents the number of vertices in the graph, and INF represents an infinite distance (unreachable).

The shortestDist function calculates the shortest distance from the source node (0) to the destination node (N-1) using dynamic programming.

It initializes the dist array to store the shortest distances from each vertex to the destination.
Starting from the second-to-last vertex (N-2), it iterates through the vertices in reverse order.
For each vertex, it initializes the distance as infinite.
It then checks all vertices in the next stages and updates the distance if a shorter path is found.
The calculated shortest distance for vertex i is stored in dist[i].
The main function initializes a 2D array graph to represent the multistage graph's adjacency matrix.

graph[i][j] stores the weight of the edge from vertex i to vertex j. If there is no edge, it's initialized as INF.
The adjacency matrix defines the connectivity and weights between vertices in the graph.
The shortestDist function is called with the graph matrix as an argument.

The calculated shortest distance is printed.

*/

