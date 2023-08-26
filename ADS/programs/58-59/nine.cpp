/*
Given a graph where every edge has weight as either 0 or 1. A source vertex is also given in the graph. Find the shortest path from the source vertex to
every other vertex.

Input : Source Vertex = 0 and below graph

Output : Shortest distances from given source
         0 0 1 1 2 1 2 1 2

*/

// C++ program to implement single source shortest path for a Binary Graph
#include<bits/stdc++.h>
using namespace std;

/* no.of vertices */
#define V 9

// a structure to represent edges
struct node
{
	// two variable one denote the node
	// and other the weight
	int to, weight;
};

// vector to store edges
vector <node> edges[V];

// Prints shortest distance from given source to
// every other vertex
void zeroOneBFS(int src)
{
	// Initialize distances from given source
	int dist[V];
	for (int i=0; i<V; i++)
		dist[i] = INT_MAX;

	// double ende queue to do BFS.
	deque <int> Q;
	dist[src] = 0;
	Q.push_back(src);

	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop_front();

		for (int i=0; i<edges[v].size(); i++)
		{
			// checking for the optimal distance
			if (dist[edges[v][i].to] > dist[v] + edges[v][i].weight)
			{
				dist[edges[v][i].to] = dist[v] + edges[v][i].weight;

				// Put 0 weight edges to front and 1 weight
				// edges to back so that vertices are processed
				// in increasing order of weights.
				if (edges[v][i].weight == 0)
					Q.push_front(edges[v][i].to);
				else
					Q.push_back(edges[v][i].to);
			}
		}
	}

	// printing the shortest distances
	for (int i=0; i<V; i++)
		cout << dist[i] << " ";
}

void addEdge(int u, int v, int wt)
{
edges[u].push_back({v, wt});
edges[v].push_back({u, wt});
}

int main()
{
	addEdge(0, 1, 0);
	addEdge(0, 7, 1);
	addEdge(1, 7, 1);
	addEdge(1, 2, 1);
	addEdge(2, 3, 0);
	addEdge(2, 5, 0);
	addEdge(2, 8, 1);
	addEdge(3, 4, 1);
	addEdge(3, 5, 1);
	addEdge(4, 5, 1);
	addEdge(5, 6, 1);
	addEdge(6, 7, 1);
	addEdge(7, 8, 1);
	int src = 0;//source node
	zeroOneBFS(src);
	return 0;
}

/*
The program defines the number of vertices as V (constant) and also includes a structure named node to represent edges with attributes to (destination vertex) and weight (weight of the edge).

The edges vector array stores the edges of the graph. Each element of the array is a vector that contains the edges for a specific vertex.

The zeroOneBFS function calculates the shortest distances from the given source using the 0-1 BFS technique.

It initializes an array dist to store the shortest distances from the source.
A double-ended queue (deque) Q is used for BFS traversal.
The algorithm initializes the distance of the source vertex to 0 and pushes it to the deque.
While the deque is not empty, it pops vertices and explores their neighbors.
For each edge of the current vertex, if a shorter path is found, the distance is updated, and vertices with weight 0 are pushed to the front of the deque, while vertices with weight 1 are pushed to the back.
The addEdge function is used to add an edge to the edges vector array with the given source vertex u, destination vertex v, and weight wt.

In the main function, edges are added to the graph using the addEdge function.

The zeroOneBFS function is called with the source vertex src to calculate and print the shortest distances from the source to all other vertices.

*/




