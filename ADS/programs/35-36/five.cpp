/*
Write a C++ program of AVL tree that  handles duplicates

Input:
nodes= 9,5,10,5,9,7,17

Output:
Pre order traversal of the constructed AVL tree is
9(2) 5(2) 7(1) 10(1) 17(1)
Pre order traversal after deletion of 9
9(2) 5(2) 7(1) 10(1) 17(1)

*/

#include <bits/stdc++.h>
using namespace std;

// An AVL tree node
struct node {
	int key;
	struct node* left;
	struct node* right;
	int height;
	int count;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct node* newNode(int key)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	node->count = 1;
	return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node* rightRotate(struct node* y)
{
	struct node* x = y->left;
	struct node* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node* leftRotate(struct node* x)
{
	struct node* y = x->right;
	struct node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return (newNode(key));

	// If key already exists in BST, increment count and return
	if (key == node->key) {
		(node->count)++;
		return node;
	}

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* 2. Update height of this ancestor node */
	node->height = max(height(node->left), height(node->right)) + 1;

	/* 3. Get the balance factor of this ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// If key is present more than once, simply decrement
		// count and return
		if (root->count > 1) {
			(root->count)--;
			return NULL;
		}
		// Else, delete the node

		// node with only one child or no child
		if ((root->left == NULL) || (root->right == NULL)) {
			struct node* temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else // One child case
				*root = *temp; // Copy the contents of the non-empty child

			free(temp);
		}
		else {
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			struct node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node and update the count
			root->key = temp->key;
			root->count = temp->count;
			temp->count = 1;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
		return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = max(height(root->left), height(root->right)) + 1;

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
	// this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node* root)
{
	if (root != NULL) {
		cout << root->key << "("<<root->count << ")"<< " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	struct node* root = NULL;

	/* Constructing tree given in the above figure */
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 7);
	root = insert(root, 17);

	cout <<"Pre order traversal of the constructed AVL tree is \n";
	preOrder(root);


	cout <<"\nPre order traversal after deletion of 9 \n";
	preOrder(root);

	return 0;
}

/*
This program implements an AVL (Adelson-Velsky and Landis) tree with support for nodes containing duplicate keys. Additionally, it demonstrates the deletion of nodes while maintaining the AVL property.

The node structure represents a node in the AVL tree. It includes fields for the key, left and right children, height of the node, and a count to track duplicate keys.

The height() function calculates the height of a node in the tree. It returns 0 for a NULL node.

The max() function returns the maximum of two integers.

The newNode() function dynamically allocates memory for a new node and initializes its fields.

The rightRotate() function performs a right rotation operation on the given node y, adjusting the heights of nodes involved.

The leftRotate() function performs a left rotation operation on the given node x, maintaining the AVL balance.

The getBalance() function calculates the balance factor of a node by subtracting the height of the right subtree from the height of the left subtree.

The insert() function inserts a new key into the AVL tree. It handles duplicates by incrementing the count field.

The minValueNode() function returns the node with the minimum key value in the subtree.

The deleteNode() function deletes a node with a given key from the AVL tree, maintaining the AVL balance. For duplicate keys, the count field is decremented.

The preOrder() function performs a preorder traversal of the AVL tree, printing keys and their corresponding counts.

In the main() function:

An AVL tree is constructed by inserting nodes with various keys.
The structure of the constructed AVL tree is displayed using preorder traversal.
A node with a key of 9 is deleted, and the updated AVL tree structure is displayed again.

*/
