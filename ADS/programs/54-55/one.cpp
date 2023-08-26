/*
Given a directed graph, find out whether the graph is strongly connected or not.
A directed graph is strongly connected if there is a path between any two pair of vertices. ((Kosaraju using DFS)

Input: graph=[ (0, 1),(1, 2),(2, 3),(3, 0),(2, 4),(4, 2) ]
Output: Yes

Input: graph=[(0, 1),(1, 2),(2, 3)]
Output: No

*/

// C++ program to check if a given directed graph is strongly connected or not
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // An array of adjacency lists

	// A recursive function to print DFS starting from v
	void DFSUtil(int v, bool visited[]);
public:
	// Constructor and Destructor
	Graph(int V) { this->V = V; adj = new list<int>[V];}
	~Graph() { delete [] adj; }

	// Method to add an edge
	void addEdge(int v, int w);

	// The main function that returns true if the
	// graph is strongly connected, otherwise false
	bool isSC();

	// Function that returns reverse (or transpose)
	// of this graph
	Graph getTranspose();
};

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// Function that returns reverse (or transpose) of this graph
Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// The main function that returns true if graph is strongly connected
bool Graph::isSC()
{
	// St1p 1: Mark all the vertices as not visited
	// (For first DFS)
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Step 2: Do DFS traversal starting from first vertex.
	DFSUtil(0, visited);

	// If DFS traversal doesn’t visit all vertices, then return false.
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	// Step 3: Create a reversed graph
	Graph gr = getTranspose();

	// Step 4: Mark all the vertices as not visited (For second DFS)
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Step 5: Do DFS for reversed graph starting from first vertex. Starting Vertex must be same starting point of first DFS
	gr.DFSUtil(0, visited);

	// If all vertices are not visited in second DFS, then return false
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	return true;
}

int main()
{
	// Create graphs given in the above diagrams
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 0);
	g1.addEdge(2, 4);
	g1.addEdge(4, 2);
	g1.isSC()? cout << "Yes\n" : cout << "No\n";

	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.isSC()? cout << "Yes\n" : cout << "No\n";

	return 0;
}


/*

Graph Class Definition:

The Graph class represents a directed graph using an adjacency list.
It has a constructor to initialize the number of vertices (V) and an array of adjacency lists adj to store the graph's edges.
The destructor releases the memory allocated for the adjacency lists.
DFSUtil Function: This function performs a Depth-First Search (DFS) traversal starting from a given vertex. It marks visited vertices and explores their adjacent vertices.

getTranspose Function: This function returns the transpose (reversed) graph of the current graph. It reverses the direction of all edges.

addEdge Function: This function adds an edge from vertex v to vertex w in the graph.

isSC Function: This is the main function that checks if the graph is strongly connected.

It first performs a DFS traversal starting from vertex 0 and marks visited vertices.
If any vertex is not visited during this DFS traversal, the graph is not strongly connected, and the function returns false.
It then creates the transpose of the graph using the getTranspose function.
It performs another DFS traversal on the reversed graph, again starting from vertex 0.
If any vertex is not visited during this DFS traversal, the graph is not strongly connected, and the function returns false.
If all vertices are visited in both DFS traversals, the graph is strongly connected, and the function returns true.
Main Function:

In the main function, two graphs g1 and g2 are created and edges are added to them using the addEdge function.
The isSC function is then called on each graph to determine if they are strongly connected or not. The results are printed accordingly.

*/

