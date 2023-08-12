/*
Given a binary tree, write an cpp program using hashing to print  right view of binary tree using hashing technique.

Input:

    1
   /  \
  2     3
   \    / \
   4    5  6
       / \
      7  8

Output: 1 3 6 8

*/


#include <iostream>
#include <unordered_map>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Traverse nodes in reverse preorder fashion
void printRightView(Node* root, int level, auto &map)
{
    if (root == nullptr) {
        return;
    }

    // insert the current node and level information into the map
    map[level] = root->key;

    // recur for the left subtree before the right subtree
    printRightView(root->left, level + 1, map);
    printRightView(root->right, level + 1, map);
}

// Function to print the right view of a given binary tree
int printRightView(Node* root)
{
    // create an empty map to store the last node for each level
    unordered_map<int, int> map;

    // traverse the tree and fill the map
    printRightView(root, 1, map);

    // iterate through the map and print the right view
    for (int i = 1; i <= map.size(); i++) {
        cout << map[i] << " ";
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printRightView(root);

    return 0;
}


/*
This program demonstrates the printing of the right view of a binary tree using a hash map. The right view of a binary tree is the set of nodes that are visible when the tree is viewed from the right side, considering the top-down perspective.

The Node struct represents a binary tree node with a key value and pointers to its left and right children.

The printRightView function is used to print the right view of the binary tree. It takes the root of the tree, the current level, and a hash map map as inputs. The function performs a reverse preorder traversal of the tree. During traversal, for each node encountered, it inserts the node's key into the map with the corresponding level as the key. This way, the last node encountered at each level will be stored in the map.

The main printRightView function initializes an empty hash map to store the last node at each level. It then calls the recursive printRightView function to fill the map. Finally, it iterates through the map and prints the keys of the nodes in the right view.

The binary tree is constructed using the Node structure in the main function. The right view of the tree is then printed by calling the printRightView function.

The hash map is utilized to efficiently store the last node at each level, ensuring that only the visible nodes from the right side are included in the right view.

*/

