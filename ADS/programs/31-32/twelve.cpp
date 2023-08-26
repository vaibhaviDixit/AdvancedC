/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Input:
     2
    / \
    1  3
Output: The given tree is a valid BST.

Input:
     0
    / \
    1  3

Output: The given tree is not a valid BST.

*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == NULL) return true;
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
            return false;
        }
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    if (sol.isValidBST(root)) {
        cout << "The given tree is a valid BST." << endl;
    } else {
        cout << "The given tree is not a valid BST." << endl;
    }

    return 0;
}

/*
This program checks whether a given binary tree is a valid binary search tree (BST) or not. It uses the concept of ranges for each node.
A node's value should be within the range defined by its parent nodes. If the node's value is not within this range, it's not a valid BST.
The program performs a recursive check on each node's left and right subtrees while updating the ranges accordingly.

*/


