/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input: x = 10, y = 2
         6
		/ \
	   10   2
	  / \  / \
	  1 3  7  12

Output:
Inorder Traversal of the original tree: 1 10 3 6 7 2 12
Inorder Traversal of the fixed tree: 1 2 3 6 7 10 12

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

Node* newNode(int data){
	return new Node(data);
}

void storeInVector(Node* root, vector<int>&vec){
	if(root == NULL) return;
	storeInVector(root->left, vec);
	vec.push_back(root->data);
	storeInVector(root->right, vec);
}

void correctBSTUtil(Node* root, vector<int> &vec, int &index){
	if(root == NULL) return;
	correctBSTUtil(root->left, vec, index);
	root->data = vec[index];
	index++;
	correctBSTUtil(root->right, vec, index);
}

void correctBST(Node* root){
	// vector to store the inorder traversal of given tree
	vector<int> vec;
	storeInVector(root, vec);
	sort(vec.begin(), vec.end());
	int index = 0;
	correctBSTUtil(root, vec, index);
}

void printInorder(Node* root){
	if(root == NULL) return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main(){
	/*   6
		/ \
	   10   2
	  / \  / \
	  1 3  7  12

	10 and 2 are swapped */
	struct Node *root = newNode(6);
	root->left = newNode(10);
	root->right = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);

	// Inorder traversal of the Original Tree
	cout <<"Inorder Traversal of the original tree \n";
	printInorder(root);

	correctBST(root);

	// inorder traversal of the fixed tree
	cout <<"\nInorder Traversal of the fixed tree \n";
	printInorder(root);

	return 0;
}
/*
The struct Node defines the structure of a binary tree node. Each node contains an integer value (data) and pointers to its left and right children (left and right).

The newNode function creates a new node with the given data and returns a pointer to it.

The storeInVector function performs an inorder traversal of the tree and stores the node values in a vector.

The correctBSTUtil function recursively updates the nodes of the BST using the values from the sorted vector. It traverses the tree in an inorder manner, updating each node's value from the vector and advancing the vector index.

The correctBST function is the main function to correct the BST. It first stores the inorder traversal of the tree in a vector, sorts the vector, and then calls the correctBSTUtil function to update the nodes.

The printInorder function performs an inorder traversal of the tree and prints the node values.

*/

