/*
Perform an inorder traversal of a binary tree without using recursion.

Input:
      1
     / \
    2   3
   / \
  4   5

Output: Inorder Traversal: 4 2 5 1 3

*/

#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> st;
    TreeNode* current = root;
    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->val << " ";
        current = current->right;
    }
}

int main() {
    // Construct a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}

/*
This program demonstrates how to perform an inorder traversal of a binary tree without using recursion. It uses a stack data structure to
simulate the call stack used in a recursive approach. The idea is to start from the root, push nodes onto the stack as long as there is a
left child, and then pop nodes from the stack while processing them and moving to the right subtree. This allows for an iterative and space-efficient
solution to the classic tree traversal problem.

*/
