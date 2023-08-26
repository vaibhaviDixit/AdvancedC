/*
Given a Binary Tree and a key, write a function that returns level of the key.

Input:
     3
	/  \
	2   5
   / \
   1  4

Output:
Level of 1 is 3
Level of 2 is 2
Level of 3 is 1
Level of 4 is 3
Level of 5 is 2

*/

// C++ program to Get Level of a node in a Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
struct node {
	int data;
	struct node* left;
	struct node* right;
};
// Helper function for getLevel(). It returns level of the data if data is present in tree, otherwise returns 0.
int getLevelUtil(struct node* node, int data, int level)
{
	if (node == NULL)
		return 0;

	if (node->data == data)
		return level;

	int downlevel
		= getLevelUtil(node->left, data, level + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = getLevelUtil(node->right, data, level + 1);
	return downlevel;
}

/* Returns level of given data value */
int getLevel(struct node* node, int data)
{
	return getLevelUtil(node, data, 1);
}

// Utility function to create a new Binary Tree node
struct node* newNode(int data)
{
	struct node* temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main()
{
	struct node* root = new struct node;
	int x;

	// Constructing tree given in the above figure
	root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	for (x = 1; x <= 5; x++) {
		int level = getLevel(root, x);
		if (level)
			cout << "Level of " << x << " is " << level
				<< endl;
		else
			cout << x << "is not present in tree" << endl;
	}

	getchar();
	return 0;
}

/*
node Structure: The program starts by defining a node structure that represents the nodes of the binary tree. Each node has data, a pointer to the left child, and a pointer to the right child.

getLevelUtil Function: This is a helper function for getLevel. It takes a node pointer, a data value to search for, and the current level. The function returns the level of the node containing the given data value. If the node is not found, it returns 0. The function works as follows:

If the current node is NULL, return 0.
If the current node's data matches the target data, return the current level.
Recursively call getLevelUtil for the left and right subtrees, incrementing the level by 1.
If the target data is found in the left subtree, return the result of the left subtree search.
If the target data is found in the right subtree, return the result of the right subtree search.
getLevel Function: This function takes a node pointer and a data value and returns the level of the node containing the given data. It calls the getLevelUtil function with an initial level of 1.

newNode Function: This utility function creates a new node with the given data and returns its pointer.

main Function: In the main function, a sample binary tree is constructed, and for each node from 1 to 5, its level in the tree is calculated using the getLevel function. The result is printed to the console.

*/
