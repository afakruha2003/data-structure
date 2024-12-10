#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the binary tree (same as previous insert)
TreeNode* insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Function to perform inorder traversal (for printing the tree)
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Function to create the mirror image of the binary tree
TreeNode* mirror(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Recursively mirror the left and right subtrees
    TreeNode* left = mirror(root->left);
    TreeNode* right = mirror(root->right);

    // Swap the left and right children
    root->left = right;
    root->right = left;

    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Insert nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Original tree (Inorder traversal): ";
    inorder(root);
    cout << endl;

    // Create a mirror image of the tree
    root = mirror(root);

    cout << "Mirrored tree (Inorder traversal): ";
    inorder(root);
    cout << endl;

    return 0;
}
