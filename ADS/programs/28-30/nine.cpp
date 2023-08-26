/*
 Write a Recursive CPP program for level order traversal of Binary Tree

 Input:
             1
			/ \
		    2  3
           / \
          4  5

 Output: Level Order traversal of binary tree is 1 2 3 4 5

*/


#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child and a pointer to right child
class node {
public:
	int data;
	node *left, *right;
};

// Function prototypes
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

// Function to print level order traversal a tree
void printLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

// Print nodes at a current level
void printCurrentLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(node* node)
{
	if (node == NULL)
		return 0;
	else {

		// Compute the height of each subtree
		int lheight = height(node->left);
		int rheight = height(node->right);

		// Use the larger one
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}

// Helper function that allocates
// a new node with the given data and
// NULL left and right pointers.
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

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);

	return 0;
}

/*
node Class: The program starts by defining a node class that represents the nodes of the binary tree. Each node has a data value, pointers to its left and right children.

printLevelOrder Function: This function prints the level order traversal of the binary tree. It takes the root node as an argument. The function works as follows:

It calculates the height of the tree using the height function.
It iterates through each level from 1 to the height of the tree.
For each level, it calls the printCurrentLevel function to print the nodes at that level.
printCurrentLevel Function: This function prints the nodes at a particular level of the binary tree. It takes the root node and the current level as arguments. The function works as follows:

If the root is NULL, it returns.
If the current level is 1, it prints the data of the current root node.
If the current level is greater than 1, it recursively calls itself on the left and right subtrees with the level reduced by 1.
height Function: This function computes the height of the binary tree recursively. It takes the root node as an argument. The function works as follows:

If the node is NULL, it returns 0.
Otherwise, it computes the height of the left and right subtrees and returns the maximum of the two heights plus 1.
newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

main Function: In the main function, a binary tree is constructed, and the printLevelOrder function is called to print its level order traversal.

*/


