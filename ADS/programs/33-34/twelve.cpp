/*
Given a BST and a sum, find if there is a pair with the given sum.

Input: sum = 28,  BST Inorder=(8,10,12,15,16,20,25)
Output: Pair is found (12, 16)

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* NewNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* root, int key)
{
	if (root == NULL)
		return NewNode(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

bool findpairUtil(Node* root, int sum,
				unordered_set<int>& set)
{
	if (root == NULL)
		return false;

	if (findpairUtil(root->left, sum, set))
		return true;

	if (set.find(sum - root->data) != set.end()) {
		cout << "Pair is found (" << sum - root->data
			<< ", " << root->data << ")" << endl;
		return true;
	}
	else
		set.insert(root->data);

	return findpairUtil(root->right, sum, set);
}

void findPair(Node* root, int sum)
{
	unordered_set<int> set;
	if (!findpairUtil(root, sum, set))
		cout << "Pairs do not exit" << endl;
}

int main()
{
	Node* root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 12);
	root = insert(root, 16);
	root = insert(root, 25);
	root = insert(root, 10);

	int sum = 28;
	findPair(root, sum);

	return 0;
}

/*
The struct Node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The NewNode function creates a new node with the given data and initializes its left and right pointers to NULL.

The insert function inserts a new node with the given data into the BST. It follows the rules of a binary search tree by comparing the value with the current node's data.

The findpairUtil function is a recursive utility function that traverses the BST to find a pair of nodes with the given sum. It uses a hash set (unordered_set) to keep track of visited nodes and searches for the complementary value (sum - root->data) in the hash set. If found, it prints the pair and returns true.

The findPair function is the main function for finding a pair of nodes with the given sum. It initializes an empty hash set and calls the findpairUtil function. If no such pair is found, it prints that the pairs do not exist.

*/



