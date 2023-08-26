/*
Given two values n1 and n2 (where n1 < n2) and a root pointer to a Binary Search Tree. Print all the keys of tree in range n1 to n2. i.e.
print all nodes n such that n1<=n<=n2 and n is a key of given BST. Print all the keys in increasing order.

Input:
         4
		/ \
	   2   7
	  / \  / \
     1  3  6 10

n1=4   n2=12

Output: 4 6 7 10

*/

#include <bits/stdc++.h>

using namespace std;

struct node {

	int data;
	struct node *left, *right;
};

// Function to print the keys in range
void RangeTraversal(node* root,
					int n1, int n2)
{
	if (!root)
		return;

	node* curr = root;

	while (curr) {

		if (curr->left == NULL)
		{
			// check if current node
			// lies between n1 and n2
			if (curr->data <= n2 &&
				curr->data >= n1)
			{
				cout << curr->data << " ";
			}

			curr = curr->right;
		}

		else {
			node* pre = curr->left;
			// finding the inorder predecessor-inorder predecessor is the right
			// most in left subtree or the left child, i.e in BST it is the maximum(right most) in left subtree.
			while (pre->right != NULL &&
				pre->right != curr)
						pre = pre->right;

			if (pre->right == NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}

			else {
				pre->right = NULL;

				// check if current node lies between n1 and n2
				if (curr->data <= n2 &&
					curr->data >= n1)
				{
					cout << curr->data << " ";
				}

				curr = curr->right;
			}
		}
	}
}

// Helper function to create a new node
node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->right = temp->left = NULL;

	return temp;
}

int main()
{

	/* Constructed binary tree is
		 4
		/ \
	   2   7
	  / \  / \
     1  3  6 10
*/

	node* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(10);

	RangeTraversal(root, 4, 12);

	return 0;
}

/*
The struct node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The RangeTraversal function performs a Morris traversal on the BST to print the keys that lie within the specified range [n1, n2].

Inside the RangeTraversal function:

It uses the curr pointer to traverse the tree.
In each iteration, it checks whether the left child of curr is NULL.
If so, it checks if the curr->data lies within the range [n1, n2] and prints it if true.
Then, it moves curr to its right child.
If the left child of curr is not NULL, it identifies the inorder predecessor of curr (i.e., the maximum value in the left subtree) and uses the Morris threading technique to traverse the tree.
If the right child of the inorder predecessor is not assigned (NULL), it assigns it to curr and moves curr to its left child.
If the right child of the inorder predecessor is already assigned to curr, it sets it back to NULL and checks if curr->data lies within the range [n1, n2]. If true, it prints the value of curr->data. Then, it moves curr to its right child.
The newNode function creates a new node with the given data and returns a pointer to it.

*/

