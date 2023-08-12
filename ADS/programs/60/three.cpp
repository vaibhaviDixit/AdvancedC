/*
You are given an undirected graph with V vertices and E edges, along with a node X. Your task is to determine the level of node X in
the undirected graph when traversing the graph starting from vertex 0. If node X is not present in the graph, return -1.

Input: V = 5, Edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}}, X = 1
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the level of the given node
int findLevel(int N, vector<vector<int> >& edges, int X)
{

	// Variable to store maximum vertex of graph
	int maxVertex = 0;
	for (auto it : edges) {
		maxVertex = max({ maxVertex, it[0], it[1] });
	}

	// Creating adjacency list
	vector<int> adj[maxVertex + 1];
	for (int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	// If X is not present then return -1
	if (X > maxVertex || adj[X].size() == 0)
		return -1;

	// Initialize a Queue for BFS traversal
	queue<int> q;
	q.push(0);
	int level = 0;

	// Visited array to mark the already visited nodes
	vector<int> visited(maxVertex + 1, 0);
	visited[0] = 1;

	// BFS traversal
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			auto currentNode = q.front();
			q.pop();
			if (currentNode == X) {
				return level;
			}

			for (auto it : adj[currentNode]) {
				if (!visited[it]) {
					q.push(it);
					visited[it] = 1;
				}
			}
		}
		level++;
	}

	return -1;
}


int main()
{
	int V = 5;
	vector<vector<int> > edges= { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 2, 4 } };
	int X = 1;

	// Function call
	int level = findLevel(V, edges, X);
	cout << level << endl;

	return 0;
}

/*
This C++ program focuses on finding the level of a given node in an undirected graph. The graph is represented using an adjacency list, and the task involves performing Breadth-First Search (BFS) traversal starting from vertex 0 to determine the level of a specified node X.

Here's a breakdown of the program:

The findLevel function takes the total number of vertices N, the list of edges edges, and the node X as inputs and returns the level of node X in the graph.

To start, the program identifies the maximum vertex value (maxVertex) by iterating through the edges. This helps in creating the adjacency list.

The adjacency list adj is then constructed, with each vertex mapping to its adjacent vertices.

If the specified node X is not within the range of vertices (greater than maxVertex) or if it has no adjacent nodes (i.e., no edges), the function returns -1 as the node X is not present in the graph.

A BFS traversal is performed using a queue (q). The traversal starts from vertex 0.

A visited array is initialized to mark nodes as visited. The index corresponds to the vertex number, and the value indicates whether the vertex has been visited (1) or not (0).

The main BFS loop continues as long as the queue is not empty. Within each iteration, the current level's nodes are processed. For each node, its adjacent nodes are explored, and if they haven't been visited, they are added to the queue and marked as visited.

The BFS traversal continues level by level, incrementing the level counter with each level traversal.

If the BFS traversal encounters the node X, the function returns the level at which it was found.

If the BFS traversal completes without encountering node X, the function returns -1 to indicate that node X is not reachable from vertex 0.

In the main function, a sample graph with 5 vertices and a list of edges is provided. The findLevel function is called with the graph information and the node X. The returned level is printed to the console.

*/
