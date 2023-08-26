/*
Write a C++ program for Prim's Minimum Spanning Tree algorithm.

Input:
{ 0, 2, 0, 6, 0 }
{ 2, 0, 3, 8, 5 }
{ 0, 3, 0, 0, 7 }
{ 6, 8, 0, 0, 9 }
{ 0, 5, 7, 9, 0 }

Output:
Edge    Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5

*/


#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];

	// Key values used to pick minimum weight edge in cut
	int key[V];

	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first
	// vertex.
	key[0] = 0;

	// First node is always root of MST
	parent[0] = -1;

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {

		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent
			// vertices of m mstSet[v] is false for vertices
			// not yet included in MST Update the key only
			// if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// Print the constructed MST
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	primMST(graph);

	return 0;
}

/*

The graph is represented by an adjacency matrix where graph[i][j] represents the weight of the edge between vertex i and vertex j. The graph provided in the main function is a 5x5 matrix where each cell (i, j) represents the weight of the edge between vertices i and j.

The minKey function is a utility function that returns the index of the vertex with the minimum key value among the set of vertices not yet included in the MST. Here, key[] holds the minimum weight of edges connecting vertices to the current MST, and mstSet[] marks whether a vertex is already included in the MST.

The printMST function is used to print the edges and their weights in the constructed MST. It iterates through the parent array, which stores the parent vertex for each vertex in the MST.

The primMST function is where the actual Prim's algorithm is implemented. It initializes various arrays and loops through the vertices to construct the MST.

a. The key array holds the minimum edge weight to connect each vertex to the MST. It's initialized to a large value initially.

b. The mstSet array marks whether a vertex is included in the MST. All vertices are marked as not included initially.

c. The first vertex (vertex 0) is added to the MST. Its key is set to 0 to ensure it's selected first, and its parent is set to -1 to mark it as the root.

d. The loop runs V - 1 times, where V is the number of vertices in the graph, because an MST has exactly V - 1 edges.

e. Inside the loop, the vertex with the minimum key value is selected using the minKey function.

f. The selected vertex is added to the MST by marking it as part of mstSet.

g. The key values and parent indices of adjacent vertices are updated if the current vertex leads to a smaller edge weight.

In the main function, the graph adjacency matrix is provided. It represents the weights of the edges between vertices.

The primMST(graph) function is called to find and print the MST.

*/
