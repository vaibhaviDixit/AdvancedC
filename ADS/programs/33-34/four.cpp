/*
Write a function to find the node with minimum value in a Binary Search Tree.

Input:
  4
 / \
 2  6
/ \
1 3

Output: Minimum value in BST is 1

*/


#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Give a binary search tree and a number, inserts a new node with the given number in
the correct place in the tree. Returns the new root pointer which the caller should then use (the standard trick to avoid using reference
parameters).

*/

struct node* insert(struct node* node, int data)
{
	/* 1. If the tree is empty, return a new,
		single node */
	if (node == NULL)
		return (newNode(data));
	else {
		/* 2. Otherwise, recur down the tree */
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		/* return the (unchanged) node pointer */
		return node;
	}
}

/* Given a non-empty binary search tree, inorder traversal for the tree is stored in
the vector sortedInorder. Inorder is LEFT,ROOT,RIGHT*/

void inorder(struct node* node, vector<int>& sortedInorder)
{
	if (node == NULL)
		return;
	/* first recur on left child */
	inorder(node->left, sortedInorder);

	/* then insert the data of node */
	sortedInorder.push_back(node->data);

	/* now recur on right child */
	inorder(node->right, sortedInorder);
}

int main()
{
	struct node* root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 4);
	insert(root, 5);

	vector<int> sortedInorder;
	inorder(root,sortedInorder); // calling the recursive function values of all nodes will appear in sorted order in the vector sortedInorder Function call
	printf("\n Minimum value in BST is %d",sortedInorder[0]);
	getchar();
	return 0;
}
/*
The struct node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The newNode function allocates and initializes a new node with the given data. It returns a pointer to the new node.

The insert function inserts a new node with the given data into the BST. It follows the standard BST insertion logic: if the data is less than or equal to the current node's data, it goes to the left subtree; otherwise, it goes to the right subtree.

The inorder function performs an in-order traversal of the BST and stores the values of the nodes in the sortedInorder vector. In-order traversal visits nodes in the order of left, root, and right.

*/



