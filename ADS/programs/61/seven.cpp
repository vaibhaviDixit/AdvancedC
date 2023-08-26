/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted then inversion count is 0. If the array is sorted in reverse order that inversion count is the maximum.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
For simplicity, we may assume that all elements are unique.
So, our task is to count the number of inversions in the array. That is the number of pair of elements (a[i], a[j]) such that:
a[i] > a[j] and, i < j.

Input: arr[] = {8, 4, 2, 1}
Output: 6

Input: arr[] = { 1, 20, 6, 4, 5 }
Output: 5

*/

#include <iostream>
using namespace std;

// Structure of the node
struct Node {
	int count;
	Node* left;
	Node* right;
};

// function to initialize new node
Node* makeNewNode()
{
	Node* temp = new Node;
	temp->count = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Insert element in trie
void insertElement(int num,
				Node* root,
				int& ans)
{
	// Converting the number into binary form
	for (int i = 63; i >= 0; i--) {
		// Checking if the i-th bit ios set or not
		int a = (num & (1 << i));

		// If the bit is 1
		if (a != 0) {
			// if the bit is 1 that means we have to go to the right but we also checks if left pointer exists i.e there is
			// at least a number smaller than the current number already in the trie we add that count to ans
			if (root->left != NULL)
				ans += root->left->count;

			// If right pointer is not NULL we just iterate to that position and increment the count
			if (root->right != NULL) {
				root = root->right;
				root->count += 1;
			}

			// If right is NULL we add a new node over there and initialize the count with 1
			else {
				Node* temp = makeNewNode();
				root->right = temp;
				root = root->right;
			}
		}

		// if the bit is 0
		else {
			// We have to iterate to left, we first check if left
			// exists? if yes then change the root and the count
			if (root->left != NULL) {
				root = root->left;
				root->count++;
			}

			// otherwise we create the left node
			else {
				Node* temp = makeNewNode();
				root->left = temp;
				root = root->left;
			}
		}
	}
}

// function to count the inversions
int getInvCount(int arr[], int n)
{
	Node* head = makeNewNode();
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		// inserting each element in Trie
		insertElement(arr[i],
					head,
					ans);
	}

	return ans;
}

int main()
{
	int arr[] = { 8, 4, 2, 1 };
	int n = sizeof(arr) / sizeof(int);

	cout << "Number of inversions are : "
		<< getInvCount(arr, n);
	return 0;
}

/*

Node Structure: This structure represents a node in the Trie. It includes an integer count to store the number of elements in the subtree rooted at this node, and pointers to the left and right child nodes.

Make New Node Function: The makeNewNode function creates and initializes a new Trie node.

Insert Element Function: The insertElement function inserts an element into the Trie and updates the inversion count. It traverses the binary representation of the number and, based on the bits, traverses the Trie to either the left or right child. While doing so, it counts the number of elements in the subtree rooted at the current node's left child. This count is then added to the inversion count when a '1' bit is encountered.

Get Inversion Count Function: The getInvCount function calculates the total number of inversions in the array using the Trie. It iterates through the array in reverse order and inserts each element into the Trie using the insertElement function. The total inversion count is accumulated during this process.

Main Function: In the main function:

An array arr is defined.
The getInvCount function is called to calculate and print the number of inversions in the array.

*/


