/*
Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9


Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0

*/


// C++ Program to find Dijkstra's shortest path using priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph {
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list<pair<int, int> >* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!pq.empty()) {
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// 'i' is used to get all adjacent vertices of a
		// vertex
		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			// Get vertex label and weight of current
			// adjacent of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight) {
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
	// create the graph given in above figure
	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	// Function call
	g.shortestPath(0);

	return 0;
}

/*
The constant INF is defined to represent infinity. It's used to initialize distances in the graph.

The program defines an alias iPair for the data type pair<int, int>, which represents a pair of integers.

The Graph class is defined to represent a directed graph using an adjacency list representation.

V: Number of vertices in the graph.
adj: An array of lists, where each element represents the adjacency list for a vertex.
The constructor of the Graph class initializes the number of vertices and allocates memory for the adjacency list.

The addEdge method adds a directed edge between two vertices along with the corresponding weight.

The shortestPath method implements Dijkstra's algorithm to find the shortest paths from a given source vertex (src) to all other vertices.

A priority queue pq is used to keep track of vertices being processed.
A vector dist is used to store the shortest distances from the source to each vertex, initialized to infinity.
The source vertex is inserted into the priority queue with a distance of 0.
The algorithm iteratively processes vertices from the priority queue while updating distances.
For each vertex, its adjacent vertices are checked. If a shorter path to an adjacent vertex is found, the distance is updated and the vertex is inserted into the priority queue.
After the algorithm completes, the shortest distances are printed.
The main function:

Creates a Graph object g with the specified number of vertices.
Adds directed edges using the addEdge method.
Calls the shortestPath method to find and print the shortest paths from the source vertex (vertex 0 in this case) to all other vertices.

*/



