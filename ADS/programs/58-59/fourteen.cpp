/*
Write a C++ program to find articulation points in an undirected graph
Note: A vertex v is an articulation point (also called cut vertex) if removing v increases the number of connected components.

Input: (1, 2),( 2, 3),(1, 3),(3, 4),(4, 5)
Output:  Articulation points in the graph 3 4

*/


#include <bits/stdc++.h>
using namespace std;

// A recursive function to traverse the graph without
// considering the ith vertex and its associated edges
void dfs(vector<int> adj[], int V, vector<int>& vis,
		int i, int curr)
{
	vis[curr] = 1;
	for (auto x : adj[curr]) {
		if (x != i) {
			if (!vis[x]) {
				dfs(adj, V, vis, i, x);
			}
		}
	}
}

// Function to find Articulation Points in the graph
void AP(vector<int> adj[], int V)
{

	// Iterating over all the vertices and for each vertex i
	// remove the vertex and check whether the graph remains
	// connected.
	for (int i = 1; i <= V; i++) {

		// To keep track of number of components of graph
		int components = 0;

		// To keep track of visited vertices
		vector<int> vis(V + 1, 0);

		// Iterating over the graph after removing vertex i
		// and its associated edges
		for (int j = 1; j <= V; j++) {
			if (j != i) {

				// If the jth vertex is not visited it will
				// form a new component.
				if (!vis[j]) {

					// Increasing the number of components.
					components++;

					// dfs call for the jth vertex
					dfs(adj, V, vis, i, j);
				}
			}
		}
		// If number of components is more than 1 after
		// removing the ith vertex then vertex i is an
		// articulation point.
		if (components > 1) {
			cout << i << "\n";
		}
	}
}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


int main()
{
	// Create graphs given in above diagrams
	cout << "Articulation points in the graph \n";
	int V = 5;
	vector<int> adj1[V + 1];
	addEdge(adj1, 1, 2);
	addEdge(adj1, 2, 3);
	addEdge(adj1, 1, 3);
	addEdge(adj1, 3, 4);
	addEdge(adj1, 4, 5);
	AP(adj1, V);

	return 0;
}

/*
The program defines a function dfs which performs depth-first traversal of the graph while excluding the ith vertex and its associated edges. It is used to mark visited vertices.

The AP function is used to find articulation points in the graph:

It iterates through each vertex and checks the number of connected components after removing that vertex.
For each vertex i, it initializes a counter components to keep track of the number of connected components.
It uses a vector vis to keep track of visited vertices.
It then iterates through the graph after removing vertex i and its associated edges.
If it encounters an unvisited vertex, it performs a depth-first search to mark all connected vertices as visited and increments the components counter.
After the loop, if the number of components is greater than 1, it means removing the vertex i increases the number of connected components, making it an articulation point.
The addEdge function is a utility function to add edges to the adjacency list representation of the graph.

In the main function:

The graph is defined using an adjacency list represented as an array of vectors.
Edges are added to the graph using the addEdge function.
The AP function is called to find and print the articulation points in the graph.
The program runs a test case on a specific graph and prints the articulation points.

*/

