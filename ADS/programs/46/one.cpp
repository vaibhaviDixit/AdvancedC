/*
Given a tree with N nodes and N-1 edges, find out the maximum height of the tree when any node in the tree is considered as the root of the tree.

Input:
        1
    /   \   \
    2    3    4
   / \    \   /  \
   5  6    7  8   9
          / \
          10 11

Output:
The maximum height when node 1 is considered as root is 3
The maximum height when node 2 is considered as root is 4
The maximum height when node 3 is considered as root is 3
The maximum height when node 4 is considered as root is 4
The maximum height when node 5 is considered as root is 5
The maximum height when node 6 is considered as root is 5
The maximum height when node 7 is considered as root is 4
The maximum height when node 8 is considered as root is 5
The maximum height when node 9 is considered as root is 5
The maximum height when node 10 is considered as root is 5
The maximum height when node 11 is considered as root is 5

*/

// C++ code to find the maximum path length considering any node as root
#include <bits/stdc++.h>
using namespace std;

vector<int> in,out;

// function to pre-calculate the array in[] which stores the maximum height when travelled via branches
void dfs1(vector<int> v[], int u, int parent)
{
	// initially every node has 0 height
	in[u] = 0;

	// traverse in the subtree of u
	for (int child : v[u]) {

		// if child is same as parent
		if (child == parent)
			continue;

		// dfs called
		dfs1(v, child, u);

		// recursively calculate the max height
		in[u] = max(in[u], 1 + in[child]);
	}
}

// function to pre-calculate the array out[] which stores the maximum height when traveled via parent
void dfs2(vector<int> v[], int u, int parent)
{
	// stores the longest and second longest branches
	int mx1 = -1, mx2 = -1;

	// traverse in the subtrees of u
	for (int child : v[u]) {
		if (child == parent)
			continue;

		// compare and store the longest and second longest
		if (in[child] >= mx1) {
			mx2 = mx1;
			mx1 = in[child];
		}

		else if (in[child] > mx2)
			mx2 = in[child];
	}

	// traverse in the subtree of u
	for (int child : v[u]) {
		if (child == parent)
			continue;

		int longest = mx1;

		// if longest branch has the node, then consider the second longest branch
		if (mx1 == in[child])
			longest = mx2;

		// recursively calculate out[i]
		out[child] = 1 + max(out[u], 1 + longest);

		// dfs function call
		dfs2(v, child, u);
	}
}

// function to print all the maximum heights from every node
void printHeights(vector<int> v[], int n)
{
	// traversal to calculate in[] array
	dfs1(v, 1, 0);

	// traversal to calculate out[] array
	dfs2(v, 1, 0);

	// print all maximum heights
	for (int i = 1; i <= n; i++)
		cout << "The maximum height when node "
			<< i << " is considered as root"
			<< " is " << max(in[i], out[i])
			<< "\n";
}

int main()
{
	int n = 11;
	vector<int> v[n + 1];

	v[1].push_back(2), v[2].push_back(1);
	v[1].push_back(3), v[3].push_back(1);
	v[1].push_back(4), v[4].push_back(1);
	v[2].push_back(5), v[5].push_back(2);
	v[2].push_back(6), v[6].push_back(2);
	v[3].push_back(7), v[7].push_back(3);
	v[7].push_back(10), v[10].push_back(7);
	v[7].push_back(11), v[11].push_back(7);
	v[4].push_back(8), v[8].push_back(4);
	v[4].push_back(9), v[9].push_back(4);

	// initialise in and out vectors
	in.resize(n+1,0);
	out.resize(n+1,0);
	// function to print the maximum height from every node
	printHeights(v, n);

	return 0;
}

/*
Two vectors in and out are declared to store the maximum heights when traveled via branches (in) and when traveled via the parent (out). These vectors are used to keep track of the maximum heights for each node.

The dfs1 function calculates the in array, which stores the maximum height when traveling via branches. It initializes in[u] to 0 for every node initially. It then recursively calculates the maximum height by considering the heights of its child nodes. The in[u] value is updated to the maximum of its current value and 1 + in[child], considering each child node.

The dfs2 function calculates the out array, which stores the maximum height when traveling via the parent. It also keeps track of the two longest branches (mx1 and mx2). It then iterates through the child nodes, comparing their heights and updating mx1 and mx2 accordingly. Afterward, it calculates the out[child] value for each child node, considering the parent's height and the longest branch's height. This is done recursively for all child nodes.

The printHeights function is responsible for printing the maximum heights for every node. It first calls dfs1 to calculate the in array and then dfs2 to calculate the out array. Finally, it prints the maximum height for each node, which is the maximum between in[i] and out[i].

In the main function, a sample tree with 11 nodes is created. The tree structure is initialized using vector v, representing the connections between nodes.

The in and out vectors are initialized to store the maximum heights for each node.

The printHeights function is called to calculate and print the maximum heights for each node when considered as the root.

*/
