/*
 A C++ program to check if a given graph is Eulerian or not

 Input: [ (1, 0),(0, 2),(2, 1)(0, 3),(3, 4)]
 Output: graph has a Euler path

 Input: [(0, 1),(1, 2),(2, 0)]
 Output: graph has a Euler cycle

*/


#include<iostream>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	Graph(int V) {this->V = V; adj = new list<int>[V]; }
	~Graph() { delete [] adj; } // To avoid memory leak

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Method to check if this graph is Eulerian or not
	int isEulerian();

	// Method to check if all non-zero degree vertices are connected
	bool isConnected();

	// Function to do DFS starting from v. Used in isConnected();
	void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

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

// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
	// Mark all the vertices as not visited
	bool visited[V];
	int i;
	for (i = 0; i < V; i++)
		visited[i] = false;

	// Find a vertex with non-zero degree
	for (i = 0; i < V; i++)
		if (adj[i].size() != 0)
			break;

	// If there are no edges in the graph, return true
	if (i == V)
		return true;

	// Start DFS traversal from a vertex with non-zero degree
	DFSUtil(i, visited);

	// Check if all non-zero degree vertices are visited
	for (i = 0; i < V; i++)
	if (visited[i] == false && adj[i].size() > 0)
			return false;

	return true;
}

/* The function returns one of the following values
0 --> If graph is not Eulerian
1 --> If graph has an Euler path (Semi-Eulerian)
2 --> If graph has an Euler Circuit (Eulerian) */
int Graph::isEulerian()
{
	// Check if all non-zero degree vertices are connected
	if (isConnected() == false)
		return 0;

	// Count vertices with odd degree
	int odd = 0;
	for (int i = 0; i < V; i++)
		if (adj[i].size() & 1)
			odd++;

	// If count is more than 2, then graph is not Eulerian
	if (odd > 2)
		return 0;

	// If odd count is 2, then semi-eulerian.
	// If odd count is 0, then eulerian
	// Note that odd count can never be 1 for undirected graph
	return (odd)? 1 : 2;
}

// Function to run test cases
void test(Graph &g)
{
	int res = g.isEulerian();
	if (res == 0)
		cout << "graph is not Eulerian\n";
	else if (res == 1)
		cout << "graph has a Euler path\n";
	else
		cout << "graph has a Euler cycle\n";
}

int main()
{
	// Let us create and test graphs shown in above figures
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	test(g1);

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(4, 0);
	test(g2);

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(1, 3);
	test(g3);

	// Let us create a graph with 3 vertices
	// connected in the form of cycle
	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(1, 2);
	g4.addEdge(2, 0);
	test(g4);

	// Let us create a graph with all vertices
	// with zero degree
	Graph g5(3);
	test(g5);

	return 0;
}

/*
The program defines a Graph class to represent an undirected graph using adjacency lists.

It has a constructor to initialize the number of vertices and allocate memory for adjacency lists.
The destructor deallocates the memory to avoid memory leaks.
The class includes methods to add edges, check connectivity, and find if the graph is Eulerian.
The addEdge function adds edges to the adjacency lists.

The DFSUtil function is a utility function to perform depth-first search starting from a given vertex.

The isConnected function checks if all non-zero degree vertices are connected by performing a DFS traversal.

The isEulerian function determines whether the graph is Eulerian and returns:

0 if the graph is not Eulerian.
1 if the graph has an Euler path (Semi-Eulerian).
2 if the graph has an Euler circuit (Eulerian).
The test function takes a graph and calls the isEulerian function to determine the Eulerian nature of the graph and prints the appropriate message.

In the main function:

Several graphs are created and tested using the test function.
Different cases of graphs are tested, including those with Euler paths, Euler circuits, cycles, and disconnected vertices.

*/



