/*
 Write a C++ program to construct all unique BSTs for keys from 1 to n.

Input: n=3
Output:
Preorder traversals of all constructed BSTs are
1 2 3
1 3 2
2 1 3
3 1 2
3 2 1

*/

#include <bits/stdc++.h>
using namespace std;

// node structure
struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = new node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

// function for constructing trees
vector<struct node *> constructTrees(int start, int end)
{
	vector<struct node *> list;

	/* if start > end then subtree will be empty so returning NULL
		in the list */
	if (start > end)
	{
		list.push_back(NULL);
		return list;
	}

	/* iterating through all values from start to end for constructing\
		left and right subtree recursively */
	for (int i = start; i <= end; i++)
	{
		/* constructing left subtree */
		vector<struct node *> leftSubtree = constructTrees(start, i - 1);

		/* constructing right subtree */
		vector<struct node *> rightSubtree = constructTrees(i + 1, end);

		/* now looping through all left and right subtrees and connecting
			them to ith root below */
		for (int j = 0; j < leftSubtree.size(); j++)
		{
			struct node* left = leftSubtree[j];
			for (int k = 0; k < rightSubtree.size(); k++)
			{
				struct node * right = rightSubtree[k];
				struct node * node = newNode(i);// making value i as root
				node->left = left;			 // connect left subtree
				node->right = right;		 // connect right subtree
				list.push_back(node);		 // add this tree to list
			}
		}
	}
	return list;
}

int main()
{
	// Construct all possible BSTs
	vector<struct node *> totalTreesFrom1toN = constructTrees(1, 3);


	/* Printing preorder traversal of all constructed BSTs */
	cout << "Preorder traversals of all constructed BSTs are \n";
	for (int i = 0; i < totalTreesFrom1toN.size(); i++)
	{
		preorder(totalTreesFrom1toN[i]);
		cout << endl;
	}
	return 0;
}

/*
The struct node defines the structure of a binary tree node. Each node contains an integer value (key) and pointers to its left and right children (left and right).

The newNode function creates a new node with the given item and returns a pointer to it.

The preorder function performs a preorder traversal of the tree and prints the node keys.

The constructTrees function constructs all possible BSTs with keys from start to end (inclusive) and returns a vector of pointers to the root nodes of these trees. It uses a recursive approach to generate all combinations of left and right subtrees.

Inside the constructTrees function, if start > end, it returns a vector containing a NULL pointer, indicating an empty subtree.

The function iterates through each value i from start to end, considering it as a root node.

It recursively constructs all possible left subtrees using the constructTrees function with a range from start to i - 1.
It recursively constructs all possible right subtrees using the constructTrees function with a range from i + 1 to end.
It then creates combinations of all possible left and right subtrees with the current i as the root, forming multiple BSTs.
These BSTs are added to the list.

*/


