/*

Write  a C++ program to print topological sorting of a graph using indegrees.

Input: graph=[(5, 2),(5, 0),(4, 0),(4, 1),(2, 3),(3, 1)]
Output: 4 5 2 0 3 1

*/

#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	// No. of vertices'
	int V;

	// Pointer to an array containing
	// adjacency listsList
	list<int>* adj;

public:
	// Constructor
	Graph(int V);

	// Function to add an edge to graph
	void addEdge(int u, int v);

	// prints a Topological Sort of
	// the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

// The function to do
// Topological Sort.
void Graph::topologicalSort()
{
	// Create a vector to store
	// indegrees of all
	// vertices. Initialize all
	// indegrees as 0.
	vector<int> in_degree(V, 0);

	// Traverse adjacency lists
	// to fill indegrees of
	// vertices. This step
	// takes O(V+E) time
	for (int u = 0; u < V; u++) {
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}

	// Create an queue and enqueue
	// all vertices with indegree 0
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	// Initialize count of visited vertices
	int cnt = 0;

	// Create a vector to store
	// result (A topological
	// ordering of the vertices)
	vector<int> top_order;

	// One by one dequeue vertices
	// from queue and enqueue
	// adjacents if indegree of
	// adjacent becomes 0
	while (!q.empty()) {
		// Extract front of queue
		// (or perform dequeue)
		// and add it to topological order
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// Iterate through all its
		// neighbouring nodes
		// of dequeued node u and
		// decrease their in-degree
		// by 1
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)

			// If in-degree becomes zero,
			// add it to queue
			if (--in_degree[*itr] == 0)
				q.push(*itr);

		cnt++;
	}

	// Check if there was a cycle
	if (cnt != V) {
		cout << "There exists a cycle in the graph\n";
		return;
	}

	// Print topological order
	for (int i = 0; i < top_order.size(); i++)
		cout << top_order[i] << " ";
	cout << endl;
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

	cout << "Following is a Topological Sort of\n";
	g.topologicalSort();

	return 0;
}

/*
This C++ program uses the indegrees approach to perform topological sorting of a graph. The Graph class represents the graph, with methods to add
edges and perform topological sorting. The program calculates indegrees for all vertices, enqueues vertices with indegree 0, and then performs a
breadth-first traversal while decrementing the indegrees of adjacent vertices. The topological order is printed as output.
If the count of visited vertices is not equal to the total number of vertices, there is a cycle in the graph.
The program demonstrates the algorithm using the provided example graph.

*/




