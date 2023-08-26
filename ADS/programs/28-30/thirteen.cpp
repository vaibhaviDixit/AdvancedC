/*
Given an array ‘pre[]’ that represents Preorder traversal of a special binary tree where every node has either 0 or 2 children.
One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that the corresponding node
in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is a non-leaf node.
Write a function to construct the tree from the given two arrays.

Input:   pre[] = {10, 30, 20, 5, 15};
	     preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Inorder Traversal of the Constructed Binary Tree: 20 30 5 10 15

*/

#include<bits/stdc++.h>

// A binary tree node structure
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// Utility function to create a new Binary Tree node
struct node* newNode (int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* A recursive function to create a Binary Tree from given pre[]
preLN[] arrays. The function returns root of tree. index_ptr is used
to update index values in recursive calls. index must be initially
passed as 0 */
struct node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n)
{
	int index = *index_ptr; // store the current value of index in pre[]

	// Base Case: All nodes are constructed
	if (index == n)
		return NULL;

	// Allocate memory for this node and increment index for
	// subsequent recursive calls
	struct node *temp = newNode ( pre[index] );
	(*index_ptr)++;

	// If this is an internal node, construct left and
	// right subtrees and link the subtrees
	if (preLN[index] == 'N')
	{
	temp->left = constructTreeUtil(pre, preLN, index_ptr, n);
	temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
	}

	return temp;
}

// A wrapper over constructTreeUtil()
struct node *constructTree(int pre[], char preLN[], int n)
{
	/* Initialize index as 0. Value of index is
	used in recursion to maintain the current
	index in pre[] and preLN[] arrays. */
	int index = 0;

	return constructTreeUtil (pre, preLN, &index, n);
}


// This function is used only for testing
void printInorder (struct node* node)
{
	if (node == NULL)
		return;

	// First recur on left child
	printInorder (node->left);

	// Print the data of node
	printf("%d ", node->data);

	// Now recur on right child
	printInorder (node->right);
}


int main()
{
	struct node *root = NULL;

	/* Constructing tree given in the above figure
		10
		/ \
		30 15
	   / \
	   20 5
    */
	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
	int n = sizeof(pre)/sizeof(pre[0]);

	// construct the above tree
	root = constructTree (pre, preLN, n);

	// Test the constructed tree
	printf("Inorder Traversal of the Constructed Binary Tree: \n");
	printInorder (root);

	return 0;
}

/*
node Structure: The program defines a node structure representing nodes of a binary tree. Each node has a data value, and pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

constructTreeUtil Function: This recursive utility function constructs a binary tree using the given preorder traversal array pre and a corresponding leaf node array preLN. It takes a reference to the current index index_ptr in the pre array, and n represents the number of elements in the arrays.

The function first stores the current value of the index.
It allocates memory for a new node with data equal to pre[index] and increments the index.
If the leaf node array value at the current index is 'N', it means the node is not a leaf node. In this case, it recursively constructs the left and right subtrees using the same function.
The function returns the constructed node.
constructTree Function: This is a wrapper function that initializes the index as 0 and calls the constructTreeUtil function.

printInorder Function: This utility function performs an inorder traversal of the binary tree and prints the values of the nodes.

main Function: In the main function, the program constructs a binary tree using the given preorder traversal array pre and leaf node array preLN.

The constructed tree is then tested by printing its inorder traversal.

*/

