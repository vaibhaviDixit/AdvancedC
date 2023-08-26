/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
The lowest common ancestor is defined between two nodes p and q as the lowest node in the tree that has both p and q as descendants.

Input:
       3
      / \
     5   1
    / \ / \
   6  2 0  8
     / \
    7   4

p=5 q=1

Output:
Lowest Common Ancestor of nodes 5 and 1 is 3

Input:
     3
      / \
     5   1
    / \ / \
   6  2 0  8
     / \
    7   4

p=7 q=4

Output: Lowest Common Ancestor of nodes 7 and 4 is 2

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return (left != NULL) ? left : right;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left->right->left;
    TreeNode* q = root->left->right->right;

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of nodes " << p->val << " and " << q->val << " is " << lca->val << endl;

    return 0;
}

/*
This program finds the lowest common ancestor (LCA) of two given nodes in a binary tree. It uses a recursive approach to traverse the tree
and check for the presence of the nodes p and q. The LCA is the first node where both nodes p and q are found in separate subtrees.

*/

