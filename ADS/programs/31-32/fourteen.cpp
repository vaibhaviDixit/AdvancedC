/*
Given a binary tree, find its maximum depth (height).

Input:
      1
     / \
    2   3
   / \
  4   5

Output: Height of tree is 3

*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* Compute the "maxDepth" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int maxDepth(node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main()
{
	node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height of tree is " << maxDepth(root);
	return 0;
}

/*
This program aims to find the maximum depth of a binary tree. The depth of a binary tree is defined as the length of the longest path from the
root node to a leaf node. We perform a depth-first traversal of the tree and keep track of the current depth. The depth is incremented as we
traverse down the tree. We use recursion to visit each node and find the maximum depth among all the paths. This is a common problem in binary
tree traversal.

*/
