/*
 C++ program to populate inorder successor of all nodes.

 Input:
 	        10
			/ \
		    8 12
           /
          3

 Output:
 Next of 3 is 8
 Next of 8 is 10
 Next of 10 is 12
 Next of 12 is -1

*/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node* next;
};

/* Set next of p and all descendants of p
by traversing them in reverse Inorder */
void populateNext(node* p)
{
	// The first visited node will be the
	// rightmost node next of the rightmost
	// node will be NULL
	static node* next = NULL;

	if (p) {
		// First set the next pointer
		// in right subtree
		populateNext(p->right);

		// Set the next as previously visited
		// node in reverse Inorder
		p->next = next;

		// Change the prev for subsequent node
		next = p;

		// Finally, set the next pointer in
		// left subtree
		populateNext(p->left);
	}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	Node->next = NULL;

	return (Node);
}

int main()
{

	/* Constructed binary tree is
			 10
			/ \
		    8 12
           /
          3
	*/
	node* root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(12);
	root->left->left = newnode(3);

	// Populates nextRight pointer in all nodes
	populateNext(root);

	// Let us see the populated values
	node* ptr = root->left->left;
	while (ptr) {
		// -1 is printed if there is no successor
		cout << "Next of " << ptr->data << " is "
			<< (ptr->next ? ptr->next->data : -1) << endl;
		ptr = ptr->next;
	}

	return 0;
}

/*

node Class: The program starts by defining a node class that represents the nodes of the binary tree.
Each node has a data value, pointers to its left and right children, and a "next" pointer that will be used to point to the in-order successor.

populateNext Function: This function is used to populate the "next" pointers for in-order traversal successors of each node.
It performs a reverse in-order traversal of the binary tree and sets the "next" pointers appropriately.

The function works as follows:
The first visited node will be the rightmost node, and its "next" pointer will be set to NULL.
Recursively populate the "next" pointer for nodes in the right subtree.
Set the "next" pointer of the current node to the previously visited node (in reverse in-order traversal).
Change the previously visited node to the current node.
Recursively populate the "next" pointer for nodes in the left subtree.
newnode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

main Function: In the main function, a binary tree is constructed, and the populateNext function is called to populate the "next" pointers.
The program then prints the in-order successor for each node using the "next" pointers.

*/

