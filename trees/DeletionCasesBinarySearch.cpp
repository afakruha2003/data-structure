#include <iostream>
using namespace std;

// Structure for a TreeNode in a binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the binary tree (simple insert)
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

// Function to find the minimum value node in a subtree (used for finding the inorder successor)
TreeNode* findMin(TreeNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

// Case 1: Deleting a leaf node
TreeNode* deleteLeafNode(TreeNode* root, int value) {
    if (root == nullptr) return root;

    // Search for the node to delete
    if (value < root->data) {
        root->left = deleteLeafNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteLeafNode(root->right, value);
    } else {
        // Node found, check if it's a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            delete root; // Delete the leaf node
            return nullptr; // Return null to remove the node
        }
    }
    return root;
}

// Case 2: Deleting a node with one child
TreeNode* deleteNodeWithOneChild(TreeNode* root, int value) {
    if (root == nullptr) return root;

    // Search for the node to delete
    if (value < root->data) {
        root->left = deleteNodeWithOneChild(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNodeWithOneChild(root->right, value);
    } else {
        // Node found with one child
        if (root->left == nullptr) {
            TreeNode* temp = root->right; // Right child
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left; // Left child
            delete root;
            return temp;
        }
    }
    return root;
}

// Case 3: Deleting a node with two children
TreeNode* deleteNodeWithTwoChildren(TreeNode* root, int value) {
    if (root == nullptr) return root;

    // Search for the node to delete
    if (value < root->data) {
        root->left = deleteNodeWithTwoChildren(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNodeWithTwoChildren(root->right, value);
    } else {
        // Node found with two children
        if (root->left != nullptr && root->right != nullptr) {
            // Get the inorder successor (smallest node in the right subtree)
            TreeNode* temp = findMin(root->right);
            root->data = temp->data; // Replace the node's value with the inorder successor
            root->right = deleteNodeWithTwoChildren(root->right, temp->data); // Delete the inorder successor
        }
    }
    return root;
}

// Inorder Traversal to print the tree (for testing purposes)
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function to demonstrate all cases
int main() {
    TreeNode* root = nullptr;

    // Inserting nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;

    // Case 1: Deleting a leaf node (20)
    cout << "Deleting leaf node 20" << endl;
    root = deleteLeafNode(root, 20);
    inorder(root);
    cout << endl;

    // Case 2: Deleting a node with one child (30)
    cout << "Deleting node with one child 30" << endl;
    root = deleteNodeWithOneChild(root, 30);
    inorder(root);
    cout << endl;

    // Case 3: Deleting a node with two children (70)
    cout << "Deleting node with two children 70" << endl;
    root = deleteNodeWithTwoChildren(root, 70);
    inorder(root);
    cout << endl;

    return 0;
}
