/*
Given the root of a binary search tree and K as input, find Kth smallest element in BST.

Input: keys[] = { 20, 8, 22, 4, 12, 10, 14 }, k=3
Output: K-th Smallest Element is 10

*/

// A simple inorder traversal based C++ program to find k-th  smallest element in a BST.
#include <iostream>

using namespace std;

// A BST node
struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// Recursive function to insert an key into BST
Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

// Function to find k'th smallest element in BST
// Here count denotes the number of nodes processed so far
int count = 0;
Node* kthSmallest(Node* root, int& k)
{
	// base case
	if (root == NULL)
		return NULL;

	// search in left subtree
	Node* left = kthSmallest(root->left, k);

	// if k'th smallest is found in left subtree, return it
	if (left != NULL)
		return left;

	// if current element is k'th smallest, return it
	count++;
	if (count == k)
		return root;

	// else search in right subtree
	return kthSmallest(root->right, k);
}

// Function to print k'th smallest element in BST
void printKthSmallest(Node* root, int k)
{
	// maintain index to count number of nodes processed so far

	Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->data;
}

int main()
{
	Node* root = NULL;
	int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

	for (int x : keys)
		root = insert(root, x);

	int k = 3;
	printKthSmallest(root, k);
	return 0;
}

/*
The struct Node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The Node constructor initializes a node with the given data and sets its left and right pointers to NULL.

The insert function recursively inserts a new node with the given value into the BST. It traverses the tree based on the comparison of the value with the current node's data.

The global variable count is used to keep track of the number of nodes processed so far during the inorder traversal.

The kthSmallest function recursively searches for the k-th smallest element in the BST. It performs an inorder traversal while keeping track of the count of nodes visited. If the k-th smallest element is found, the function returns that node.

The printKthSmallest function takes the root of the BST and the value of k as arguments. It calls the kthSmallest function and prints the k-th smallest element if it exists, or a message if there are fewer than k nodes in the BST.

*/



