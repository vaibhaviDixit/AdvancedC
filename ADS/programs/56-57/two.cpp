/*
Write a CPP Program for Kruskal’s Minimum Spanning Tree (MST) Algorithm.

Input: graph=[(0, 1, 10),(1, 3, 15),(2, 3, 4),(2, 0, 6),(0, 3, 5)]
Output:
Following are the edges in the constructed MST
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Cost Spanning Tree: 19


*/


#include <bits/stdc++.h>
using namespace std;

// DSU data structure
// path compression + rank by union
class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	// Union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
			}
			else if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
			}
			else {
				parent[s2] = s1;
				rank[s1] += 1;
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	// Function to add edge in a graph
	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst()
	{
		// Sort all edges
		sort(edgelist.begin(), edgelist.end());

		// Initialize the DSU
		DSU s(V);
		int ans = 0;
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// Take this edge in MST if it does
			// not forms a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w
					<< endl;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans;
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	// Function call
	g.kruskals_mst();

	return 0;
}

/*


*/

/*
A Disjoint Set Union (DSU) data structure is defined using a class named DSU. The DSU implements both path compression and rank by union techniques, which help in efficient finding and union of sets. This data structure will be used to track connected components and detect cycles during the construction of the MST.

Inside the DSU class, the constructor initializes arrays parent and rank. The parent array stores the parent of each element in the set, and the rank array is used to keep track of the height of the trees in the forest. All elements are initially in their own disjoint sets, so parent is set to -1 and rank is set to 1.

The find function in the DSU class implements path compression while finding the representative of the set to which an element belongs.

The unite function in the DSU class implements rank by union. It joins two sets represented by their representatives and ensures that the smaller tree is attached to the root of the larger tree.

A class named Graph is defined to represent the graph.

Inside the Graph class, the constructor is defined to initialize the number of vertices (V).

The addEdge function is used to add an edge to the graph. Each edge is represented as a tuple {weight, vertex1, vertex2} and is added to the edgelist.

The kruskals_mst function implements Kruskal's algorithm to find the MST.

a. The edgelist is sorted based on edge weights.

b. A DSU instance s is created with the given number of vertices V.

c. A loop iterates through the sorted edgelist, and for each edge, the vertices and weight are extracted.

d. If adding the current edge to the MST doesn't form a cycle (i.e., the vertices belong to different sets), the edge is included in the MST. The DSU is updated using the unite function.

e. The total weight of the MST (ans) is calculated.

In the main function:

a. An instance of the Graph class is created with 4 vertices.

b. Edges are added to the graph using the addEdge function.

c. The kruskals_mst function is called to find and print the MST.

*/


