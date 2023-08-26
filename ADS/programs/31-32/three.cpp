/*
Write a function to determine if two trees are identical or not:
Two trees are identical when they have the same data and the arrangement of data is also the same

Input:             1                    1
                 /   \                /   \
               2      3            2      3
             /                    /
           4                   4

Output: Both trees are identical

*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node */
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void preorder(Node* root,vector<int>&v)
{
    if(root==NULL)
    {
        // v.push_back(0);
        return;
    }
    v.push_back(root->data);
    if(root->left)
        preorder(root->left,v);
    if(!root->left)
        v.push_back(0);
    if(root->right)
        preorder(root->right,v);
    if(!root->right)
        v.push_back(0);
}

bool isIdentical(Node* root1,Node*root2)
{
    vector<int>v,x;
    preorder(root1,v);
    preorder(root2,x);
    // for(auto it:v)cout<<it<<" ";
    // cout<<endl;
    return v==x;
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    // Function call
    if (isIdentical(root1, root2))
    {
        cout << "Both the trees are identical." << endl;
    }
    else
    {
        cout << "Given trees are not identical." << endl;
    }
}


/*

Node Class Definition: The binary tree node class is defined using the class keyword. It includes an integer data representing the value of the node, and two pointers left and right representing the left and right children of the node. The constructor initializes these attributes.

Preorder Traversal Function (preorder): This function performs a preorder traversal of the binary tree rooted at root. It stores the data of each visited node in a vector v. For nodes without a left child, it inserts a placeholder 0 in the vector.

Identical Trees Function (isIdentical): This function takes two binary tree roots (root1 and root2) as input and checks whether they are identical. It uses the preorder function to collect the node data in vectors v and x for the two trees. It then compares these vectors to determine whether the trees have the same structure and values.

*/

