/*
Given n nodes of a forest (collection of trees), find the number of trees in the forest.

Input :  edges[] = {0, 1}, {0, 2}, {3, 4}
Output : 2

*/

// CPP program to count number of trees in a forest.
#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to do DFS of graph recursively from a given vertex u.
void DFSUtil(int u, vector<int> adj[],
					vector<bool> &visited)
{
	visited[u] = true;
	for (int i=0; i<adj[u].size(); i++)
		if (visited[adj[u][i]] == false)
			DFSUtil(adj[u][i], adj, visited);
}

// Returns count of tree is the forest given as adjacency list.
int countTrees(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);
	int res = 0;
	for (int u=0; u<V; u++)
	{
		if (visited[u] == false)
		{
			DFSUtil(u, adj, visited);
			res++;
		}
	}
	return res;
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 3, 4);
	cout << countTrees(adj, V);
	return 0;
}

/*

addEdge Function: This function takes an adjacency list adj[], and two vertices u and v as arguments. It adds an undirected edge between vertices u and v by pushing v into the adjacency list of u, and vice versa.

DFSUtil Function: This is a recursive utility function for performing DFS traversal on the graph starting from a given vertex u. It marks the current vertex as visited and recursively explores its neighbors that haven't been visited yet.

countTrees Function: This function takes an adjacency list adj[] and the number of vertices V as arguments.
It initializes a boolean vector visited[] of size V to keep track of visited vertices.
It then iterates through all vertices and starts a DFS traversal from each unvisited vertex.
The number of times the DFS traversal is initiated corresponds to the number of trees in the forest. The function returns this count of trees.

*/


