/*
Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way that keeps the original structure of Binary Tree.

Input:
          10
         /  \
        2    7
       / \
      8   4
Output: Following is Inorder Traversal of the converted BST: 2 4 7 8 10

*/

#include <iostream>
using namespace std;

/* A binary tree node structure */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* A helper function that stores inorder
traversal of a tree rooted with node */
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
	// Base Case
	if (node == NULL)
		return;

	/* first store the left subtree */
	storeInorder(node->left, inorder, index_ptr);

	/* Copy the root's data */
	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	/* finally store the right subtree */
	storeInorder(node->right, inorder, index_ptr);
}

/* A helper function to count nodes in a Binary Tree */
int countNodes(struct node* root)
{
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

/* A helper function that copies contents of arr[] to Binary Tree. This function basically does Inorder traversal of Binary Tree and one by one
copy arr[] elements to Binary Tree nodes */
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
	// Base Case
	if (root == NULL)
		return;

	/* first update the left subtree */
	arrayToBST(arr, root->left, index_ptr);

	/* Now update root's data and increment index */
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	/* finally update the right subtree */
	arrayToBST(arr, root->right, index_ptr);
}

// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node* root)
{
	// base case: tree is empty
	if (root == NULL)
		return;

	/* Count the number of nodes in Binary Tree so that
	we know the size of temporary array to be created */
	int n = countNodes(root);

	// Create a temp array arr[] and store inorder traversal of tree in arr[]
	int* arr = new int[n];
	int i = 0;
	storeInorder(root, arr, &i);

	// Sort the array using library function for quick sort
	qsort(arr, n, sizeof(arr[0]), compare);

	// Copy array elements back to Binary Tree
	i = 0;
	arrayToBST(arr, root, &i);

	// delete dynamically allocated memory to avoid memory leak
	delete[] arr;
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node* temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Utility function to print inorder traversal of Binary Tree */
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout <<" "<< node->data;

	/* now recur on right child */
	printInorder(node->right);
}

int main()
{
	struct node* root = NULL;

	/* Constructing tree given in the above figure
		10
		/ \
		30 15
	   /	 \
	  20	 5

    */
	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->right->right = newNode(5);

	// convert Binary Tree to BST
	binaryTreeToBST(root);

	cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
	printInorder(root);

	return 0;
}

/*
The struct node defines the structure of a binary tree node, containing an integer value (data) and pointers to its left and right children (left and right).

The storeInorder function performs an inorder traversal of the binary tree rooted at a given node and stores the traversed elements in an array. The index_ptr parameter is used to keep track of the current index in the array.

The countNodes function calculates the number of nodes in a binary tree using a recursive approach.

The compare function is used as a comparison function for the qsort library function to sort the array of integers.

The arrayToBST function takes an array of integers (arr), a binary tree node (root), and an index pointer (index_ptr). It updates the binary tree nodes' data values with the values from the sorted array, maintaining the BST property. The index_ptr is incremented as elements from the array are used.

The binaryTreeToBST function is the core of the conversion process. It first counts the number of nodes in the binary tree, creates an array to store inorder traversal, fills the array with the inorder traversal, sorts the array, and finally updates the binary tree nodes' values using the arrayToBST function.

The newNode function is a utility function that creates a new binary tree node and returns its pointer.

The printInorder function performs an inorder traversal of the binary tree and prints the values of the nodes.

*/


