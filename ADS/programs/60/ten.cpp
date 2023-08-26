/*
 C++ program to find out whether a given graph is Bipartite or not.It should work for disconnected graph also.

Input: { { 0, 1, 0, 1 },{ 1, 0, 1, 0 },{ 0, 1, 0, 1 },{ 1, 0, 1, 0 } }
Output: Yes

*/

#include <bits/stdc++.h>

using namespace std;

const int V = 4;

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex numbers a
	// nd enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

	// Run while there are vertices in queue (Similar to
	// BFS)
	while (!q.empty()) {
		// Dequeue a vertex from queue ( Refer
		// http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1)
			return false;

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v) {
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1) {
				// Assign alternate color to this
				// adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can
	// be colored with alternate color
	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(int G[][V])
{
	// Create a color array to store colors assigned to all
	// vertices. Vertex/ number is used as index in this
	// array. The value '-1' of colorArr[i] is used to
	// indicate that no color is assigned to vertex 'i'.
	// The value 1 is used to indicate first color is
	// assigned and value 0 indicates second color is
	// assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// This code is to handle disconnected graph
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
				return false;

	return true;
}

int main()
{
	int G[][V] = { { 0, 1, 0, 1 },
				{ 1, 0, 1, 0 },
				{ 0, 1, 0, 1 },
				{ 1, 0, 1, 0 } };

	isBipartite(G) ? cout << "Yes" : cout << "No";
	return 0;
}

/*
The constant V is defined to specify the number of vertices in the graph.

The isBipartiteUtil function is a utility function that performs a breadth-first search (BFS) traversal of the graph to determine if it's bipartite starting from a given source vertex src. It returns true if the graph is bipartite and false otherwise.

Inside the isBipartiteUtil function:

An array colorArr is used to assign colors to vertices. -1 indicates no color, 0 indicates one color, and 1 indicates the other color.
The BFS traversal is implemented using a queue. The traversal continues until the queue is empty.
The colorArr for the source vertex is set to 1.
For each adjacent vertex, the color is assigned alternately (1 - colorArr[u]) and the vertex is added to the queue if it's not colored yet.
If an adjacent vertex has the same color as the current vertex, the graph is not bipartite, and false is returned.
The isBipartite function checks if the graph is bipartite. If the graph is disconnected, it calls the isBipartiteUtil function on each connected component.

The main function:

Defines a sample graph using an adjacency matrix G.
Calls the isBipartite function and prints "Yes" if the graph is bipartite and "No" otherwise.

*/



