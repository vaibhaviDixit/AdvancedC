/*
Write a function that returns true if the given Binary Tree is SumTree else false.
A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree.
An empty tree is SumTree and the sum of an empty tree can be considered as 0.
A leaf node is also considered as SumTree.

Input:
       26
     /    \
   10     3
  / \      \
 4   6      3

Output: The given tree is a SumTree

*/

#include <iostream>
using namespace std;

// A binary tree node has data, left child and right child
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

// A utility function to get the sum of values in tree with root as root
int sum(struct node *root)
{
	if (root == NULL)
		return 0;

	return sum(root->left) + root->data +
		sum(root->right);
}

// Returns 1 if sum property holds for the given node and both of its children
int isSumTree(struct node* node)
{
	int ls, rs;

	// If node is NULL or it's a leaf node then return true
	if (node == NULL ||
	(node->left == NULL &&
		node->right == NULL))
		return 1;

// Get sum of nodes in left and right subtrees
ls = sum(node->left);
rs = sum(node->right);

// If the node and both of its children satisfy the property return 1 else 0
	if ((node->data == ls + rs) &&
		isSumTree(node->left) &&
		isSumTree(node->right))
		return 1;

return 0;
}

// Helper function that allocates a new node with the given data and NULL left and right pointers.
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(
		sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{
	struct node *root = newNode(26);
	root->left = newNode(10);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(6);
	root->right->right = newNode(3);

	if (isSumTree(root))
		cout << "The given tree is a SumTree ";
	else
		cout << "The given tree is not a SumTree ";

	getchar();
	return 0;
}

/*
Node Structure Definition: The binary tree node structure is defined using the struct keyword. It includes an integer data representing the value
of the node, and two pointers left and right representing the left and right children of the node.

Sum Function (sum): This function calculates and returns the sum of all values in the binary tree rooted at the given node. It's a recursive
function that sums up values in the left subtree, adds the current node's value, and then sums up values in the right subtree.

Is Sum Tree Function (isSumTree): This function checks whether a given node and its children satisfy the Sum Tree property.
It first calculates the sums of values in the left and right subtrees, and then compares the current node's value with the sum of its children's
values. If the property holds for the current node and its children's subtrees, it returns 1 (true); otherwise, it returns 0 (false).

New Node Function (newNode): This function creates and returns a new node with the given data. It allocates memory for the node and initializes its
data and pointers to NULL.

*/





