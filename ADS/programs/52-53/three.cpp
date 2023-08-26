/*
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least
one cycle, else return false. This approach should strictly follows the algorithm in CLRS book.

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes

Input:n = 4, e = 3
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 3
Output:No

*/

#include <bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

// Graph class represents a directed graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices
	list<int>* adj; // adjacency lists

	// DFS traversal of the vertices reachable from v
	bool DFSUtil(int v, int color[]);
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	bool isCyclic();
};

// Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Utility function to add an edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// Recursive function to find if there is back edge
// in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(int u, int color[])
{
	// GRAY : This vertex is being processed (DFS
	//		 for this vertex has started, but not
	//		 ended (or this vertex is in function
	//		 call stack)
	color[u] = GRAY;

	// Iterate through all adjacent vertices
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // An adjacent of u

		// If there is
		if (color[v] == GRAY)
		return true;

		// If v is not processed and there is a back
		// edge in subtree rooted with v
		if (color[v] == WHITE && DFSUtil(v, color))
		return true;
	}

	// Mark this vertex as processed
	color[u] = BLACK;

	return false;
}

// Returns true if there is a cycle in graph
bool Graph::isCyclic()
{
	// Initialize color of all vertices as WHITE
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = WHITE;

	// Do a DFS traversal beginning with all
	// vertices
	for (int i = 0; i < V; i++)
		if (color[i] == WHITE)
		if (DFSUtil(i, color) == true)
			return true;

	return false;
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";

	return 0;
}

/*
This C++ code implements a Depth-First Search (DFS) based approach to detect cycles in a directed graph. The code defines a Graph class that represents a directed graph using adjacency lists. The class provides methods to add edges and check for cycles.

The DFSUtil function is a recursive utility that checks for back edges during DFS traversal, marking vertices as WHITE (not visited), GRAY (currently being processed), and BLACK (processed).

The isCyclic function initializes vertex colors, performs DFS starting from each unvisited vertex, and checks for cycles using the DFSUtil function.

The main function creates a graph and tests for cycles using the isCyclic method, displaying whether or not a cycle exists in the graph.

*/


