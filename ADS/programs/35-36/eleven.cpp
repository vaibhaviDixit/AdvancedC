/*
Given two arrays that represent a sequence of keys. Imagine we make a Binary Search Tree (BST) from each array.
We need to tell whether two BSTs will be identical or not without actually constructing the tree.

Input:
a[] = { 8, 3, 6, 1, 4, 7, 10, 14, 13 }
b[] = { 8, 10, 14, 3, 6, 4, 1, 7, 13 }

Output: BSTs are same

*/

#include <bits/stdc++.h>
using namespace std;

/* The main function that checks if two arrays a[] and b[] of size n construct
same BST. The two values 'min' and 'max' decide whether the call is made for left subtree or right subtree of a parent
element. The indexes i1 and i2 are the indexes in (a[] and b[]) after which we search the left or right child. Initially,
the call is made for INT_MIN and INT_MAX as 'min' and 'max' respectively, because
root has no parent. i1 and i2 are just after the indexes of the parent element in a[] and b[].
*/

bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2,
				int min, int max)
{
	int j, k;

	/* Search for a value satisfying the constraints of min and max in a[] and b[]. If the parent element is a leaf
	node then there must be some elements in a[] and b[] satisfying constraint. */
	for (j = i1; j < n; j++)
		if (a[j] > min && a[j] < max)
			break;
	for (k = i2; k < n; k++)
		if (b[k] > min && b[k] < max)
			break;

	/* If the parent element is leaf in both arrays */
	if (j == n && k == n)
		return true;

	/* Return false if any of the following is true
		a) If the parent element is leaf in one array,
			but non-leaf in other.
		b) The elements satisfying constraints are
			not same. We either search for left
			child or right child of the parent
			element (decided by min and max values).
			The child found must be same in both arrays */
	if (((j == n) ^ (k == n)) || a[j] != b[k])
		return false;


	return isSameBSTUtil(a, b, n, j + 1, k + 1, a[j], max)&& isSameBSTUtil(a, b, n, j + 1, k + 1, min,a[j]);
}

// A wrapper over isSameBSTUtil()
bool isSameBST(int a[], int b[], int n)
{
	return isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX);
}

int main()
{
	int a[] = { 8, 3, 6, 1, 4, 7, 10, 14, 13 };
	int b[] = { 8, 10, 14, 3, 6, 4, 1, 7, 13 };
	int n = sizeof(a) / sizeof(a[0]);
	if (isSameBST(a, b, n)) {
		cout << "BSTs are same";
	}
	else {
		cout << "BSTs not same";
	}
	return 0;
}

/*
isSameBSTUtil() Function: This is the main recursive function that checks if the two arrays can construct the same BST. It takes the two arrays a[] and b[], the size n, two indexes i1 and i2 (to track the current positions in arrays a[] and b[]), and the minimum (min) and maximum (max) constraints for constructing the current subtree.

The function starts by searching for the next valid element in both a[] and b[] arrays that satisfy the constraints within the range [min, max].

If both arrays have reached the end (j == n and k == n), it means the current subtree's parent element is a leaf node, and this subtree is valid. It returns true.

If only one array has reached the end or the values at the current positions in both arrays do not match, it means the arrays cannot construct the same BST. It returns false.

If the above conditions are not met, it checks whether the subtrees on the left and right branches of the parent element can construct the same BST. It makes two recursive calls with modified constraints for the left and right subtrees.

isSameBST() Function: This function is a wrapper over isSameBSTUtil(). It initializes the initial call to isSameBSTUtil() with the root of the BST, represented by index 0 for both arrays. It also sets the initial constraints as negative infinity (INT_MIN) and positive infinity (INT_MAX).

*/


