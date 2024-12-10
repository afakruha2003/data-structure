#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to count total nodes in the binary tree
int countNodes(TreeNode* root) {
    if (root == nullptr)
        return 0; // Base case: If the node is null, return 0
    return 1 + countNodes(root->left) + countNodes(root->right); // Count the node and recursively count left and right subtrees
}

// Example usage
int main() {
    // Create a simple binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Count total nodes in the binary tree
    int totalNodes = countNodes(root);
    cout << "Total nodes in the binary tree: " << totalNodes << endl;

    return 0;
}
