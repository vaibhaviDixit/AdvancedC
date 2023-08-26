/*
Determine whether a universal sink exists in a directed graph. A universal sink is a vertex which has no edge emanating from it, and all other vertices have an edge towards the sink.

Input :
v1 -> v2 (implies vertex 1 is connected to vertex 2)
v3 -> v2
v4 -> v2
v5 -> v2
v6 -> v2
Output :
Sink found at vertex 2

Input :
v1 -> v6
v2 -> v3
v2 -> v4
v4 -> v3
v5 -> v3
Output :
No Sink

*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class Graph {
	int vertices;
	int adjacency_matrix[MAX][MAX];

public:
	Graph(int vertices)
	{
		this->vertices = vertices;
		memset(adjacency_matrix, 0,
			sizeof(adjacency_matrix));
	}
	void insert(int source, int destination)
	{
		adjacency_matrix[destination - 1] = 1;
	}

	bool is_sink(int i)
	{
		for (int j = 0; j < vertices; j++) {
			if (adjacency_matrix[i][j] == 1)
				return false;
			if (adjacency_matrix[j][i] == 0 && j != i)
				return false;
		}
		return true;
	}

	int eliminate()
	{
		int i = 0, j = 0;
		while (i < vertices && j < vertices) {
			if (adjacency_matrix[i][j] == 1)
				i = i + 1;
			else
				j = j + 1;
		}

		if (i > vertices)
			return -1;
		else if (!is_sink(i))
			return -1;
		else
			return i;
	}
};

int main()
{
	int number_of_vertices = 6, number_of_edges = 5;
	Graph g(number_of_vertices);
	g.insert(1, 6);
	g.insert(2, 3);
	g.insert(2, 4);
	g.insert(4, 3);
	g.insert(5, 3);

	int vertex = g.eliminate();

	if (vertex >= 0)
		cout << "Sink found at vertex " << (vertex + 1)
			<< endl;
	else
		cout << "No Sink" << endl;

	return 0;
}

/*

The constant MAX is defined to specify the maximum number of vertices in the graph.

The Graph class is defined, which contains:

vertices: The number of vertices in the graph.
adjacency_matrix: A 2D array to store the adjacency matrix of the graph.
The constructor of the Graph class initializes the number of vertices and sets the adjacency matrix to all zeros using memset.

The insert method takes two parameters: source and destination, and it modifies the adjacency matrix to indicate a directed edge from the source to the destination.

The is_sink method checks whether a given vertex i is a sink node by iterating through the corresponding row and column in the adjacency matrix. It returns true if the vertex is a sink node and false otherwise.

The eliminate method attempts to find a sink node in the graph by iteratively traversing the adjacency matrix from top-left to bottom-right. If a sink node is found, its index is returned; otherwise, -1 is returned to indicate that no sink node was found.

The main function:

Creates a Graph object g with the specified number of vertices.
Inserts directed edges using the insert method.
Calls the eliminate method to find a sink node in the graph.
If a sink node is found (vertex index is not -1), it prints the vertex index.
If no sink node is found, it prints "No Sink".

*/




