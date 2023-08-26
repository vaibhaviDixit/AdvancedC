/*

Given two arrays that represent Preorder traversals of a full binary tree and its mirror tree, we need to write a program to construct the binary
tree using these two Preorder traversals. A Full Binary Tree is a binary tree where every node has either 0 or 2 children.


Input :  preOrder[] = {1,2,4,5,3,6,7}
         preOrderMirror[] = {1,3,7,6,2,5,4}

Output :          1
               /    \
              2      3
            /   \   /  \
           4     5 6    7

*/

#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder(Node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

// A recursive function to construct Full binary tree from pre[] and preM[]. preIndex is used to keep
// track of index in pre[]. l is low index and h is high index for the current subarray in preM[]
Node* constructBinaryTreeUtil(int pre[], int preM[],
					int &preIndex, int l,int h,int size)
{
	// Base case
	if (preIndex >= size || l > h)
		return NULL;

	// The first node in preorder traversal is root.
	// So take the node at preIndex from preorder and
	// make it root, and increment preIndex
	Node* root = newNode(pre[preIndex]);
		++(preIndex);

	// If the current subarray has only one element, no need to recur
	if (l == h)
		return root;

	// Search the next element of pre[] in preM[]
	int i;
	for (i = l; i <= h; ++i)
		if (pre[preIndex] == preM[i])
			break;

	// construct left and right subtrees recursively
	if (i <= h)
	{
		root->left = constructBinaryTreeUtil (pre, preM,
									preIndex, i, h, size);
		root->right = constructBinaryTreeUtil (pre, preM,
								preIndex, l+1, i-1, size);
	}

	// return root
	return root;
}

// function to construct full binary tree using its preorder traversal and preorder traversal of its mirror tree
void constructBinaryTree(Node* root,int pre[],
						int preMirror[], int size)
{
	int preIndex = 0;
	int preMIndex = 0;

	root = constructBinaryTreeUtil(pre,preMirror,
							preIndex,0,size-1,size);

	printInorder(root);
}

int main()
{
	int preOrder[] = {1,2,4,5,3,6,7};
	int preOrderMirror[] = {1,3,7,6,2,5,4};

	int size = sizeof(preOrder)/sizeof(preOrder[0]);

	Node* root = new Node;

	constructBinaryTree(root,preOrder,preOrderMirror,size);

	return 0;
}

/*
Node Structure: The program defines a Node structure representing nodes of a binary tree. Each node has a data value, and pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

printInorder Function: This utility function performs an inorder traversal of the binary tree and prints the values of the nodes.

constructBinaryTreeUtil Function: This function is a recursive helper function that constructs a binary tree using the given preorder traversal and the preorder traversal of its mirror tree.

It takes pre, preM, preIndex, l, h, and size as arguments. preIndex keeps track of the current index in the pre array.
The first element of pre is the root. It creates a node for the root and increments preIndex.
It searches for the next element of pre in preM and finds the index i. This index divides the subtrees into the left and right subtrees.
Recursively constructs the left and right subtrees by calling constructBinaryTreeUtil with appropriate arguments.
Returns the constructed root.
constructBinaryTree Function: This function constructs a full binary tree using the given preorder traversal and the preorder traversal of its mirror tree.

It takes root, pre, preMirror, and size as arguments.
Calls the constructBinaryTreeUtil function to construct the binary tree and assigns the root.
main Function: In the main function, two arrays preOrder and preOrderMirror are provided representing the preorder traversal of the original tree and its mirror tree.

The constructBinaryTree function is called to construct the binary tree.
Finally, the printInorder function is called to print the inorder traversal of the constructed binary tree.

*/

