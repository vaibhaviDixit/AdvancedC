/*
Implement a program to check whether Binary search tree is balanced or not.

Input:
    10
   /  \
   8   18
  / \
  5  7
 /
3

Output: Tree is not balanced
*/


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		int data = d;
		left = right = NULL;
	}
};

// Function to calculate the height of a tree
int height(Node* node)
{
	// base case tree is empty
	if (node == NULL)
		return 0;

	// If tree is not empty then
	// height = 1 + max of left height
	// and right heights
	return 1 + max(height(node->left), height(node->right));
}

// Returns true if binary tree
// with root as root is height-balanced
bool isBalanced(Node* root)
{
	// for height of left subtree
	int lh;

	// for height of right subtree
	int rh;

	// If tree is empty then return true
	if (root == NULL)
		return 1;

	// Get the height of left and right sub trees
	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh - rh) <= 1 && isBalanced(root->left)
		&& isBalanced(root->right))
		return 1;

	// If we reach here then tree is not height-balanced
	return 0;
}

int main()
{
	Node* root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(18);
	root->left->left = new Node(5);
	root->left->right = new Node(9);
	root->left->left->left = new Node(3);

	if (isBalanced(root))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";
	return 0;
}

/*
In this program, we will create a function to check if an AVL tree is balanced or not.
An AVL tree is considered balanced if the balance factor of every node in the tree is between -1, 0, or 1.
The balance factor of a node is calculated as the difference between the heights of its left and right subtrees.
If the balance factor of any node is outside the range of -1 to 1, the tree is not balanced.

*/

