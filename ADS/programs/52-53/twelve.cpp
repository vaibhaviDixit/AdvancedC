/*
Write a C++ program to find maximum edges after adding which graph still remains a DAG.

Input: graph=[(5, 2),(5, 0),(4, 0),(4, 1),(2, 3),(3, 1)]
Output: 4-5 4-2 4-3 5-3 5-1 2-0 2-1 0-3 0-1

*/


#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V; // No. of vertices

	// Pointer to a list containing adjacency list
	list<int>* adj;

	// Vector to store indegree of vertices
	vector<int> indegree;

	// function returns a topological sort
	vector<int> topologicalSort();

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Prints all edges that can be added without making any
	// cycle
	void maximumEdgeAddition();
};

// Constructor of graph
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];

	// Initialising all indegree with 0
	for (int i = 0; i < V; i++)
		indegree.push_back(0);
}

// Utility function to add edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.

	// increasing inner degree of w by 1
	indegree[w]++;
}

// Main function to print maximum edges that can be added
vector<int> Graph::topologicalSort()
{
	vector<int> topological;
	queue<int> q;

	// In starting push all node with indegree 0
	for (int i = 0; i < V; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		// push the node into topological vector
		topological.push_back(t);

		// reducing indegree of adjacent vertices
		for (list<int>::iterator j = adj[t].begin();
			j != adj[t].end(); j++) {
			indegree[*j]--;

			// if indegree becomes 0, just push
			// into queue
			if (indegree[*j] == 0)
				q.push(*j);
		}
	}
	return topological;
}

// The function prints all edges that can be
// added without making any cycle
// It uses recursive topologicalSort()
void Graph::maximumEdgeAddition()
{
	bool* visited = new bool[V];
	vector<int> topo = topologicalSort();

	// looping for all nodes
	for (int i = 0; i < topo.size(); i++) {
		int t = topo[i];

		// In below loop we mark the adjacent node of t
		for (list<int>::iterator j = adj[t].begin();
			j != adj[t].end(); j++)
			visited[*j] = true;

		// In below loop unmarked nodes are printed
		for (int j = i + 1; j < topo.size(); j++) {
			// if not marked, then we can make an edge
			// between t and j
			if (!visited[topo[j]])
				cout << t << "-" << topo[j] << " ";

			visited[topo[j]] = false;
		}
	}
}


int main()
{

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 4);


	g.maximumEdgeAddition();
	return 0;
}
/*
This C++ program finds the maximum number of edges that can be added to a directed acyclic graph (DAG) without creating a cycle.
It uses the topological sorting approach. The Graph class represents the graph and includes methods to add edges, perform topological sorting,
and find the maximum edges that can be added. The topologicalSort method returns a vector with the topological ordering of the vertices.
The maximumEdgeAddition method iterates through the vertices, marks adjacent nodes, and prints unmarked nodes to identify the edges that can be added.
The program demonstrates this approach using the provided example graph.
*/



