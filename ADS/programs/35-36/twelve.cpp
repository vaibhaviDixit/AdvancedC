/*
Create a BST and find Ceil of number X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.
If Ceil could not be found, return -1.

Input: nodes= 5 1 7 2 3
       X = 3
Output: 3


Input: nodes= 5 1 7 2 3
       X = 6
Output: 7

*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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

int findCeil(Node* root, int input);

int main() {

        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;
        Node* root = buildTree(s);
        cout << findCeil(root, x) << endl;

    return 1;
}

// Function to return the ceil of given number in BST.
void in(Node *root,vector<int>&v){
    if(!root)return;
    in(root->left,v);
    v.push_back(root->data);
    in(root->right,v);
}
int findCeil(Node* root, int input) {
    vector<int>v;
    in(root,v);
    if(v[v.size()-1]<input)return -1;
    else{
        return *lower_bound(v.begin(),v.end(),input);
    }
}

/*
Node Structure: A struct Node is defined to represent a node in the Binary Search Tree. Each node contains an integer data and pointers to its left and right children.

newNode() Function: This is a utility function that creates a new node with the given value, initializes its left and right pointers to NULL, and returns the created node.

buildTree() Function: This function takes a string input and constructs a Binary Search Tree based on the given input. The input string represents the tree in level order, where each node is represented by its value, and "N" represents a null node. The function parses the string and builds the tree using a queue for level order traversal.

findCeil() Function: This is the main function responsible for finding the ceiling of a given number in the BST. It takes the root of the tree and the input number as arguments. The function first performs an in-order traversal of the tree and stores the elements in a vector v. Then, it checks if the largest element in the tree (last element of the vector) is less than the input number. If so, it returns -1, indicating that there is no ceiling. Otherwise, it uses the lower_bound() function to find the smallest element in the vector that is greater than or equal to the input number, which represents the ceiling.

*/


