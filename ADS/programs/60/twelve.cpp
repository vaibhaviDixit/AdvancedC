/*
Given a Directed Acyclic Graph of n nodes (numbered from 1 to n) and m edges. The task is to find the number of sink nodes. A sink node is a node such that no edge emerges out of it.

Input : n = 4, m = 2
        Edges[] = {{2, 3}, {4, 3}}
Output : 2

Input : n = 4, m = 2
        Edges[] = {{3, 2}, {3, 4}}
Output : 3

*/

// C++ program to count number if sink nodes
#include<bits/stdc++.h>
using namespace std;

// Return the number of Sink NOdes.
int countSink(int n, int m, int edgeFrom[],
						int edgeTo[])
{
	// Array for marking the non-sink node.
	int mark[n];
	memset(mark, 0, sizeof mark);

	// Marking the non-sink node.
	for (int i = 0; i < m; i++)
		mark[edgeFrom[i]] = 1;

	// Counting the sink nodes.
	int count = 0;
	for (int i = 1; i <= n ; i++)
		if (!mark[i])
			count++;

	return count;
}

int main()
{
	int n = 4, m = 2;
	int edgeFrom[] = { 2, 4 };
	int edgeTo[] = { 3, 3 };

	cout << countSink(n, m, edgeFrom, edgeTo) << endl;

	return 0;
}

/*

The countSink function takes four parameters:

n: The number of nodes in the graph.
m: The number of edges in the graph.
edgeFrom[]: An array containing the source nodes of the edges.
edgeTo[]: An array containing the destination nodes of the edges.
Inside the countSink function:

An array mark is created to mark nodes that are not sink nodes. It's initialized with zeros.
The loop iterates through the array of destination nodes (edgeFrom) and marks the corresponding source nodes as non-sink nodes.
Another loop counts the number of sink nodes by iterating through each node from 1 to n and incrementing the count if the node is not marked as a non-sink node.
The main function:

Initializes the number of nodes n, the number of edges m, and the arrays edgeFrom and edgeTo representing the edges.
Calls the countSink function with the given parameters and prints the result, which is the number of sink nodes in the graph.

*/

