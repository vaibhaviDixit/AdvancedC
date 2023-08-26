/*
Given a binary tree, print all its root-to-leaf paths without using recursion. For example, consider the following Binary Tree.

Input:
        6
     /    \
    3      5
  /   \     \
 2     5     4
     /   \
    7     4

Output:

  6->3->2
  6->3->5->7
  6->3->5->4
  6->5>4

*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree */
struct Node
{
	int data;
	struct Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers.*/
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

/* Function to print root to leaf path for a leaf
using parent nodes stored in map */
void printTopToBottomPath(Node* curr,
						map<Node*, Node*> parent)
{
	stack<Node*> stk;

	// start from leaf node and keep on pushing
	// nodes into stack till root node is reached
	while (curr)
	{
		stk.push(curr);
		curr = parent[curr];
	}

	// Start popping nodes from stack and print them
	while (!stk.empty())
	{
		curr = stk.top();
		stk.pop();
		cout << curr->data << " ";
	}
	cout << endl;
}

/* An iterative function to do preorder traversal
of binary tree and print root to leaf path
without using recursion */
void printRootToLeaf(Node* root)
{
	// Corner Case
	if (root == NULL)
		return;

	// Create an empty stack and push root to it
	stack<Node*> nodeStack;
	nodeStack.push(root);

	// Create a map to store parent pointers of binary
	// tree nodes
	map<Node*, Node*> parent;

	// parent of root is NULL
	parent[root] = NULL;

	/* Pop all items one by one. Do following for
	every popped item
		a) push its right child and set its parent
		pointer
		b) push its left child and set its parent
		pointer
	Note that right child is pushed first so that
	left is processed first */
	while (!nodeStack.empty())
	{
		// Pop the top item from stack
		Node* current = nodeStack.top();
		nodeStack.pop();

		// If leaf node encountered, print Top To
		// Bottom path
		if (!(current->left) && !(current->right))
			printTopToBottomPath(current, parent);

		// Push right & left children of the popped node
		// to stack. Also set their parent pointer in
		// the map
		if (current->right)
		{
			parent[current->right] = current;
			nodeStack.push(current->right);
		}
		if (current->left)
		{
			parent[current->left] = current;
			nodeStack.push(current->left);
		}
	}
}

int main()
{
	/* Constructed binary tree is
		10
		/ \
	    8  2
	   / \ /
      3	 5 2
 */
	Node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);

	printRootToLeaf(root);

	return 0;
}

/*
Node Structure: The program starts by defining a Node structure that represents the nodes of a binary tree. Each node has a data value, and pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

printTopToBottomPath Function: This function prints a root-to-leaf path by traversing from a leaf node up to the root node using a map that stores parent pointers. It takes the current node and the parent map as arguments.

It pushes nodes into a stack while traversing from the leaf to the root using parent pointers.
After reaching the root, it pops nodes from the stack and prints their data values.
printRootToLeaf Function: This function performs an iterative preorder traversal of the binary tree and prints all root-to-leaf paths.

It starts by pushing the root node into a stack.
It maintains a parent map to store parent pointers of binary tree nodes.
It iteratively pops nodes from the stack and performs the following:
If a leaf node is encountered (both left and right children are NULL), it calls the printTopToBottomPath function to print the root-to-leaf path for that node.
It pushes the right and left children of the current node onto the stack and updates their parent pointers in the parent map.
main Function: In the main function, a binary tree is constructed, and the printRootToLeaf function is called to print all root-to-leaf paths.

*/


