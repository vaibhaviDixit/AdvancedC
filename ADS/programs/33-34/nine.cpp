/*
Construct the BST (Binary Search Tree) from its given level order traversal.

Input: arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10 }
Output: Inorder Traversal: 1 3 4 5 6 7 8 10 12

*/

#include <bits/stdc++.h>

using namespace std;

// node of a BST
struct Node {
	int data;
	Node *left, *right;
};

// function to get a new node
Node* getNode(int data)
{
	// Allocate memory
	Node* newNode = (Node*)malloc(sizeof(Node));

	// put in the data
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// function to construct a BST from its level order traversal
Node* LevelOrder(Node* root, int data)
{
	if (root == NULL) {
		root = getNode(data);
		return root;
	}
	if (data <= root->data)
		root->left = LevelOrder(root->left, data);
	else
		root->right = LevelOrder(root->right, data);
	return root;
}

Node* constructBst(int arr[], int n)
{
	if (n == 0)
		return NULL;
	Node* root = NULL;

	for (int i = 0; i < n; i++)
		root = LevelOrder(root, arr[i]);

	return root;
}

// function to print the inorder traversal
void inorderTraversal(Node* root)
{
	if (!root)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

int main()
{
	int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Node* root = constructBst(arr, n);

	cout << "Inorder Traversal: ";
	inorderTraversal(root);
	return 0;
}

/*
The struct Node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The getNode function allocates memory for a new node and initializes it with the given data. It returns a pointer to the new node.

The LevelOrder function inserts a new node with the given data into the BST using level order traversal. If the tree is empty, it creates a root node. If the data is less than or equal to the current node's data, it inserts the data into the left subtree; otherwise, it inserts it into the right subtree.

The constructBst function constructs the BST from the level order traversal array by iterating through the array and using the LevelOrder function to insert each element into the tree.

The inorderTraversal function performs an inorder traversal of the tree and prints the values of the nodes.

*/

