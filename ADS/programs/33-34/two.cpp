/*
Write a CPP  program to check if a Binary Tree is BST or not

Input:
    4
   / \
  2   5
 / \
1   3

Output: Is BST

*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int maxValue(struct node* node)
{
	if (node == NULL) {
		return INT16_MIN;
	}
	int value = node->data;
	int leftMax = maxValue(node->left);
	int rightMax = maxValue(node->right);

	return max(value, max(leftMax, rightMax));
}

int minValue(struct node* node)
{
	if (node == NULL) {
		return INT16_MAX;
	}
	int value = node->data;
	int leftMax = minValue(node->left);
	int rightMax = minValue(node->right);

	return min(value, min(leftMax, rightMax));
}

/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node)
{
	if (node == NULL)
		return 1;

	/* false if the max of the left is > than us */
	if (node->left != NULL
		&& maxValue(node->left) > node->data)
		return 0;

	/* false if the min of the right is <= than us */
	if (node->right != NULL
		&& minValue(node->right) < node->data)
		return 0;

	/* false if, recursively, the left or right is not a BST
	*/
	if (!isBST(node->left) || !isBST(node->right))
		return 0;

	/* passing all that, it's a BST */
	return 1;
}

int main()
{
	struct node* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	// root->right->left = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);

	// Function call
	if (isBST(root))
		printf("Is BST");
	else
		printf("Not a BST");

	return 0;
}

/*
The struct node defines a structure to represent nodes in a binary tree. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The newNode function is a helper utility that allocates and initializes a new node with the provided data. It returns a pointer to the new node.

The maxValue function takes a node pointer as an argument and recursively finds the maximum value in the subtree rooted at that node. If the node is NULL, it returns the smallest possible value (INT16_MIN) to indicate that no valid value has been found.

The minValue function takes a node pointer as an argument and recursively finds the minimum value in the subtree rooted at that node. If the node is NULL, it returns the largest possible value (INT16_MAX) to indicate that no valid value has been found.

The isBST function is the main function responsible for determining whether the given binary tree is a Binary Search Tree. It uses recursive logic to traverse the tree and validate the conditions of a BST:

It returns true (1) for an empty tree (a NULL node).
It checks if the max value in the left subtree is less than the current node's value and the min value in the right subtree is greater than the current node's value. If not, it returns false (0).
It recursively checks if both the left and right subtrees are valid BSTs.
If all conditions pass, the function returns true (1), indicating that the tree is a BST

*/
