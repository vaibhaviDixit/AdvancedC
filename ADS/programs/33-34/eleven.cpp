/*
We have given a binary search tree and we want to delete the leaf nodes from the binary search tree.

Input : 20 10 5 15 30 25 35
Output : Inorder before Deleting the leaf node: 5 10 15 20 25 30 35
         Inorder after Deleting the leaf node: 10 20 30

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// Create a newNode in binary search tree.
struct Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Insert a Node in binary search tree.
struct Node* insert(struct Node* root, int data)
{
	if (root == NULL)
		return newNode(data);
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}

// Function for inorder traversal in a BST.
void inorder(struct Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

// Delete leaf nodes from binary search tree.
struct Node* leafDelete(struct Node* root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL) {
		free(root);
		return NULL;
	}

	// Else recursively delete in left and right subtrees.
	root->left = leafDelete(root->left);
	root->right = leafDelete(root->right);

	return root;
}

int main()
{
	struct Node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	cout << "Inorder before Deleting the leaf Node." << endl;
	inorder(root);
	cout << endl;
	leafDelete(root);
	cout << "INorder after Deleting the leaf Node." << endl;
	inorder(root);
	return 0;
}

/*
The struct Node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The newNode function creates a new node in the BST with the given data and initializes its left and right pointers to NULL.

The insert function inserts a new node with the given data into the BST. It traverses the tree based on the comparison of the value with the current node's data.

The inorder function performs an inorder traversal of the BST and prints the data of each node.

The leafDelete function recursively deletes leaf nodes from the BST. If the current node is a leaf node (both left and right pointers are NULL), it frees the memory allocated for the node and returns NULL. Otherwise, it recursively deletes leaf nodes from the left and right subtrees.

*/



