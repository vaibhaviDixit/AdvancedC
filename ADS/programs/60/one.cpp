/*
You are given an undirected graph consisting of N nodes labeled from 0 to N – 1. The graph is represented by a 2D array arr[][],
where arr[i] represents all the nodes that are connected to the ith node.
Your task is to determine whether it's possible to visit all the nodes in the graph starting from a given node X.

Note: You can visit a node and then move to any of its connected nodes.

Input: { { 1, 2 }, { 0, 3, 2 }, { 0, 1 }, { 1 } } , N=4, X=0
Output: YES

*/


#include <bits/stdc++.h>
using namespace std;

// Function to find if
// all nodes can be visited from X
bool canVisitAllNodes(vector<vector<int> >& arr,
					int X, int n)
{
	queue<int> q;
	vector<int> visited(n, false);
	q.push(X);
	visited[X] = true;
	int count = 0;

	// Loop to implement BFS
	while (q.size() > 0) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			auto curr = q.front();
			q.pop();
			count++;

			for (auto j : arr[curr]) {
				if (visited[j] == false) {
					q.push(j);
					visited[j] = true;
				}
			}
		}
	}

	// Check if all nodes are visited
	if (count == n)
		return true;
	return false;
}

int main()
{
	vector<vector<int> > arr
		= { { 1, 2 }, { 0, 3, 2 }, { 0, 1 }, { 1 } };
	int N = 4, X = 0;

	// Function Call
	if (canVisitAllNodes(arr, X, N)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

/*
This C++ program addresses the problem of determining whether all nodes in an undirected graph can be visited starting from a given node X. The graph is represented using a 2D vector arr, where arr[i] contains the nodes connected to the ith node. The program uses Breadth-First Search (BFS) to traverse the graph and keep track of visited nodes.

Here's a breakdown of the program:

The canVisitAllNodes function takes the adjacency information (arr), the starting node X, and the total number of nodes n as input. It returns a boolean indicating whether all nodes can be visited from node X.

Inside the canVisitAllNodes function, a queue (q) and a vector (visited) of size n are initialized. The queue holds nodes to be processed in BFS, and the visited vector keeps track of whether a node has been visited.

The BFS traversal begins by pushing the starting node X into the queue and marking it as visited. A variable count is initialized to track the number of nodes visited.

The main loop continues as long as the queue is not empty. Within each iteration, the nodes at the current level are processed. For each node, its adjacent nodes are explored, and if they haven't been visited yet, they are pushed into the queue and marked as visited.

After each level of nodes is processed, the count variable is incremented by the number of nodes processed in that level.

Finally, after BFS traversal, the program checks if the total count is equal to the total number of nodes n. If all nodes are visited, the function returns true; otherwise, it returns false.

In the main function, a sample graph represented by the arr vector is provided. The canVisitAllNodes function is called with the graph information and the starting node X. If all nodes can be visited from node X, it prints "YES"; otherwise, it prints "NO".

The program uses BFS to explore the graph starting from node X. If the BFS traversal visits all nodes, it indicates that all nodes can be visited from node X, and the program outputs "YES". Otherwise, it outputs "NO".

*/
