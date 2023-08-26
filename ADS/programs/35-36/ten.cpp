/*
Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Input: arr[] = {1, 2, 3}
Output: PreOrder Traversal of constructed BST 2 1 3

*/

#include <bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class TNode {
public:
	int data;
	TNode* left;
	TNode* right;
};

TNode* newNode(int data);

/* A function that constructs Balanced Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	TNode* root = newNode(arr[mid]);

	/* Recursively construct the left subtree and make it left child of root */
	root->left = sortedArrayToBST(arr, start, mid - 1);

	/* Recursively construct the right subtree and make it right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to print preorder traversal of BST */
void preOrder(TNode* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
	TNode* root = sortedArrayToBST(arr, 0, n - 1);
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);

	return 0;
}

/*
TNode Class: A class TNode is defined to represent a node in the Binary Search Tree. It has three members: an integer value to store the node's data, and pointers to the left and right child nodes.

newNode() Function: This function is a helper function that creates a new node with the given data and initializes its left and right pointers to NULL.

sortedArrayToBST() Function: This is the core function responsible for constructing a Balanced BST from a sorted array. It takes the sorted array, a start index, and an end index as arguments. It uses recursion to divide the array into two halves and constructs the tree in a balanced manner. The middle element of the current range is selected as the root, and then the left and right subtrees are constructed recursively using the smaller subarrays. This function returns the root of the constructed BST.

preOrder() Function: This is a utility function that performs a preorder traversal of the BST. It prints the data of the current node, then recursively traverses the left subtree, and finally the right subtree.

main() Function: In the main function, an array arr is defined with sorted integer values. The number of elements n is calculated based on the size of the array. The sortedArrayToBST() function is called with the array and the range [0, n-1] to construct a Balanced BST. Then, the preOrder() function is called to print the preorder traversal of the constructed BST.

*/



