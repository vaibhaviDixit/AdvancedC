/*
Write a C++ program to find Minimum Spanning Tree of a graph using Reverse Delete Algorithm

Input: graph= [ (0, 1, 4),(0, 7, 8),(1, 2, 8),(1, 7, 11),(2, 3, 7),(2, 8, 2),(2, 5, 4),(3, 4, 9),(3, 5, 14),(4, 5, 10),(5, 6, 2),(6, 7, 1),(6, 8, 6),(7, 8, 7)]

Output:
Edges in MST
(3, 4)
(0, 7)
(2, 3)
(2, 5)
(0, 1)
(5, 6)
(2, 8)
(6, 7)
Total weight of MST is 37

*/

#include<bits/stdc++.h>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
	int V; // No. of vertices
	list<int> *adj;
	vector< pair<int, iPair> > edges;
	void DFS(int v, bool visited[]);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// Returns true if graph is connected
	bool isConnected();

	void reverseDeleteMST();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(v); // Add w to v’s list.
	adj[v].push_back(u); // Add w to v’s list.
	edges.push_back({w, {u, v}});
}

void Graph::DFS(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to
	// this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited);
}

// Returns true if given graph is connected, else false
bool Graph::isConnected()
{
	bool visited[V];
	memset(visited, false, sizeof(visited));

	// Find all reachable vertices from first vertex
	DFS(0, visited);

	// If set of reachable vertices includes all,
	// return true.
	for (int i=1; i<V; i++)
		if (visited[i] == false)
			return false;

	return true;
}

// This function assumes that edge (u, v)
// exists in graph or not,
void Graph::reverseDeleteMST()
{
	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());

	int mst_wt = 0; // Initialize weight of MST

	cout << "Edges in MST\n";

	// Iterate through all sorted edges in
	// decreasing order of weights
	for (int i=edges.size()-1; i>=0; i--)
	{
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		// Remove edge from undirected graph
		adj[u].remove(v);
		adj[v].remove(u);

		// Adding the edge back if removing it
		// causes disconnection. In this case this
		// edge becomes part of MST.
		if (isConnected() == false)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);

			// This edge is part of MST
			cout << "(" << u << ", " << v << ") \n";
			mst_wt += edges[i].first;
		}
	}

	cout << "Total weight of MST is " << mst_wt;
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

	g.reverseDeleteMST();
	return 0;
}

/*
The typedef pair<int, int> iPair creates a shortcut for an integer pair.

The Graph class represents a graph using an adjacency list representation. It includes functions to add edges, check if the graph is connected, and implement the Reverse Delete Algorithm.

The addEdge function adds edges to the adjacency list representation of the graph. The edges are stored in a vector edges, which also holds their weights and vertices.

The DFS function performs Depth-First Search to check if the graph is connected by marking vertices as visited.

The isConnected function uses Depth-First Search to determine if the graph is connected by checking if all vertices are reachable from the first vertex.

The reverseDeleteMST function implements the Reverse Delete Algorithm to find the MST.

a. The edges are sorted in decreasing order of their weights.

b. The algorithm iterates through the sorted edges.

c. For each edge (u, v):

The edge is removed from the graph.
If removing the edge causes the graph to become disconnected, the edge is added back to the graph, and it's considered part of the MST.
d. The total weight of the MST is calculated.

In the main function:

a. A sample graph is created using the Graph class and edges are added to it.

b. The reverseDeleteMST function is called to find and print the Minimum Spanning Tree using the Reverse Delete Algorithm

*/



