/*
You are tasked to construct binary tree and calculate number of elements present in the tree.

Input: nodes=1,2,3,4,5
Output: Size of the tree is 5

*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

/* Computes the number of nodes in a tree. */
int size(node* node)
{
	if (node == NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Size of the tree is " << size(root);
	return 0;
}

/*
node Class: The program starts by defining a node class that represents the nodes of the binary tree. Each node has a data value, a pointer to
the left child, and a pointer to the right child.

newNode Function: This utility function creates a new node with the given data value and returns its pointer.

size Function: This recursive function calculates the size (number of nodes) of a binary tree. It takes a node pointer as a parameter.
The function works as follows:

If the current node is NULL, return 0 (size of an empty tree).
Recursively calculate the size of the left subtree using the size function.
Recursively calculate the size of the right subtree using the size function.
Add 1 to account for the current node.
main Function: In the main function, a binary tree is constructed, and the size of the tree is calculated using the size function.
The result is printed to the console.

*/



