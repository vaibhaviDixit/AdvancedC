/*
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.
Two nodes are cousins of each other if they are at same level and have different parents.

Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
       \
       15

Node1=4, Node2=7

Output: Yes

*/

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	int data;
	struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node* newNode(int item)
{
	struct Node* temp
		= new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to check if two Nodes are siblings
int isSibling(struct Node* root, struct Node* a,
			struct Node* b)
{
	// Base case
	if (root == NULL)
		return 0;

	return ((root->left == a && root->right == b)
			|| (root->left == b && root->right == a)
			|| isSibling(root->left, a, b)
			|| isSibling(root->right, a, b));
}

// Recursive function to find level of Node 'ptr' in a binary tree
int level(struct Node* root, struct Node* ptr, int lev)
{
	// base cases
	if (root == NULL)
		return 0;
	if (root == ptr)
		return lev;

	// Return level if Node is present in left subtree
	int l = level(root->left, ptr, lev + 1);
	if (l != 0)
		return l;

	// Else search in right subtree
	return level(root->right, ptr, lev + 1);
}

// Returns 1 if a and b are cousins, otherwise 0
int isCousin(struct Node* root, struct Node* a, struct Node* b)
{
	// 1. The two Nodes should be on the same level in the binary tree.
	// 2. The two Nodes should not be siblings (means that they should not have the same parent Node).
	if ((level(root, a, 1) == level(root, b, 1)) && !(isSibling(root, a, b)))
		return 1;
	else
		return 0;
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(15);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	struct Node *Node1, *Node2;
	Node1 = root->left->left;
	Node2 = root->right->right;

	if (isCousin(root, Node1, Node2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

/*

Node Structure Definition: The binary tree node structure is defined using the struct keyword. It includes an integer data representing the value of the node, and two pointers left and right representing the left and right children of the node.

New Node Function (newNode): This function creates and returns a new node with the given data. It allocates memory for the node using the new operator, initializes its data, and sets its left and right pointers to NULL.

Is Sibling Function (isSibling): This recursive function checks whether two given nodes are siblings. Two nodes are siblings if they have the same parent. It checks if the left child of the current node is one of the given nodes and the right child is the other given node, or vice versa. It also makes recursive calls to check in the left and right subtrees.

Level Function (level): This recursive function finds the level of a given node in the binary tree. It traverses the tree and increments the level as it moves down the tree. It returns the level at which the given node is found.

Is Cousin Function (isCousin): This function determines whether two given nodes are cousins. It first checks if both nodes are at the same level using the level function. Then, it checks if the nodes are not siblings using the isSibling function. If both conditions are met, it returns 1 (true), indicating that the nodes are cousins; otherwise, it returns 0 (false).

*/
