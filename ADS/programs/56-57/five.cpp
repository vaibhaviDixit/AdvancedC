/*
 A C++ program for getting minimum product spanning tree The program is for adjacency matrix representation of the graph

 Input:
 		{ 0, 2, 0, 6, 0 }
		{ 2, 0, 3, 8, 5 }
		{ 0, 3, 0, 0, 7 }
		{ 6, 8, 0, 0, 9 }
		{ 0, 5, 7, 9, 0 }

Output: Edge Weight
0 - 1 2
1 - 2 3
0 - 3 6
1 - 4 5
Minimum Obtainable product is 180

*/

#include <bits/stdc++.h>

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum
// key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed MST
// stored in parent[] and print Minimum Obtainable product
int printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge Weight\n");
	int minProduct = 1;
	for (int i = 1; i < V; i++) {
		printf("%d - %d %d \n",
			parent[i], i, graph[i][parent[i]]);

		minProduct *= graph[i][parent[i]];
	}
	printf("Minimum Obtainable product is %d\n",
		minProduct);
}

// Function to construct and print MST for a graph
// represented using adjacency matrix representation
// inputGraph is sent for printing actual edges and
// logGraph is sent for actual MST operations
void primMST(int inputGraph[V][V], double logGraph[V][V])
{
	int parent[V]; // Array to store constructed MST
	int key[V]; // Key values used to pick minimum
	// weight edge in cut
	bool mstSet[V]; // To represent set of vertices not
	// yet included in MST

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	key[0] = 0; // Make key 0 so that this vertex is
	// picked as first vertex
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum key vertex from the set of
		// vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of the
		// adjacent vertices of the picked vertex.
		// Consider only those vertices which are not yet
		// included in MST
		for (int v = 0; v < V; v++)

			// logGraph[u][v] is non zero only for
			// adjacent vertices of m mstSet[v] is false
			// for vertices not yet included in MST
			// Update the key only if logGraph[u][v] is
			// smaller than key[v]
			if (logGraph[u][v] > 0 && mstSet[v] == false && logGraph[u][v] < key[v])

				parent[v] = u, key[v] = logGraph[u][v];
	}

	// print the constructed MST
	printMST(parent, V, inputGraph);
}

// Method to get minimum product spanning tree
void minimumProductMST(int graph[V][V])
{
	double logGraph[V][V];

	// Constructing logGraph from original graph
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j] > 0)
				logGraph[i][j] = log(graph[i][j]);
			else
				logGraph[i][j] = 0;
		}
	}

	// Applying standard Prim's MST algorithm on
	// Log graph.
	primMST(graph, logGraph);
}

int main()
{

	int graph[V][V] = {
		{ 0, 2, 0, 6, 0 },
		{ 2, 0, 3, 8, 5 },
		{ 0, 3, 0, 0, 7 },
		{ 6, 8, 0, 0, 9 },
		{ 0, 5, 7, 9, 0 },
	};

	// Print the solution
	minimumProductMST(graph);

	return 0;
}

/*
The number of vertices in the graph is defined as V.

The minKey function finds the vertex with the minimum key value among the vertices not yet included in the Minimum Spanning Tree (MST). It returns the index of the minimum key value.

The printMST function is used to print the constructed MST, including edge weights. It also calculates and prints the minimum obtainable product.

The primMST function constructs the Minimum Product Spanning Tree using a variation of Prim's algorithm. It takes two input graphs: inputGraph is used to print the actual edges, and logGraph is used for the MST operations. The algorithm works with the logarithm of edge weights.

The minimumProductMST function calculates the MPST by converting edge weights into logarithmic form and then applying the modified Prim's algorithm.

In the main function:

a. A sample graph represented by the adjacency matrix graph is provided. Edge weights are defined between pairs of vertices.

b. The minimumProductMST function is called to find and print the Minimum Product Spanning Tree.

*/
