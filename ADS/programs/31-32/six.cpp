/*
We are given a tree of size n as array parent[0..n-1] where every index i in the parent[] represents a node and the value at i represents the
immediate parent of that node. For root node value will be -1. Find the height of the generic tree given the parent links.

Input : parent[] = {-1, 0, 0, 0, 3, 1, 1, 2}
Output : 2

*/

#include <bits/stdc++.h>
using namespace std;

// Recur For Ancestors of node and store height of node at last
int fillHeight(int p[], int node, int visited[],
								int height[])
{
	// If root node
	if (p[node] == -1) {

		// mark root node as visited
		visited[node] = 1;
		return 0;
	}

	// If node is already visited
	if (visited[node])
		return height[node];

	// Visit node and calculate its height
	visited[node] = 1;

	// recur for the parent node
	height[node] = 1 + fillHeight(p, p[node],
							visited, height);

	// return calculated height for node
	return height[node];
}

int findHeight(int parent[], int n)
{
	// To store max height
	int ma = 0;

	// To check whether or not node is visited before
	int visited[n];

	// For Storing Height of node
	int height[n];

	memset(visited, 0, sizeof(visited));
	memset(height, 0, sizeof(height));

	for (int i = 0; i < n; i++) {

		// If not visited before
		if (!visited[i])
			height[i] = fillHeight(parent, i,
							visited, height);

		// store maximum height so far
		ma = max(ma, height[i]);
	}

	return ma;
}

int main()
{
	int parent[] = { -1, 0, 0, 0, 3, 1, 1, 2 };
	int n = sizeof(parent) / sizeof(parent[0]);

	cout << "Height of N-ary Tree = "<< findHeight(parent, n);
	return 0;
}

/*
fillHeight Function: This function is used to fill in the heights of the nodes in the tree. It takes the following parameters:

p[]: An array representing the parent of each node.
node: The current node for which the height is being calculated.
visited[]: An array to mark whether a node has been visited or not.
height[]: An array to store the height of each node.
The function first checks if the current node is the root (parent is -1). If so, it sets the height of the root to 0 and marks it as visited.
If the node is already visited, it returns the height calculated previously. If the node is not visited, it recursively calculates the height
of its parent and stores it in the height array. The height of the current node is then updated as one more than the height of its parent, and
the function returns this calculated height.

findHeight Function: This function takes two parameters:

parent[]: An array representing the parent of each node.
n: The number of nodes in the tree.
It initializes an integer variable ma to store the maximum height found. It also initializes arrays visited and height to keep track of visited
nodes and their heights, respectively.

The function then iterates through each node in the tree using a loop. If the current node has not been visited, it calculates its height using
the fillHeight function. After calculating the height of each node, it updates the ma variable with the maximum height found so far.

*/

