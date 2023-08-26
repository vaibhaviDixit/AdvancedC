/*
Given two binary trees, check if the first tree is a subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all
of its descendants in T.The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a
proper subtree.

Input:
        Tree1
          x
        /    \
      a       b
       \
        c

        Tree2
              z
            /   \
          x      e
        /    \     \
      a       b      k
       \
        c

Output: No: S is NOT a subtree of T

*/

#include <cstring>
#include <iostream>
using namespace std;
#define MAX 100

// Structure of a tree node
struct Node {
	char key;
	struct Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(char item)
{
	Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to store inorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storeInorder(Node* root, char arr[], int& i)
{
	if (root == NULL) {
		arr[i++] = '$';
		return;
	}
	storeInorder(root->left, arr, i);
	arr[i++] = root->key;
	storeInorder(root->right, arr, i);
}

// A utility function to store preorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storePreOrder(Node* root, char arr[], int& i)
{
	if (root == NULL) {
		arr[i++] = '$';
		return;
	}
	arr[i++] = root->key;
	storePreOrder(root->left, arr, i);
	storePreOrder(root->right, arr, i);
}

/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S)
{
	/* base cases */
	if (S == NULL)
		return true;
	if (T == NULL)
		return false;

	// Store Inorder traversals of T and S in inT[0..m-1]
	// and inS[0..n-1] respectively
	int m = 0, n = 0;
	char inT[MAX], inS[MAX];
	storeInorder(T, inT, m);
	storeInorder(S, inS, n);
	inT[m] = '\0', inS[n] = '\0';

	// If inS[] is not a substring of inT[], return false
	if (strstr(inT, inS) == NULL)
		return false;

	// Store Preorder traversals of T and S in preT[0..m-1]
	// and preS[0..n-1] respectively
	m = 0, n = 0;
	char preT[MAX], preS[MAX];
	storePreOrder(T, preT, m);
	storePreOrder(S, preS, n);
	preT[m] = '\0', preS[n] = '\0';

	// If preS[] is not a substring of preT[], return false Else return true
	return (strstr(preT, preS) != NULL);
}

int main()
{
	Node* T = newNode('a');
	T->left = newNode('b');
	T->right = newNode('d');
	T->left->left = newNode('c');
	T->right->right = newNode('e');

	Node* S = newNode('a');
	S->left = newNode('b');
	S->left->left = newNode('c');
	S->right = newNode('d');

	if (isSubtree(T, S))
		cout << "Yes: S is a subtree of T";
	else
		cout << "No: S is NOT a subtree of T";

	return 0;
}

/*
Node Structure: The program defines a structure Node to represent a node in a binary tree. Each node has a key (character data), and pointers to its left and right children.

newNode Function: This function is used to create a new node with the given character item. It allocates memory for the node, sets its data and initializes its left and right pointers to NULL.

storeInorder Function: This function takes a binary tree's root node, an array arr, and an integer reference i. It recursively traverses the tree in inorder and stores the characters in the arr array. When a NULL node is encountered, the special character '$' is stored in the array. The integer reference i is used to keep track of the index of the array where characters are stored.

storePreOrder Function: Similar to the storeInorder function, this function traverses the tree in preorder and stores characters in the given array.

isSubtree Function: This function takes two parameters, the root nodes of trees T and S. It uses the following logic:

If S is NULL, it is considered a subtree of any tree, so the function returns true.
If T is NULL, it is not a subtree of any tree, so the function returns false.
The storeInorder function is used to store the inorder traversals of both T and S in arrays inT and inS, respectively.
The strstr function is used to check if the inorder traversal of S is a substring of the inorder traversal of T. If not, it returns false.
Similarly, the storePreOrder function is used to store the preorder traversals of both T and S in arrays preT and preS, respectively.
The strstr function is again used to check if the preorder traversal of S is a substring of the preorder traversal of T. If this condition is satisfied, the function returns true.

*/
