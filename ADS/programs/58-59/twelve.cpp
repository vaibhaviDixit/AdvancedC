/*
Given an undirected Graph, The task is to find the Bridges in this Graph.

An edge in an undirected connected graph is a bridge if removing it disconnects the graph. For a disconnected undirected graph, the definition is similar,
a bridge is an edge removal that increases the number of disconnected components.

Input: [ (1, 0),(0, 2),(2, 1),(0, 3),(3, 4)]
Output:
3 4
0 3

Input: [(0, 1),(1, 2),(2, 3)]
Output:
2 3
1 2
0 1

*/

// A C++ program to find bridges in a given undirected graph
#include<bits/stdc++.h>
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
								vector<int>& low, int parent);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	void bridge(); // prints all bridges
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
								vector<int>& low, int parent)
{
	// A static variable is used for simplicity, we can
	// avoid use of static variable by passing a pointer.
	static int time = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices adjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u

		// 1. If v is parent
		if(v==parent)
			continue;

		//2. If v is visited
		if(visited[v]){
		low[u] = min(low[u], disc[v]);
		}

		//3. If v is not visited
		else{
		parent = u;
		bridgeUtil(v, visited, disc, low, parent);

		// update the low of u as it's quite possible
		// a connection exists from v's descendants to u
		low[u] = min(low[u], low[v]);

		// if the lowest possible time to reach vertex v
		// is greater than discovery time of u it means
		// that v can be only be reached by vertex above v
		// so if that edge is removed v can't be reached so it's a bridge
		if (low[v] > disc[u])
			cout << u <<" " << v << endl;

		}
	}
}

// DFS based function to find all bridges. It uses recursive
// function bridgeUtil()
void Graph::bridge()
{
	// Mark all the vertices as not visited disc and low as -1
	vector<bool> visited (V,false);
	vector<int> disc (V,-1);
	vector<int> low (V,-1);

	// Initially there is no parent so let it be -1
	int parent = -1;

	// Call the recursive helper function to find Bridges
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent);
}

// Driver program to test above function
int main()
{
	// Create graphs given in above diagrams
	cout << "\nBridges in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.bridge();

	cout << "\nBridges in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.bridge();

	cout << "\nBridges in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.bridge();

	return 0;
}

/*
The program defines a Graph class to represent an undirected graph using adjacency lists. It includes a constructor, a method to add edges, and a method to find and print the bridges.

The addEdge function adds edges to the adjacency lists.

The bridgeUtil function is a recursive utility function that performs depth-first search (DFS) to find bridges in the graph.

It uses the disc (discovery time) and low arrays to keep track of discovery times and low values for each vertex.
The time variable is used to assign discovery times.
The function iterates through the adjacent vertices of the current vertex and checks for three cases:
If the adjacent vertex is the parent, skip it.
If the adjacent vertex is visited, update the low value of the current vertex.
If the adjacent vertex is not visited, call the bridgeUtil function recursively and update the low value.
The bridge function initializes the necessary arrays and iterates through all vertices to find bridges using the bridgeUtil function.

In the main function:

Several graphs are created and tested using the bridge function to find and print the bridges in the graph.
Different cases of graphs are tested, and the program prints the bridges in each graph.
The program runs test cases on different graphs and outputs the bridges found in each graph.

*/



