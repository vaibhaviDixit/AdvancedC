/*
 A C++ program to print topological sorting of a DAG using departure time of vertex

 Input: graph=[(5, 2),(5, 0),(4, 0),(4, 1),(2, 3),(3, 1)]
 Output: 5 4 2 3 1 0

*/

#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph using adjacency
// list representation
class Graph {
	int V; // No. of vertices
	// Pointer to an array containing adjacency lists
	list<int>* adj;

public:
	Graph(int); // Constructor
	~Graph(); // Destructor

	// function to add an edge to graph
	void addEdge(int, int);

	// The function to do DFS traversal
	void DFS(int, vector<bool>&, vector<int>&, int&);

	// The function to do Topological Sort.
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	this->adj = new list<int>[V];
}

Graph::~Graph() { delete[] this->adj; }

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// The function to do DFS() and stores departure time
// of all vertex
void Graph::DFS(int v, vector<bool>& visited,
				vector<int>& departure, int& time)
{
	visited[v] = true;
	// time++; // arrival time of vertex v

	for (int i : adj[v])
		if (!visited[i])
			DFS(i, visited, departure, time);

	// set departure time of vertex v
	departure[time++] = v;
}

// The function to do Topological Sort. It uses DFS().
void Graph::topologicalSort()
{
	// vector to store departure time of vertex.
	vector<int> departure(V, -1);

	// Mark all the vertices as not visited
	vector<bool> visited(V, false);
	int time = 0;

	// perform DFS on all unvisited vertices
	for (int i = 0; i < V; i++) {
		if (visited[i] == 0) {
			DFS(i, visited, departure, time);
		}
	}
	// print the topological sort
	for (int i = V - 1; i >= 0; i--)
		cout << departure[i] << " ";
}


int main()
{

	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Topological Sort of the given graph is \n";
	g.topologicalSort();

	return 0;
}

/*
This C++ program performs a topological sorting of a Directed Acyclic Graph (DAG) using Depth-First Search (DFS). The graph is represented using an adjacency list.

The Graph class represents the graph and includes methods to add edges, perform DFS traversal, and perform topological sorting. The DFS method performs the DFS traversal and stores the departure time of each vertex. The topologicalSort method iterates through all vertices and calls DFS for unvisited vertices. After completing DFS, it prints the vertices in topological order based on their departure time.

The program demonstrates this approach using the provided example graph and prints the topological sorting of the graph.

*/
