/*
Given a Weighted Directed Acyclic Graph and a source vertex in the graph, find the shortest paths from given source to all other vertices.

Input: [ (0, 1, 5),(0, 2, 3),(1, 3, 6),(1, 2, 2),(2, 4, 4),(2, 5, 2),(2, 3, 7),(3, 4, -1),(4, 5, -2) ]
Output: Following are shortest distances from source 1 nINF 0 2 6 5 3

*/

// C++ program to find single source shortest paths for Directed Acyclic Graphs

#include<iostream>
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

// Graph is represented using adjacency list. Every node
// of adjacency list contains vertex number of the vertex
// to which edge connects. It also
// contains weight of the edge
class AdjListNode
{
	int v;
	int weight;
public:
	AdjListNode(int _v, int _w) { v = _v; weight = _w;}
	int getV()	 { return v; }
	int getWeight() { return weight; }
};

// Class to represent a graph using adjacency
// list representation
class Graph
{
	int V; // No. of vertices'

	// Pointer to an array containing adjacency lists
	list<AdjListNode> *adj;

	// A function used by shortestPath
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int weight);

	// Finds shortest paths from given source vertex
	void shortestPath(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
	AdjListNode node(v, weight);
	adj[u].push_back(node); // Add v to u's list
}

// A recursive function used by shortestPath.
// See below link for details
// https://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		AdjListNode node = *i;
		if (!visited[node.getV()])
			topologicalSortUtil(node.getV(), visited, Stack);
	}

	// Push current vertex to stack which stores topological sort
	Stack.push(v);
}

// The function to find shortest paths from given vertex.
// It uses recursive topologicalSortUtil() to get topological
// sorting of given graph.
void Graph::shortestPath(int s)
{
	stack<int> Stack;
	int dist[V];

	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store
	// Topological Sort starting from all vertices
	// one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Initialize distances to all vertices as
	// infinite and distance to source as 0
	for (int i = 0; i < V; i++)
		dist[i] = INF;
	dist[s] = 0;

	// Process vertices in topological order
	while (Stack.empty() == false)
	{
		// Get the next vertex from topological order
		int u = Stack.top();
		Stack.pop();

		// Update distances of all adjacent vertices
		list<AdjListNode>::iterator i;
		if (dist[u] != INF)
		{
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (dist[i->getV()] > dist[u] + i->getWeight())
				dist[i->getV()] = dist[u] + i->getWeight();
		}
	}

	// Print the calculated shortest distances
	for (int i = 0; i < V; i++)
		(dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
}

int main()
{
	// Create a graph given in the above diagram.
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with
	// following mappings: 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	cout << "Following are shortest distances from source " << s <<" n";
	g.shortestPath(s);

	return 0;
}

/*
The constant INF is defined to represent infinity, and V is defined to represent the number of vertices in the graph.

The AdjListNode class represents a vertex number and its corresponding weight.

The Graph class represents the graph using an adjacency list:

It contains a list of AdjListNode for each vertex.
The addEdge function is used to add an edge to the graph.
The topologicalSortUtil function is a recursive helper function to perform topological sorting of the vertices.
The shortestPath function implements the shortest path algorithm for DAGs:

It performs topological sorting to ensure that the vertices are processed in the correct order.
It initializes distances to all vertices as infinity except for the source vertex, which is set to 0.
It iterates through the vertices in topological order and updates the shortest distances to adjacent vertices.
The main function creates a DAG using the Graph class and adds edges to it.

The source vertex s is set to 1.
The shortestPath function is called to compute and print the shortest distances from the source vertex to all other vertices.

*/





