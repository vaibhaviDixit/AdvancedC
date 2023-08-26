/*
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree.
It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis
contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

Input : "1(2)(3)"
Output : 1 2 3

Input: "4(2(3)(1))(6(5))"
Output: 4 2 3 1 6 5

*/


#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
	if (si > ei)
		return -1;

	// Inbuilt stack
	stack<char> s;

	for (int i = si; i <= ei; i++) {

		// if open parenthesis, push it
		if (str[i] == '(')
			s.push(str[i]);

		// if close parenthesis
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();

				// if stack is empty, this is
				// the required index
				if (s.empty())
					return i;
			}
		}
	}
	// if not found return -1
	return -1;
}

// function to construct tree from string
Node* treeFromString(string str, int si, int ei)
{
	// Base case
	if (si > ei)
		return NULL;


	int num = 0;
	// In case the number is having more than 1 digit
	while(si <= ei && str[si] >= '0' && str[si] <= '9')
	{
	num *= 10;
	num += (str[si] - '0');
	si++;
	}

	// new root
	Node* root = newNode(num);
	int index = -1;

	// if next char is '(' find the index of
	// its complement ')'
	if (si <= ei && str[si] == '(')
		index = findIndex(str, si, ei);

	// if index found
	if (index != -1) {

		// call for left subtree
		root->left = treeFromString(str, si + 1, index - 1);

		// call for right subtree
		root->right
			= treeFromString(str, index + 2, ei - 1);
	}
	return root;
}

int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str, 0, str.length() - 1);
	preOrder(root);

	return 0;
}



/*
Node Structure: The program defines a Node structure representing nodes of a binary tree. Each node has a data value, and pointers to its left and right children.

newNode Function: This utility function creates a new node with the given data value and initializes its pointers to NULL.

preOrder Function: This function performs a preorder traversal of the binary tree and prints the values of the nodes.

findIndex Function: This utility function returns the index of the closing parenthesis corresponding to an opening parenthesis in the given string. It uses a stack to keep track of opening and closing parentheses.

treeFromString Function: This function constructs the binary tree from the parenthesized string. It takes the string, starting index, and ending index as parameters.

It processes the string from the start index to the end index.
If it encounters a digit, it extracts the number and creates a new node with that number.
If there is an opening parenthesis after the number, it finds the index of its corresponding closing parenthesis using the findIndex function.
It then recursively calls itself to construct the left and right subtrees based on the positions of the parentheses.
main Function: The main function initializes the string str representing the parenthesized string representation of the binary tree.

It calls the treeFromString function to construct the binary tree.
Finally, it calls the preOrder function to perform a preorder traversal of the constructed binary tree and prints the values of the nodes.

*/
