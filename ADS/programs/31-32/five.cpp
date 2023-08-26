/*
You are given a binary tree and a given sum. The task is to check if there exists a subtree whose sum of all nodes is equal to the given sum.

Input :
         5
    	/ \
    	4	8
       /   / \
       11  13 4
      / \	 \
      7 2	 1

sum = 22
Output: Yes


*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

bool hasTargetSum(TreeNode* root, int targetSum)
{
    unordered_map<int, int> mp;
    mp[0] = 1; // adding a dummy sum to handle the case where root itself has the target sum
    int sum = 0;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* curr = st.top();
        st.pop();
        sum += curr->val;
        if (mp.find(sum - targetSum) != mp.end())
        {
            return true;
        }
        mp[sum] = 1;
        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
    return false;
}

int main()
{
    /*
    	5
    	/ \
    	4	8
       /   / \
       11  13 4
      / \	 \
      7 2	 1

    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    if (hasTargetSum(root, targetSum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

/*
Function to Check for Target Sum Path (hasTargetSum): This function takes the root of a binary tree and a target sum as inputs.
It uses a hash map mp to store cumulative sums encountered during traversal. The map is initialized with a dummy entry {0, 1} to handle the
case where the root itself has the target sum. The variable sum is used to keep track of the cumulative sum. A stack is used to perform iterative
depth-first traversal of the tree. The function iterates through the tree nodes and updates the cumulative sum. It checks whether the current
cumulative sum minus the target sum exists in the hash map mp. If it does, the function returns true, indicating that a path with the target
sum has been found. The cumulative sum is added to the hash map. If the node has a right child, it's pushed onto the stack before the left child.
This ensures that left subtree exploration is done before right subtree exploration. The function returns false if no path with the target sum is
found.

*/



