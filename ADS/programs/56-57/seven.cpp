/*
Write a C++ program for  Boruvka's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph.

Input: [(0, 1, 10),(0, 2, 6),(0, 3, 5),(1, 3, 15),(2, 3, 4)]
Output:
Edge 0-3 with weight 5 included in MST
Edge 0-1 with weight 10 included in MST
Edge 2-3 with weight 4 included in MST
Weight of MST is 19

*/


#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	int V; // No. of vertices
	vector<vector<int> >graph; // default dictionary to store graph

	// A utility function to find set of an element i
	// (uses path compression technique)
	int find(vector<int>& parent, int i)
	{
		if (parent[i] == i) {
			return i;
		}
		return find(parent, parent[i]);
	}

	// A function that does union of two sets of x and y
	// (uses union by rank)
	void unionSet(vector<int>& parent, vector<int>& rank,
				int x, int y)
	{
		int xroot = find(parent, x);
		int yroot = find(parent, y);

		// Attach smaller rank tree under root of high rank
		// tree (Union by Rank)
		if (rank[xroot] < rank[yroot]) {
			parent[xroot] = yroot;
		}
		else if (rank[xroot] > rank[yroot]) {
			parent[yroot] = xroot;
		}
		// If ranks are same, then make one as root and
		// increment its rank by one
		else {
			parent[yroot] = xroot;
			rank[xroot]++;
		}
	}

public:
	Graph(int vertices)
	{
		V = vertices;
		graph = vector<vector<int> >();
	}

	// function to add an edge to graph
	void addEdge(int u, int v, int w)
	{
		graph.push_back({ u, v, w });
	}

	// The main function to construct MST using Kruskal's
	// algorithm
	void boruvkaMST()
	{
		vector<int> parent(V);

		// An array to store index of the cheapest edge of
		// subset. It store [u,v,w] for each component
		vector<int> rank(V);
		vector<vector<int> > cheapest(V,
									vector<int>(3, -1));

		// Initially there are V different trees.
		// Finally there will be one tree that will be MST
		int numTrees = V;
		int MSTweight = 0;

		// Create V subsets with single elements
		for (int node = 0; node < V; node++) {
			parent[node] = node;
			rank[node] = 0;
		}

		// Keep combining components (or sets) until all
		// components are not combined into single MST
		while (numTrees > 1) {

			// Traverse through all edges and update
			// cheapest of every component
			for (int i = 0; i < graph.size(); i++) {

				// Find components (or sets) of two corners
				// of current edge
				int u = graph[i][0], v = graph[i][1],
					w = graph[i][2];
				int set1 = find(parent, u),
					set2 = find(parent, v);

				// If two corners of current edge belong to
				// same set, ignore current edge. Else check
				// if current edge is closer to previous
				// cheapest edges of set1 and set2
				if (set1 != set2) {
					if (cheapest[set1][2] == -1
						|| cheapest[set1][2] > w) {
						cheapest[set1] = { u, v, w };
					}
					if (cheapest[set2][2] == -1
						|| cheapest[set2][2] > w) {
						cheapest[set2] = { u, v, w };
					}
				}
			}

			// Consider the above picked cheapest edges and
			// add them to MST
			for (int node = 0; node < V; node++) {

				// Check if cheapest for current set exists
				if (cheapest[node][2] != -1) {
					int u = cheapest[node][0],
						v = cheapest[node][1],
						w = cheapest[node][2];
					int set1 = find(parent, u),
						set2 = find(parent, v);
					if (set1 != set2) {
						MSTweight += w;
						unionSet(parent, rank, set1, set2);
						printf("Edge %d-%d with weight %d "
							"included in MST\n",
							u, v, w);
						numTrees--;
					}
				}
			}
			for (int node = 0; node < V; node++) {

				// reset cheapest array
				cheapest[node][2] = -1;
			}
		}
		printf("Weight of MST is %d\n", MSTweight);
	}
};
int main()
{
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 6);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);

	g.boruvkaMST();
}

/*
The Graph class represents the graph using an adjacency list and includes methods to add edges, find sets, perform union by rank, and implement Boruvka's algorithm.

The find method uses path compression to find the root of a set in which an element belongs.

The unionSet method implements union by rank to merge two sets and update the parent.

The addEdge method adds edges to the graph's adjacency list representation along with their weights.

The boruvkaMST method implements Boruvka's algorithm to find the MST.

a. It initializes parent and rank arrays for the Union-Find data structure.

b. It initializes the cheapest array to store the cheapest edge for each component.

c. The algorithm iteratively selects the cheapest edge for each component.

d. It then adds these edges to the MST if they connect different components.

e. The numTrees variable keeps track of the number of trees (connected components) in the graph.

In the main function:

a. A sample graph is created using the Graph class, and edges with their weights are added to it.

b. The boruvkaMST function is called to find and print the Minimum Spanning Tree using Boruvka's algorithm.

*/



