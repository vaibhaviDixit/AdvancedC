/*
Given the preorder traversal of a binary search tree, construct the BST.

Input: Preorder= {10, 5, 1, 7, 40, 50}
Output: Inorder: 1 5 7 10 40 50

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

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct Full from pre[].
// preIndex is used to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int low,
						int high, int size)
{
	// Base case
	if (*preIndex >= size || low > high)
		return NULL;

	// The first node in preorder traversal is root. So take the node at preIndex from pre[] and make it root, and increment preIndex
	node* root = newNode(pre[*preIndex]);
	*preIndex = *preIndex + 1;

	// If the current subarray has only one element, no need
	// to recur
	if (low == high)
		return root;

	// Search for the first element greater than root
	int i;
	for (i = low; i <= high; ++i)
		if (pre[i] > root->data)
			break;

	// Use the index of element found in preorder to divide preorder array in two parts. Left subtree and right subtree
	root->left = constructTreeUtil(pre, preIndex, *preIndex,
								i - 1, size);
	root->right
		= constructTreeUtil(pre, preIndex, i, high, size);

	return root;
}

// The main function to construct BST from given preorder traversal. This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, 0, size - 1,
							size);
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	// Function call
	node* root = constructTree(pre, size);

	printInorder(root);

	return 0;
}

/*
The class node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The newNode function is a utility that creates and initializes a new node with the given data. It returns a pointer to the new node.

The constructTreeUtil function is a recursive utility function that constructs the BST from the given preorder traversal array (pre). It uses the following approach:

The first element of the preorder array is always the root of the current subtree.
The preIndex parameter is used to keep track of the current index in the pre array.
It creates a new node with the root's data and increments preIndex.
It searches for the index (i) of the first element greater than the root's data within the range (low to high) of the current subtree.
It recursively constructs the left subtree using the elements before index i and the right subtree using the elements after index i.
It returns the constructed root node of the current subtree.
The constructTree function is the main function responsible for constructing the BST from the preorder traversal. It initializes the preIndex to 0 and then calls the constructTreeUtil function with the appropriate parameters.

The printInorder function performs an inorder traversal of the BST and prints the values of the nodes in ascending order.

*/

