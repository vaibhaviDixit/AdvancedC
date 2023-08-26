/*
Given a string that contains ternary expressions. The expressions may be nested, task is convert the given ternary expression to a binary Tree.

Input :  string expression =   a?b?c:d:e
Output : preorder traversal: a b c d e

Input :  string expression =   a?b:c
Output : preorder traversal: a b c

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char val;
	Node *left, *right;
	Node(char v) : val(v), left(nullptr), right(nullptr) {}
};

Node* ternaryToTree(string exp) {
	if (exp.empty()) return nullptr;
	Node *root = new Node(exp[0]);
	stack<Node*> st;
	st.push(root);
	for (int i = 1; i < exp.size(); i += 2) {
		Node *cur = st.top(); st.pop();
		if (exp[i] == '?') {
			cur->left = new Node(exp[i+1]);
			st.push(cur);
			st.push(cur->left);
		} else {
			cur->right = new Node(exp[i+1]);
			st.push(cur->right);
		}
	}
	return root;
}

void printTree(Node* root) {
	if (!root) return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	string exp = "a?b?c:d:e";
	Node *root = ternaryToTree(exp);
	printTree(root);
	return 0;
}


/*
Node Class: The program defines a class Node to represent a node in a binary tree. Each node has a char value, and pointers to its left and right children.

Constructor: The constructor of the Node class initializes the node with the given character value and sets its left and right pointers to nullptr.

ternaryToTree Function: This function converts a given ternary expression into a binary tree. It takes the ternary expression as input and returns the root of the resulting binary tree. The function uses a stack to keep track of the nodes being created. It iterates through the characters of the expression. For each character:

If the character is a '?', it creates a left child for the current node, adds the current node back to the stack, and then pushes the left child onto the stack.
If the character is a ':', it creates a right child for the current node.
Otherwise, it creates a new node with the character as its value and assigns it as the current node's left or right child based on the last operation (either creating a left child or right child).
printTree Function: This function performs a preorder traversal of the binary tree and prints the values of the nodes. The order of traversal is root-left-right.

main Function: In the main function, a ternary expression "a?b?c:d:e" is provided. The ternaryToTree function is called with this expression to construct the binary tree. Then, the printTree function is called to print the tree in preorder.

*/
