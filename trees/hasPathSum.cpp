/*Problem Explanation:
You are tasked with determining if there exists a root-to-leaf path in a binary tree such that the sum of the node values along the path equals a given target sum. For example, in a binary tree, a path from the root to any leaf can have multiple nodes, and we need to check if the sum of the values along that path equals the given sum.

Approach:
Start from the root and subtract the current node's value from the target sum.
Recursively check the left and right children.
If a leaf node is reached and the remaining sum is 0, then a valid path is found.*/
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to check if there's a root-to-leaf path with the given sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    // If we reach a leaf node, check if the remaining sum is zero
    if (root->left == nullptr && root->right == nullptr) {
        return root->data == targetSum;
    }

    // Subtract the current node's value and check both left and right subtrees
    targetSum -= root->data;

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

// Main function
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum)) {
        cout << "There is a root-to-leaf path with sum " << targetSum << "." << endl;
    } else {
        cout << "No root-to-leaf path with sum " << targetSum << "." << endl;
    }

    return 0;
}
