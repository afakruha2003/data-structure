#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the maximum value in a binary tree
int findMax(TreeNode* root) {
    if (root == nullptr) 
        return INT_MIN; // If the tree is empty, return a very small value (INT_MIN)

    // Recursively find the maximum in the left and right subtrees
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    // Return the maximum of the current node's value, left subtree, and right subtree
    return max(root->value, max(leftMax, rightMax));
}

// Example usage
int main() {
    // Create a simple binary tree:
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     3   7    20

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);

    // Find the maximum value in the binary tree
    int maxValue = findMax(root);
    cout << "Maximum value in the binary tree: " << maxValue << endl;

    return 0;
}
