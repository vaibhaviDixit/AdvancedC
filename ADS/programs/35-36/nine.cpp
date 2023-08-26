/*
Given an array of N elements and two integers A, B which belong to the given array. Create a Binary Search Tree by inserting elements from arr[0]
to arr[n-1]. The task is to find the maximum element in the path from A to B.

Input : arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 }
        a = 1
        b = 10

Output : 12

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int data;
};

// Create and return a pointer of new Node.
Node *createNode(int x)
{
	Node *p = new Node;
	p -> data = x;
	p -> left = p -> right = NULL;
	return p;
}

// Insert a new Node in Binary Search Tree.
void insertNode(struct Node *root, int x)
{
	Node *p = root, *q = NULL;

	while (p != NULL)
	{
		q = p;
		if (p -> data < x)
			p = p -> right;
		else
			p = p -> left;
	}

	if (q == NULL)
		p = createNode(x);
	else
	{
		if (q -> data < x)
			q -> right = createNode(x);
		else
			q -> left = createNode(x);
	}
}

// Return the maximum element between a Node and its given ancestor.
int maxelpath(Node *q, int x)
{
	Node *p = q;

	int mx = INT_MIN;

	// Traversing the path between ancestor and Node and finding maximum element.
	while (p -> data != x)
	{
		if (p -> data > x)
		{
			mx = max(mx, p -> data);
			p = p -> left;
		}
		else
		{
			mx = max(mx, p -> data);
			p = p -> right;
		}
	}

	return max(mx, x);
}

// Return maximum element in the path between two given Node of BST.
int maximumElement(struct Node *root, int x, int y)
{
	Node *p = root;

	// Finding the LCA of Node x and Node y
	while ((x < p -> data && y < p -> data) ||
		(x > p -> data && y > p -> data))
	{
		// Checking if both the Node lie on the left side of the parent p.
		if (x < p -> data && y < p -> data)
			p = p -> left;

		// Checking if both the Node lie on the right side of the parent p.
		else if (x > p -> data && y > p -> data)
			p = p -> right;
	}

	// Return the maximum of maximum elements occur in path from ancestor to both Node.
	return max(maxelpath(p, x), maxelpath(p, y));
}

int main()
{
	int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
	int a = 8, b = 10;
	int n = sizeof(arr) / sizeof(arr[0]);

	// Creating the root of Binary Search Tree
	struct Node *root = createNode(arr[0]);

	// Inserting Nodes in Binary Search Tree
	for (int i = 1; i < n; i++)
		insertNode(root, arr[i]);

	cout << maximumElement(root, a, b) << endl;

	return 0;
}

/*
Struct Node: A structure is defined to represent a node in the Binary Search Tree. It has three members: a pointer to the left child, a pointer to the right child, and an integer value representing the data of the node.

createNode(): This function is used to create a new node with the given data and return a pointer to it.

insertNode(): This function is responsible for inserting a new node into the Binary Search Tree. It takes a root pointer and an integer value as arguments. The function traverses the tree based on the value of the data and inserts the new node at the appropriate location.

maxelpath(): This function calculates the maximum element between a given node and its ancestor. It takes a pointer to the node and an integer value as arguments. The function traverses the path from the node to the ancestor, keeping track of the maximum value encountered along the path. The maximum value could be either the node's own data or a value from its ancestor.

maximumElement(): This function is the main function responsible for finding the maximum element in the path between two given nodes in the BST. It takes the root pointer, and the values of the two nodes as arguments. The function first finds the Lowest Common Ancestor (LCA) of the two nodes. Then it calculates the maximum element in the path from the LCA to each of the given nodes using the maxelpath() function and returns the maximum of those two values.

main(): In the main function, an array arr is defined with some integer values representing the data of nodes to be inserted into the BST. The root node of the BST is created with the first element of the array. Then, a loop is used to insert the remaining elements into the BST using the insertNode() function. Finally, the maximumElement() function is called with two node values (a and b), and the maximum element along the path between these two nodes is printed.

*/

