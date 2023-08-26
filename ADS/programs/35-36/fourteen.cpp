/*
Create a binary search tree and find the greatest number in the binary search tree that is less than or equal to number N .

Input: BST= 5 2 12 1 3 9 21 19 25
       N= 24
Output: 21

Input: BST= 5 2 12 1 3 9 21 19 25
       N= 12
Output: 12

*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->key = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

int findMaxForN(Node* root,int N);

int main()
{
		string s;
		getline(cin >> ws, s);
		int x;
		cin >> x;

		Node* root = buildTree(s);
		cout << findMaxForN(root, x) << endl;

	return 1;
}


/* 'N' is the element 'size' is the total element in BST */
int findMaxForN(Node* root, int N)
{
    int ans=0;
    while(root!=NULL){
    if(root->key<=N){
        ans=root->key;
        root=root->right;
    }
    else{
        root=root->left;
    }
    }
    return ans;

}


/*
Node Structure: The program defines a struct Node representing a node in the BST. Each node contains an integer key and pointers to its left and right children.

newNode() Function: This utility function creates and returns a new node with the given value. It initializes the node's key, left, and right pointers to NULL.

buildTree() Function: This function constructs a BST using the input string. The input string is split into individual elements using a space delimiter. The function iterates through the input elements and creates nodes for the tree. It follows a level-order (BFS) approach using a queue to link nodes together and build the tree.

findMaxForN() Function: This is the main function that finds the largest node value in the BST that is less than or equal to a given value N. It performs an iterative traversal of the tree and keeps updating the answer while traversing.

*/

