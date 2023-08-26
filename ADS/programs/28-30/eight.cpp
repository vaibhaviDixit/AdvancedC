/*
Given Preorder, Inorder, and Postorder traversals of some tree. Write a program to check if they all are of the same tree.

Input : Inorder -> 4 2 5 1 3
        Preorder -> 1 2 4 5 3
        Postorder -> 4 5 2 3 1
Output : Yes


Input : Inorder -> 4 2 5 1 3
        Preorder -> 1 5 4 2 3
        Postorder -> 4 1 2 3 5
Output : No

*/


#include <bits/stdc++.h>
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

/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(int arr[], int strt, int end, int value)
{
	for (int i = strt; i <= end; i++)
	{
		if(arr[i] == value)
			return i;
	}
}

/* Recursive function to construct binary tree
of size len from Inorder traversal in[] and
Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking for
cases where inorder and preorder do not form a
tree */
Node* buildTree(int in[], int pre[], int inStrt,
									int inEnd)
{
	static int preIndex = 0;

	if(inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal
	using preIndex and increment preIndex */
	Node *tNode = newNode(pre[preIndex++]);

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in
	Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, tNode->data);

	/* Using index in Inorder traversal,
	construct left and right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex-1);
	tNode->right = buildTree(in, pre, inIndex+1, inEnd);

	return tNode;
}

/* function to compare Postorder traversal
on constructed tree and given Postorder */
int checkPostorder(Node* node, int postOrder[], int index)
{
	if (node == NULL)
		return index;

	/* first recur on left child */
	index = checkPostorder(node->left,postOrder,index);

	/* now recur on right child */
	index = checkPostorder(node->right,postOrder,index);

	/* Compare if data at current index in
	both Postorder traversals are same */
	if (node->data == postOrder[index])
		index++;
	else
		return -1;

	return index;
}

int main()
{
	int inOrder[] = {4, 2, 5, 1, 3};
	int preOrder[] = {1, 2, 4, 5, 3};
	int postOrder[] = {4, 5, 2, 3, 1};

	int len = sizeof(inOrder)/sizeof(inOrder[0]);

	// build tree from given
	// Inorder and Preorder traversals
	Node *root = buildTree(inOrder, preOrder, 0, len - 1);

	// compare postorder traversal on constructed
	// tree with given Postorder traversal
	int index = checkPostorder(root,postOrder,0);

	// If both postorder traversals are same
	if (index == len)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}



/*
Node Structure: The program starts by defining a Node structure that represents the nodes of the binary tree. Each node has a data value, pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

search Function: This utility function searches for a value in an array within the specified range and returns the index of the value in the array.

buildTree Function: This recursive function constructs a binary tree from its Inorder and Preorder traversals. It takes the Inorder array, Preorder array, and the range of indices to consider for constructing the tree. The function works as follows:

Pick the current node from Preorder traversal using the preIndex and increment preIndex.
If the current node has no children, return the node.
Find the index of the current node's value in the Inorder traversal.
Recursively build the left subtree and right subtree by calling the buildTree function on appropriate ranges of indices.
Return the current node.
checkPostorder Function: This recursive function compares the Postorder traversal of the given tree with the given Postorder array. It takes the current node, the Postorder array, and the current index in the Postorder array. The function works as follows:

If the node is NULL, return the current index.
Recur on the left subtree.
Recur on the right subtree.
Compare the current node's data with the value at the current index in the Postorder array. If they match, increment the index; otherwise, return -1.
Return the updated index.
main Function: In the main function, the Inorder, Preorder, and Postorder arrays are given. The binary tree is constructed using the buildTree function. Then, the checkPostorder function is called to compare the Postorder traversal of the constructed tree with the given Postorder array. If they match, it indicates that the traversals belong to the same binary tree.

*/
