/*An AVL tree is a self-balancing binary search tree where the difference in heights of left and right subtrees of any node is at most 1. It maintains balance by performing rotations during insertion and deletion.*/
/*AVL Tree:
An AVL tree is a self-balancing binary search tree. The main property of the AVL tree is that the difference in heights between the left and right subtrees of any node (called the balance factor) is at most 1. If the balance factor becomes greater than 1 or less than -1 after an insertion or deletion, the tree is rebalanced using rotations (left or right).

Why AVL?
The AVL tree was the first self-balancing binary search tree and is an important data structure in computer science, especially for applications where fast search, insert, and delete operations are needed.*/
/*
Approach:
Insertion: Insert a node like in a regular binary search tree, but after each insertion, check the balance factor of the nodes and perform rotations if necessary.

Rotation: There are four types of rotations:

Left Rotation (LL Rotation)
Right Rotation (RR Rotation)
Left-Right Rotation (LR Rotation)
Right-Left Rotation (RL Rotation)
Deletion: After deletion, re-balance the tree by checking balance factors and performing rotations if necessary.
*/
#include <iostream>
#include <algorithm>
using namespace std;

// AVL Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;  // Height of the node

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Utility function to get the height of a node
int getHeight(TreeNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Utility function to get the balance factor of a node
int getBalance(TreeNode* node) {
    return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right rotation (for LL case)
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation (for RR case)
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert a node into the AVL tree
TreeNode* insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    // Perform the normal BST insertion
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node; // No duplicates allowed
    }

    // Update height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor to check if the node is unbalanced
    int balance = getBalance(node);

    // If the node becomes unbalanced, then there are 4 cases

    // Left Left Case (Right rotation)
    if (balance > 1 && value < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case (Left rotation)
    if (balance < -1 && value > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case (Left rotation on left child, then right rotation)
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (Right rotation on right child, then left rotation)
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Utility function to print the tree in Inorder traversal
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function
int main() {
    TreeNode* root = nullptr;

    // Inserting nodes into the AVL tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 3);

    cout << "Inorder traversal of the AVL tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
