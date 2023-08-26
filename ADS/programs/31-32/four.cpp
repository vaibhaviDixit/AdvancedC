/*
Given a Binary Tree, find if there exists an edge whose removal creates two trees of equal size.

Input : root of following tree
           5
         /   \
       1      6
      /      /  \
     3      7    4
Output : true

( Removing edge 5-6 creates two trees of equal size )

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

// utility function to create a new node
struct Node* newNode(int x)
{
	struct Node* temp = new Node;
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
};

// To calculate size of tree with given root
int count(Node* root)
{
	if (root==NULL)
		return 0;
	return count(root->left) + count(root->right) + 1;
}

// This function returns true if there is an edge whose removal can divide the tree in two halves n is size of tree
bool checkRec(Node* root, int n)
{
	// Base cases
	if (root ==NULL)
	return false;

	// Check for root
	if (count(root) == n-count(root))
		return true;

	// Check for rest of the nodes
	return checkRec(root->left, n) ||
		checkRec(root->right, n);
}

// This function mainly uses checkRec()
bool check(Node *root)
{
	// Count total nodes in given tree
	int n = count(root);

	// Now recursively check all nodes
	return checkRec(root, n);
}

int main()
{
	struct Node* root = newNode(5);
	root->left = newNode(1);
	root->right = newNode(6);
	root->left->left = newNode(3);
	root->right->left = newNode(7);
	root->right->right = newNode(4);

	check(root)? printf("YES") : printf("NO");

	return 0;
}

/*

Utility Function to Create a New Node (newNode): This function takes an integer x and creates a new node with the given value.
The left and right pointers are initialized to NULL, and the new node is returned.

Function to Calculate Size of Tree with Given Root (count): This function recursively calculates the number of nodes in a tree with the given root.
It counts the nodes in the left subtree, the right subtree, and the current root itself, and returns the total count.

Recursive Function to Check if Edge Removal Divides Tree (checkRec): This function takes a root node and the total number of nodes n as inputs.
It recursively checks whether there exists an edge whose removal would divide the tree into two subtrees of equal size.
The base case is when the root is NULL, in which case it returns false. It checks if the count of nodes in the left subtree is equal to n minus
the count of nodes in the right subtree. If this condition is satisfied, it returns true. Otherwise, it recursively checks for the condition in
both the left and right subtrees.

Main Function to Check and Output Result (check): This function calculates the total number of nodes in the given tree using the count function.
Then, it calls the checkRec function with the root and the total number of nodes. It returns the result of this check.

*/


