/*

Given a binary tree. Modify it in such a way that after modification you can have a preorder traversal of it using only the right pointers.
During modification, you can use right as well as left pointers.

Input :    10
          /   \
        8      2
      /  \
    3     5

Output :    10
              \
               8
                \
                 3
                  \
                   5
                    \
                     2

*/


#include <bits/stdc++.h>

using namespace std;

// A binary tree node has data, left child and right child
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// function that allocates a new node with the given data and NULL left and right pointers.
struct Node* newNode(int data)
{
	struct Node* node = new struct Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// Function to modify tree
struct Node* modifytree(struct Node* root)
{
	struct Node* right = root->right;
	struct Node* rightMost = root;

	// if the left tree exists
	if (root->left) {

		// get the right-most of the original left subtree
		rightMost = modifytree(root->left);

		// set root right to left subtree
		root->right = root->left;
		root->left = NULL;
	}

	// if the right subtree does not exists we are done!
	if (!right)
		return rightMost;

	// set right pointer of right-most of the original left subtree
	rightMost->right = right;

	// modify the rightsubtree
	rightMost = modifytree(right);
	return rightMost;
}

// printing using right pointer only
void printpre(struct Node* root)
{
	while (root != NULL) {
		cout << root->data << " ";
		root = root->right;
	}
}

int main()
{
	/* Constructed binary tree is
		10
		/ \
	   8  2
	  / \
     3  5	 */
	struct Node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);

	modifytree(root);
	printpre(root);

	return 0;
}


/*
Node Structure: The program starts by defining a Node structure that represents the nodes of a binary tree. Each node has a data value, and pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

modifytree Function: This function modifies the binary tree for traversal using only the right pointers. It takes the root node as an argument.

If the left subtree exists, the function recursively traverses it, finds the right-most node, and updates the right pointer of that node to point to the right subtree.
It then updates the root's right pointer to point to the modified left subtree.
Finally, it returns the right-most node of the modified left subtree.
printpre Function: This function prints the modified binary tree using only the right pointers. It starts from the root and traverses the tree by following the right pointers.

main Function: In the main function, a binary tree is constructed and modified using the modifytree function. Then, the printpre function is called to print the modified tree using only the right pointers.

*/

