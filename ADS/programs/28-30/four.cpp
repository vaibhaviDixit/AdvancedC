/*
Given two Binary Trees, write a function that returns true if two trees are mirror of each other, else false.

Input:
   1
  / \
  3  2
    /  \
    5   4

   1
  / \
  2  3
 / \
4   5

Output: Yes

*/

#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node
{
	int data;
	Node* left, *right;
};

/* Given two trees, return true if they are
mirror of each other */
/*As function has to return bool value instead integer value*/
bool areMirror(Node* a, Node* b)
{
	/* Base case : Both empty */
	if (a==NULL && b==NULL)
		return true;

	// If only one is empty
	if (a==NULL || b == NULL)
		return false;

	/* Both non-empty, compare them recursively
	Note that in recursive calls, we pass left
	of one tree and right of other tree */
	return a->data == b->data &&
			areMirror(a->left, b->right) &&
			areMirror(a->right, b->left);
}

/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}


int main()
{
	Node *a = newNode(1);
	Node *b = newNode(1);
	a->left = newNode(2);
	a->right = newNode(3);
	a->left->left = newNode(4);
	a->left->right = newNode(5);

	b->left = newNode(3);
	b->right = newNode(2);
	b->right->left = newNode(5);
	b->right->right = newNode(4);

	areMirror(a, b)? cout << "Yes" : cout << "No";

	return 0;
}

/*
Node Structure: The program starts by defining a Node structure that represents the nodes of the binary tree. Each node has a data value, a
pointer to the left child, and a pointer to the right child.

areMirror Function: This function takes two pointers to the root nodes of two binary trees and returns a boolean value indicating whether the
trees are mirrors of each other or not. The function works as follows:

If both trees are empty (both pointers are NULL), return true.
If only one tree is empty, return false.
Check if the data values of the current nodes in the two trees are equal.
Recursively call areMirror for the left subtree of the first tree and the right subtree of the second tree.
Recursively call areMirror for the right subtree of the first tree and the left subtree of the second tree.
If all conditions are satisfied, return true. Otherwise, return false.
newNode Function: This utility function creates a new node with the given data value and returns its pointer.

main Function: In the main function, two binary trees (a and b) are constructed. The trees are considered mirrors of each other if the areMirror
function returns true, and they are not mirrors if the function returns false. The result is printed to the console.

*/
