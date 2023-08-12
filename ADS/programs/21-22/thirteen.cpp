/*
Create a binary tree class called 'BinaryTree' with nodes.
Implement constructors, copy constructor, copy assignment operator, and destructor.

Input:
    BinaryTree tree1;
    tree1.insert(3);
    tree1.insert(2);
    tree1.insert(4);

    BinaryTree tree2 = tree1;

    BinaryTree tree3;
    tree3.insert(1);
    tree3 = tree1;
    tree1.displayInorder();
    tree2.displayInorder();
    tree3.displayInorder();

Output:

Tree1 (Inorder): 2 3 4
Tree2 (Inorder): 2 3 4
Tree3 (Inorder): 2 3 4

*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* copyTree(TreeNode* otherRoot) {
        if (otherRoot == nullptr) {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(otherRoot->data);
        newNode->left = copyTree(otherRoot->left);
        newNode->right = copyTree(otherRoot->right);
        return newNode;
    }

public:
    BinaryTree() : root(nullptr) {}

    BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root);
    }

    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            // Copy Constructor
            BinaryTree temp(other);
            // Swap the data of current object and temp
            swap(root, temp.root);
        }
        return *this;
    }

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            TreeNode* temp = root;
            while (true) {
                if (value < temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    void displayInorder(TreeNode* node) {
        if (node != nullptr) {
            displayInorder(node->left);
            cout << node->data << " ";
            displayInorder(node->right);
        }
    }

    void displayInorder() {
        displayInorder(root);
        cout << endl;
    }

    ~BinaryTree() {
        deleteTree(root);
    }

    void deleteTree(TreeNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree tree1;
    tree1.insert(3);
    tree1.insert(2);
    tree1.insert(4);

    BinaryTree tree2 = tree1; // Copy constructor called

    BinaryTree tree3;
    tree3.insert(1);
    tree3 = tree1; // Copy assignment operator called

    cout << "Tree1 (Inorder): ";
    tree1.displayInorder();

    cout << "Tree2 (Inorder): ";
    tree2.displayInorder();

    cout << "Tree3 (Inorder): ";
    tree3.displayInorder();

    return 0;
}

/*
TreeNode Class:
The TreeNode class represents a node in a binary tree. It has three public attributes: data, which stores the integer value of the node, and left and right, which are pointers to the left and right child nodes, respectively. The constructor of the TreeNode class takes an integer value as its parameter and initializes the data attribute with the provided value. The left and right attributes are initialized to nullptr by default, indicating that the node currently has no left or right child.

BinaryTree Class:
The BinaryTree class represents a binary tree. It has a private attribute root, which is a pointer to the root node of the binary tree. The constructor of the BinaryTree class initializes the root attribute to nullptr, indicating an empty tree.

The BinaryTree class has the following member functions:

copyTree function: This is a private helper function used by the copy constructor and the copy assignment operator to perform a deep copy of the binary tree. It takes a pointer to the root of the other binary tree as its parameter and recursively copies each node and its children. It returns the root of the copied tree.

Copy Constructor: The copy constructor is used to create a new BinaryTree object as a copy of an existing BinaryTree object. It takes a reference to another BinaryTree object (const BinaryTree& other) as its parameter. The copy constructor uses the copyTree function to perform a deep copy of the binary tree, creating a new binary tree with the same structure and values.

Copy Assignment Operator: The copy assignment operator (operator=) allows assignment of one BinaryTree object to another. It takes a reference to another BinaryTree object (const BinaryTree& other) as its parameter. The copy assignment operator first checks whether the two objects are not the same (to avoid self-assignment). Then, it uses the copy constructor to create a temporary BinaryTree object (BinaryTree temp(other)) and swaps the root pointers of the current object and the temporary object using the swap() function. This ensures that the current object gets a deep copy of the binary tree from the temp object, and the temp object gets destroyed with the old binary tree.

insert function: This function is used to insert a new node with the given value into the binary tree. If the tree is empty (root is nullptr), the new node becomes the root. Otherwise, the function traverses the tree based on the value of the nodes to find the appropriate position to insert the new node.

displayInorder function: This function is used to display the elements of the binary tree in inorder traversal order (left-root-right). It performs a recursive inorder traversal starting from the root of the tree.

Destructor: The destructor is responsible for releasing the dynamically allocated memory when the object is destroyed. It calls the deleteTree function to delete all nodes in the binary tree, preventing memory leaks.

deleteTree function: This is a private helper function used by the destructor to delete all nodes in the binary tree. It takes a pointer to the root of the tree and performs a recursive postorder traversal to delete each node and its children.

In the main() function, we demonstrate the use of the BinaryTree class by creating three binary trees (tree1, tree2, and tree3). We insert elements (3, 2, and 4) into tree1 using the insert() function. Then, we create tree2 as a copy of tree1 using the copy constructor. Next, we create tree3 and insert an element (1) into it, and then use the copy assignment operator to assign tree1 to tree3. Finally, we display the elements of all three binary trees using the displayInorder() function.

*/


