/*
Implement a C++ program to insert an integer into an AVL tree. Ensure that the AVL tree remains balanced after the insertion.

Input: avltree={10,20,30}

Output:
Inserted: 10, Inorder Traversal: 10
Inserted: 20, Inorder Traversal: 10 20
Inserted: 30, Inorder Traversal: 10 20 30

*/

#include <iostream>

// Define a structure for the AVL tree node
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

// Function to get the height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a key into the AVL tree
Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalance(root);

    // Perform rotations to maintain balance
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to perform an inorder traversal of the AVL tree
void inorderTraversal(Node* root) {
    if (!root)
        return;

    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
}

// Main function
int main() {
    Node* root = nullptr;

    // Insert elements into AVL tree
    int arr[] = {10, 20, 30, 40, 50, 25};
    for (int key : arr) {
        root = insert(root, key);
        std::cout << "Inserted: " << key << ", Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    return 0;
}


/*
This C++ program implements insertion in an AVL tree. The Node struct represents a single node in the AVL tree, and each node contains a key (an integer value), height (used to keep track of the balance factor), and pointers to its left and right children.

The getHeight function calculates the height of a node, and the getBalance function calculates the balance factor for a node.

The rotateRight and rotateLeft functions perform right and left rotations, respectively, to rebalance the AVL tree if it becomes unbalanced.

The insert function inserts a new node with the given key into the AVL tree and ensures the tree remains balanced. It recursively inserts the node in the appropriate subtree and performs rotations as needed to balance the tree.

The inorderTraversal function performs an inorder traversal of the AVL tree to print its elements in ascending order.

The main function demonstrates the insertion of elements into the AVL tree and prints the inorder traversal after each insertion.

*/
