/*
Given an ancestor matrix mat[n][n] where Ancestor matrix is defined as below.

mat[i][j] = 1 if i is ancestor of j
mat[i][j] = 0, otherwise
Construct a Binary Tree from a given ancestor matrix where all its values of nodes are from 0 to n-1.

It may be assumed that the input provided in the program is valid and the tree can be constructed out of it.
Many Binary trees can be constructed from one input. The program will construct any one of them.

Input:  { 0, 0, 0, 0, 0, 0 }
		{ 1, 0, 0, 0, 1, 0 }
		{ 0, 0, 0, 1, 0, 0 }
		{ 0, 0, 0, 0, 0, 0 }
		{ 0, 0, 0, 0, 0, 0 }
		{ 1, 1, 1, 1, 1, 0 }

Output: Inorder traversal of tree is: 0 1 4 5 3 2

*/


#include <bits/stdc++.h>
using namespace std;

# define N 6

/* A binary tree node */
struct Node
{
	int data;
	Node *left, *right;
};

/* Helper function to create a new node */
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Constructs tree from ancestor matrix
Node* ancestorTree(int mat[][N])
{
	// Binary array to determine whether
	// parent is set for node i or not
	int parent[N] = {0};

	// Root will store the root of the constructed tree
	Node* root = NULL;

	// Create a multimap, sum is used as key and row numbers are used as values
	multimap<int, int> mm;

	for (int i = 0; i < N; i++)
	{
		int sum = 0; // Initialize sum of this row
		for (int j = 0; j < N; j++)
			sum += mat[i][j];

		// insert(sum, i) pairs into the multimap
		mm.insert(pair<int, int>(sum, i));
	}

	// node[i] will store node for i in constructed tree
	Node* node[N];

	// Traverse all entries of multimap. Note that values
	// are accessed in increasing order of sum
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
	// create a new node for every value
	node[it->second] = newNode(it->second);

	// To store last processed node. This node will be root after loop terminates
	root = node[it->second];

	// if non-leaf node
	if (it->first != 0)
	{
		// traverse row 'it->second' in the matrix
		for (int i = 0; i < N; i++)
		{
		// if parent is not set and ancestor exits
		if (!parent[i] && mat[it->second][i])
		{
			// check for unoccupied left/right node and set parent of node i
			if (!node[it->second]->left)
			node[it->second]->left = node[i];
			else
			node[it->second]->right = node[i];

			parent[i] = 1;
		}
		}
	}
	}
	return root;
}

/* Given a binary tree, print its nodes in inorder */
void printInorder(Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

int main()
{
	int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0 }
	};

	Node* root = ancestorTree(mat);

	cout << "Inorder traversal of tree is \n";

	// Function call
	printInorder(root);

	return 0;
}

/*
Node Structure: The program defines a Node structure representing nodes of a binary tree. Each node has a data value, and pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

ancestorTree Function: This function constructs a binary tree from the given ancestor matrix. It takes the ancestor matrix as input and returns the root of the constructed binary tree.

The function initializes an array parent to keep track of whether a parent is set for a node.
It creates a multimap mm to store the sum of each row in the ancestor matrix along with the corresponding row numbers.
The multimap is sorted based on the sum of ancestors.
The function creates nodes for each row in the multimap, assigning the first node as the root.
For non-leaf nodes, it traverses the row and sets the parent of the node if there is a valid ancestor. It also ensures that unoccupied left/right children are assigned accordingly.
printInorder Function: This utility function performs an inorder traversal of the binary tree and prints the values of the nodes.

main Function: The main function initializes the ancestor matrix mat and calls the ancestorTree function to construct the binary tree.

It then prints the inorder traversal of the constructed binary tree.

*/


