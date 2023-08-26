/*
Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not
make any change.

Input:  Original BST: 2 3 4 5 7 8 9
        Enter node value to delete: 7

Output: BST after deleting 7: 2 3 4 5 8 9

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a new value into the BST
Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);   // Insert into the left subtree
    } else if (val > root->data) {
        root->right = insert(root->right, val); // Insert into the right subtree
    }
    return root;
}

// Function to find the node with the minimum value in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a given value from the BST
Node* deleteNode(Node* root, int val) {
    if (!root) {
        return root;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);   // Delete from the left subtree
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val); // Delete from the right subtree
    } else {
        if (!root->left) {
            Node* temp = root->right;  // No left child, replace with right child
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;   // No right child, replace with left child
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);  // Node has two children, find successor
        root->data = temp->data;  // Copy successor's value to this node
        root->right = deleteNode(root->right, temp->data); // Delete successor node
    }
    return root;
}

// Function to perform an inorder traversal of the BST
void inorder(Node* root) {
    if (root) {
        inorder(root->left);         // Traverse left subtree
        cout << root->data << " ";   // Print current node's value
        inorder(root->right);        // Traverse right subtree
    }
}

int main() {
    Node* root = NULL;
    int keys[] = {5, 3, 8, 2, 4, 7, 9};

    // Insert keys into the BST
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "Original BST: ";
    inorder(root);  // Print the original BST in sorted order
    cout << endl;

    int x;
    cout << "Enter node value to delete: ";
    cin >> x;

    root = deleteNode(root, x);  // Delete the node with the given value

    cout << "BST after deleting " << x << ": ";
    inorder(root);  // Print the modified BST after deletion
    cout << endl;

    return 0;
}

/*
The program starts by defining the Node structure, which represents a node in the BST. Each node contains an integer data value, and pointers to its left and right children.

The insert() function is defined to insert a new value into the BST while maintaining the BST properties. It recursively traverses the tree to find the appropriate position to insert the new node.

The minValueNode() function is defined to find the node with the minimum value in a given subtree. It starts from the given node and traverses left until it reaches the leftmost node.

The deleteNode() function is defined to delete a node with a given value from the BST. It handles three cases:

If the node has no children or only one child, the node is deleted, and its child (if any) is linked directly to its parent.
If the node has two children, it finds the node with the minimum value in the right subtree (the node's "successor") and replaces the node's value with the successor's value. Then it recursively deletes the successor node.
The inorder() function performs an inorder traversal of the BST and prints the elements in sorted order.

*/

