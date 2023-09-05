/*
Given a binary tree and a target K, the task is to find the diameter of the minimum subtree having sum equal to K which is also a binary search tree.
Return -1 if not possible.

Input: K = 38
          13
        /    \
      5       23
     / \      / \
 N  17   N   N
     /   \
  16   N
Output: 3
Explanation: 5, 17, 16 is the smallest subtree with diameter 3.

Input: K = 73
            7
          /   \
       N     23
            /     \
         10      23
        /  \     / \
   N   17   N   N
Output: -1

*/


#include <bits/stdc++.h>
using namespace std;

// Structure of node of tree
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int num)
	{
		data = num;
		left = NULL;
		right = NULL;
	}
};
int target, ans;

// Hash Tables to store Minimum value, Maximum Value, diameter of subtree and sum of elements of subtree
unordered_map<Node *, int> minv, maxv, h, sum;

// Function to check if the tree is a BST or not
bool isBST(Node* root)
{
	// Base condition
	if (root == NULL)
		return true;
	if (root->left == NULL
		and root->right == NULL) {
		minv[root] = root->data;
		maxv[root] = root->data;
		h[root] = 1;
		sum[root] = root->data;
		if (sum[root] == target)
			ans = min(ans, h[root]);
		return true;
	}

	// Condition for Binary tree to be a BST
	if (root->left == NULL) {
		if (isBST(root->right)
			and minv[root->right] > root->data) {
			minv[root] = root->data;
			maxv[root] = maxv[root->right];
			h[root] = h[root->right] + 1;
			sum[root] = sum[root->right] + root->data;
			if (sum[root] == target)
				ans = min(ans, h[root]);
			return true;
		}
		return false;
	}
	if (root->right == NULL) {
		if (isBST(root->left)
			and maxv[root->left] < root->data) {
			minv[root] = minv[root->left];
			maxv[root] = root->data;
			h[root] = h[root->left] + 1;
			sum[root] = sum[root->left] + root->data;
			if (sum[root] == target)
				ans = min(ans, h[root]);
			return true;
		}
		return false;
	}
	bool bstleft = isBST(root->left);
	bool bstright = isBST(root->right);
	if (bstleft and bstright
		and maxv[root->left] < root->data
		and minv[root->right] > root->data) {
		minv[root] = minv[root->left];
		maxv[root] = maxv[root->right];
		h[root] = 1 + h[root->left] + h[root->right];
		sum[root] = root->data + sum[root->left]
					+ sum[root->right];
		if (sum[root] == target)
			ans = min(ans, h[root]);
		return true;
	}
	return false;
}

// Function to find the desired subtree
int minSubtreeSumBST(int k, Node* root)
{
	// Initialize answer as infinity(INT_MAX)
	ans = INT_MAX;
	target = k;

	// check for BST using DFS traversal
	isBST(root);
	if (ans == INT_MAX)
		return -1;
	return ans;
}

int main()
{
	int k = 38;

	// Defining tree
	Node* root = new Node(13);
	root->left = new Node(5);
	root->right = new Node(23);
	root->left->right = new Node(17);
	root->left->right->left = new Node(16);

	// Function call
	int res = minSubtreeSumBST(k, root);
	cout << res << endl;
	return 0;
}


/*
A Node structure is defined to represent the nodes of the binary tree. It contains data, left, and right pointers.

Global variables target and ans are declared. target will store the given target sum, and ans will store the minimum height of the subtree.

Four unordered maps (minv, maxv, h, and sum) are declared to store information about each node's subtree:

minv: Minimum value in the subtree rooted at a node.
maxv: Maximum value in the subtree rooted at a node.
h: Height of the subtree rooted at a node.
sum: Sum of elements in the subtree rooted at a node.
The isBST function checks whether the given binary tree is a Binary Search Tree (BST) or not, while calculating information about each node's subtree:

Base case: If a node is a leaf node, its properties are initialized, and if its sum equals the target, ans is updated with the minimum height.
Conditions for a BST: If a node has no left child or right child, the BST condition is checked for the remaining subtree.
In the case of a node with both left and right children, the BST condition is checked, and information about the subtree is updated.
The minSubtreeSumBST function finds the minimum height of a subtree with a sum equal to the target:

Initialize ans with a large value (INT_MAX).
Set target to the given value.
Call the isBST function to check if the tree is a BST and calculate subtree information.
If ans remains INT_MAX, return -1 (indicating no valid subtree found). Otherwise, return the minimum height

*/
