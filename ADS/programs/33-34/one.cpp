/*
Given a binary search tree and a key. Check the given key exists in BST or not without recursion.

Input:
          50
         /   \
		30	  70
		/ \   / \
	   20 40  60 80
Key=15

Output: No


Input:
          50
         /   \
		30	  70
		/ \   / \
	   20 40  60 80
Key=20

Output: Yes

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

// Function to check the given key exist or not
bool iterativeSearch(struct Node* root, int key)
{
	// Traverse until root reaches to dead end
	while (root != NULL) {
		// pass right subtree as new tree
		if (key > root->data)
			root = root->right;

		// pass left subtree as new tree
		else if (key < root->data)
			root = root->left;
		else
			return true; // if the key is found return 1
	}
	return false;
}

// A utility function to create a new BST Node
struct Node* newNode(int item)
{
	struct Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new Node with
given key in BST */
struct Node* insert(struct Node* Node, int data)
{
	/* If the tree is empty, return a new Node */
	if (Node == NULL)
		return newNode(data);

	/* Otherwise, recur down the tree */
	if (data < Node->data)
		Node->left = insert(Node->left, data);
	else if (data > Node->data)
		Node->right = insert(Node->right, data);

	/* return the (unchanged) Node pointer */
	return Node;
}

int main()
{
	/* Let us create following BST
           50
         /   \
		30	  70
		/ \   / \
	   20 40  60 80

    */
	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	if (iterativeSearch(root, 20))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

/*
The iterativeSearch function takes a pointer to the root of a BST and an integer key as its parameters. It performs an iterative search within the BST to find the given key. The function uses a while loop to traverse the tree until it either finds the key or reaches a dead end (a null node). If the key is found, the function returns true; otherwise, it returns false.

The newNode function is a utility function that creates and returns a new BST node with the given data value. It initializes the left and right pointers of the new node to NULL.

The insert function is used to insert a new node with a given key into the BST. It takes a pointer to the current node and the data value to be inserted as parameters. If the current node is NULL, it creates a new node with the given data and returns its pointer. Otherwise, it recursively traverses the tree based on the key value and inserts the new node in the appropriate position.

*/
