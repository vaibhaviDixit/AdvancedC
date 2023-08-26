/*
Given preorder of a binary tree, calculate its depth(or height) [starting from depth 0]. The preorder is given as a string with two possible
characters.

‘l’ denotes the leaf
‘n’ denotes internal node
The given tree can be seen as a full binary tree where every node has 0 or two children. The two children of a node can ‘n’ or ‘l’ or mix of both.

Input  : nlnll
Output : 2

*/

// C++ program to find height of full binary tree using preorder
#include <bits/stdc++.h>
using namespace std;

// function to return max of left subtree height
// or right subtree height
int findDepthRec(char tree[], int n, int& index)
{
	if (index >= n || tree[index] == 'l')
		return 0;

	// calc height of left subtree (In preorder
	// left subtree is processed before right)
	index++;
	int left = findDepthRec(tree, n, index);

	// calc height of right subtree
	index++;
	int right = findDepthRec(tree, n, index);

	return max(left, right) + 1;
}

// Wrapper over findDepthRec()
int findDepth(char tree[], int n)
{
	int index = 0;
	return findDepthRec(tree, n, index);
}


int main()
{
	char tree[] = "nlnnlll";
	int n = strlen(tree);

	cout << findDepth(tree, n) << endl;

	return 0;
}

/*
In this program, we define a function findDepthRec that takes the following parameters:

tree[]: An array representing the binary tree in a specific format. Each character in the array can be 'n' (for a non-leaf node) or 'l' (for a leaf node).
n: The length of the tree[] array.
index: A reference to an integer representing the current index in the array.
The function calculates the height of the binary tree rooted at the current index. The algorithm works as follows:

If the current index is out of bounds or the current node is a leaf ('l'), return 0.
Increment the index and recursively calculate the height of the left subtree by calling findDepthRec.
Increment the index again and recursively calculate the height of the right subtree by calling findDepthRec.
Return the maximum of the heights of the left and right subtrees, plus 1 (to account for the current node).
The function findDepth is a wrapper around findDepthRec, which initializes the index parameter and returns the result of findDepthRec.

In the main function:

We declare a character array tree[] representing the binary tree as "nlnnlll".
We calculate the length of the array using strlen(tree).
We call the findDepth function to calculate and print the height of the binary tree.

*/
