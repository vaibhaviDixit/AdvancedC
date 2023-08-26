/*
Given a binary tree and an array, the task is to find if the given array sequence is present as a root-to-leaf path in given tree.

Tree:
      5
    /  \
   2    3
  / \
 1   4
    / \
   6   8

Input : arr[] = {5, 2, 4, 8} for above tree
Output: "Path Exist"

Input :  arr[] = {5, 3, 4, 9} for above tree
Output: "Path does not Exist"

*/

#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
};

/* utility that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newnode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}


// Util function
bool existPathUtil(struct Node *root, int arr[], int n, int index)
{
	// If root is NULL or reached end of the array
	if(root == NULL or index==n)
			return false;

	// If current node is leaf
	if (root->left == NULL && root->right == NULL)
	{
		if((root->data == arr[index]) && (index == n-1))
			return true;

	return false;
	}

	// If current node is equal to arr[index] this means that till this level path has been matched and
	// remaining path can be either in left subtree or right subtree.
	return ((index < n) && (root->data == arr[index]) &&
				(existPathUtil(root->left, arr, n, index+1) ||
				existPathUtil(root->right, arr, n, index+1) ));
}

// Function to check given sequence of root to leaf path exist in tree or not.
// index represents current element in sequence of root to leaf path
bool existPath(struct Node *root, int arr[], int n, int index)
{
	if(!root)
		return (n==0);

	return existPathUtil(root, arr, n, 0);
}

int main()
{
	// arr[] --> sequence of root to leaf path
	int arr[] = {5, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	struct Node *root = newnode(5);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(1);
	root->left->right = newnode(4);
	root->left->right->left = newnode(6);
	root->left->right->left = newnode(8);

	existPath(root, arr, n, 0)? cout << "Path Exists" :
								cout << "Path does not Exist";
	return 0;
}



/*
Node Structure: The program defines a structure Node to represent a node in a binary tree. Each node has a data field, and pointers to its left and right children.

newnode Function: This function creates a new node with the given integer data. It allocates memory for the node, sets its data, and initializes its left and right pointers to NULL.

existPathUtil Function: This is a utility function that checks if there exists a root-to-leaf path in the binary tree that matches the given sequence. It takes the current node, the sequence array, the length of the sequence array, and the index of the current element being checked in the sequence. It performs a recursive depth-first traversal of the binary tree while comparing the elements of the sequence. If a leaf node is reached and the sequence matches, the function returns true.

existPath Function: This function is the main interface for checking if the given sequence exists as a root-to-leaf path in the binary tree. It first checks if the root is NULL, in which case it returns true only if the sequence is empty. Otherwise, it calls the existPathUtil function to perform the actual check starting from the root.

*/
