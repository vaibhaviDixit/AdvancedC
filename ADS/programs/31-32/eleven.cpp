/*
Given a binary tree, print the vertical sum of the tree.

Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
         \
          8
           \
            9

Output:

Following are the values of vertical sums with the positions of the columns with respect to root
-2: 4
-1: 2
0: 12
1: 11
2: 7
3: 9

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new Binary Tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Traverses the tree in in-order form and populates a hashMap that contains the vertical sum
void verticalSumUtil(Node *node, int hd,
					map<int, int> &Map)
{
	// Base case
	if (node == NULL) return;

	// Recur for left subtree
	verticalSumUtil(node->left, hd-1, Map);

	// Add val of current node to map entry of corresponding hd
	Map[hd] += node->data;

	// Recur for right subtree
	verticalSumUtil(node->right, hd+1, Map);
}

// Function to find vertical sum
void verticalSum(Node *root)
{
	// a map to store sum of nodes for each horizontal distance
	map < int, int> Map;
	map < int, int> :: iterator it;

	// populate the map
	verticalSumUtil(root, 0, Map);

	// Prints the values stored by VerticalSumUtil()
	for (it = Map.begin(); it != Map.end(); ++it)
	{
		cout << it->first << ": "
			<< it->second << endl;
	}
}

int main()
{
	// Create binary tree as shown in above figure
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);

	cout << "Following are the values of vertical sums with the positions of the columns with respect to root\n";
	verticalSum(root);

	return 0;
}

/*
This C++ program calculates the vertical sum of a binary tree. It uses a recursive approach to traverse the tree in an in-order fashion
while maintaining a map called Map to store the sum of nodes for each horizontal distance from the root. The verticalSumUtil function updates
the Map while traversing the tree. The verticalSum function prints the vertical sum values along with their corresponding horizontal distance.

The main function creates a sample binary tree and calls the verticalSum function to calculate and display the vertical sums for each column
position with respect to the root.

*/

