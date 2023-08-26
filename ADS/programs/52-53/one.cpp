/*
Given the root of a Directed graph, The task is to check whether the graph contains a cycle or not.

Input: N = 4, E = 6
       edges=[(0, 1),(0, 2),(1, 2),(2, 0),(2, 3),(3, 3)]
Output: Graph contains cycle

Input: N=6, E=6
       edges= [(0, 1),(0, 2),(1, 3),(4, 1),(4, 5),(5, 3)]
Output: Graph does not contain cycle.

*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
	// No. of vertices
	int V;

	// Pointer to an array containing adjacency lists
	list<int>* adj;

	// Used by isCyclic()
	bool isCyclicUtil(int v, bool visited[], bool* rs);

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

// DFS function to find if a cycle exists
bool Graph::isCyclicUtil(int v, bool visited[],
						bool* recStack)
{
	if (visited[v] == false) {
		// Mark the current node as visited
		// and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this
		// vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (!visited[*i]
				&& isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}
	}

	// Remove the vertex from recursion stack
	recStack[v] = false;
	return false;
}

// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited
	// and not part of recursion stack
	bool* visited = new bool[V];
	bool* recStack = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function
	// to detect cycle in different DFS trees
	for (int i = 0; i < V; i++)
		if (!visited[i]
			&& isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

int main()
{
	// Create a graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	// Function call
	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}

/*
This code defines a C++ class Graph that represents a directed graph and provides methods to add directed edges and check for cycles using
Depth-First Search (DFS). The class includes member functions for adding edges, performing DFS traversal, and determining whether the graph
contains a cycle. The main() function demonstrates the usage of this class by creating a graph with 4 vertices and testing for the presence
of cycles.

*/


