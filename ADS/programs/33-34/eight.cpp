/*
Given a BST, transform it into a greater sum tree where each node contains the sum of all nodes greater than that node.

Input:
         11
       /    \
      2      29
     / \    /   \
    1   7   15  40
               /
              35

Output:
Inorder Traversal of given tree
1 2 7 11 15 29 35 40

Inorder Traversal of transformed tree
139 137 130 119 104 75 40 0

*/

#include<iostream>
using namespace std;

// A BST node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to transform a BST to sum tree. This function traverses the tree in reverse inorder so
// that we have visited all greater key nodes of the currently visited node
void transformTreeUtil(struct Node *root, int *sum)
{
// Base case
if (root == NULL) return;

// Recur for right subtree
transformTreeUtil(root->right, sum);

// Update sum
*sum = *sum + root->data;

// Store old sum in current node
root->data = *sum - root->data;

// Recur for left subtree
transformTreeUtil(root->left, sum);
}

// A wrapper over transformTreeUtil()
void transformTree(struct Node *root)
{
	int sum = 0; // Initialize sum
	transformTreeUtil(root, &sum);
}

// A utility function to print indorder traversal of a binary tree
void printInorder(struct Node *root)
{
	if (root == NULL) return;

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

int main()
{
	struct Node *root = newNode(11);
	root->left = newNode(2);
	root->right = newNode(29);
	root->left->left = newNode(1);
	root->left->right = newNode(7);
	root->right->left = newNode(15);
	root->right->right = newNode(40);
	root->right->right->left = newNode(35);

	cout << "Inorder Traversal of given tree\n";
	printInorder(root);

	transformTree(root);

	cout << "\n\nInorder Traversal of transformed tree\n";
	printInorder(root);

	return 0;
}

/*
The struct Node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The newNode function is a utility that creates and initializes a new binary tree node with the given data. It returns a pointer to the new node.

The transformTreeUtil function is a recursive utility function that transforms the BST into a Sum Tree. It uses reverse inorder traversal so that it first processes all greater key nodes before the current node.

Inside transformTreeUtil:

The base case is when the node is NULL, in which case the function returns.
It first recurs for the right subtree.
It updates the sum variable by adding the current node's data to it.
It then stores the old sum in the current node by subtracting the current node's data from the updated sum.
Finally, it recurs for the left subtree.
The transformTree function is a wrapper function that initializes the sum to 0 and calls transformTreeUtil with the root of the tree.

The printInorder function performs an inorder traversal of the tree and prints the values of the nodes.

*/


