/*
Given a Preorder traversal of a Binary Search Tree. The task is to print leaf nodes of the Binary Search Tree from the given preorder.

Input : preorder[] = {890, 325, 290, 530, 965}
Output : 290 530 965

*/

#include<bits/stdc++.h>
using namespace std;

// Binary Search
int binarySearch(int inorder[], int l, int r, int d)
{
	int mid = (l + r)>>1;

	if (inorder[mid] == d)
		return mid;

	else if (inorder[mid] > d)
		return binarySearch(inorder, l, mid - 1, d);

	else
		return binarySearch(inorder, mid + 1, r, d);
}

// Function to print Leaf Nodes by doing preorder traversal of tree using preorder and inorder arrays.
void leafNodesRec(int preorder[], int inorder[],
				int l, int r, int *ind, int n)
{
	// If l == r, therefore no right or left subtree.
	// So, it must be leaf Node, print it.
	if(l == r)
	{
		printf("%d ", inorder[l]);
		*ind = *ind + 1;
		return;
	}

	// If array is out of bound, return.
	if (l < 0 || l > r || r >= n)
		return;

	// Finding the index of preorder element
	// in inorder array using binary search.
	int loc = binarySearch(inorder, l, r, preorder[*ind]);

	// Incrementing the index.
	*ind = *ind + 1;

	// Finding on the left subtree.
	leafNodesRec(preorder, inorder, l, loc - 1, ind, n);

	// Finding on the right subtree.
	leafNodesRec(preorder, inorder, loc + 1, r, ind, n);
}

// Finds leaf nodes from given preorder traversal.
void leafNodes(int preorder[], int n)
{
	int inorder[n]; // To store inorder traversal

	// Copy the preorder into another array.
	for (int i = 0; i < n; i++)
		inorder[i] = preorder[i];

	// Finding the inorder by sorting the array.
	sort(inorder, inorder + n);

	// Point to the index in preorder.
	int ind = 0;

	// Print the Leaf Nodes.
	leafNodesRec(preorder, inorder, 0, n - 1, &ind, n);
}

int main()
{
	int preorder[] = {60,50,90,70};
	int n = sizeof(preorder)/sizeof(preorder[0]);

	leafNodes(preorder, n);
	return 0;
}

/*
binarySearch function: This is a standard binary search algorithm that searches for a given element d in the inorder array within the range [l, r]. It returns the index of the element if found.

leafNodesRec function: This recursive function is used to print the leaf nodes of the BST. It takes the preorder, inorder, range [l, r], the current index ind in the preorder array, and the total number of nodes n as parameters.

If l is equal to r, it means a leaf node has been reached, so it prints the corresponding element from the inorder array and increments the ind index.
If the range boundaries are invalid (out of bounds), it returns without performing any operations.
Otherwise, it finds the index of the current element preorder[ind] in the inorder array using the binarySearch function.
It then recursively calls leafNodesRec for the left subtree ([l, loc - 1]) and the right subtree ([loc + 1, r]).
leafNodes function: This function prepares for the recursive leaf node printing process.

It creates a copy of the preorder array named inorder and sorts it to get the inorder traversal.
It initializes an index ind to keep track of the current element in the preorder array.
It calls leafNodesRec with initial parameters to start printing leaf nodes.

*/




