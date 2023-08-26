/*

Write a CPP program to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Input:
        1
       / \
      2   3
       \
        4
         \
          5
           \
            6

Output: 2 1 3 6

*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to print the top view of a binary tree
void topView(Node* root) {
    if (!root)
        return;

    map<int, int> verticalMap; // Map to store vertical level and node data

    queue<pair<Node*, int>> q; // Queue for BFS traversal
    q.push({root, 0});

    while (!q.empty()) {
        Node* node = q.front().first;
        int verticalLevel = q.front().second;
        q.pop();

        // Insert the node's data if not present in the map
        if (verticalMap.find(verticalLevel) == verticalMap.end()) {
            verticalMap[verticalLevel] = node->data;
        }

        // Push left child with decreased vertical level
        if (node->left) {
            q.push({node->left, verticalLevel - 1});
        }

        // Push right child with increased vertical level
        if (node->right) {
            q.push({node->right, verticalLevel + 1});
        }
    }

    // Print the nodes in the top view
    for (const auto& entry : verticalMap) {
        cout << entry.second << " ";
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(60);
    root->left->left = new Node(40);
    root->right->left = new Node(90);
    root->right->right = new Node(100);
    cout << "Top view of the binary tree: ";
    topView(root);

    return 0;
}

/*
The program defines a structure Node to represent a node in the binary tree. Each node has an integer data value and pointers to its left and right children.

The topView() function is responsible for printing the top view of the binary tree. It uses a map (verticalMap) to store the nodes at each vertical level. The vertical level of a node is tracked during BFS traversal.

The program uses a queue to perform a level-order (BFS) traversal of the binary tree. At each node, it updates the verticalMap with the first encountered node's data at each vertical level.

Nodes are pushed into the queue along with their corresponding vertical levels. For the left child, the vertical level is decreased by 1, and for the right child, the vertical level is increased by 1.

Finally, the verticalMap is iterated, and the data of nodes at each vertical level are printed. This ensures that the top view nodes are printed in the correct order.

*/



