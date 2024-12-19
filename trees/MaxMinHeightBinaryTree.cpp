#include <iostream>
#include <algorithm> // For std::min and std::max
using namespace std;
/*
Maximum height for N Nodes: N-1
Minimum height: [log(N+1)-1]
                    2
*/

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the maximum height of the binary tree
int findMaxHeight(TreeNode* root) {
    if (root == nullptr) 
        return -1; // Base case: if the node is null, return -1 (height of an empty tree)
    return 1 + max(findMaxHeight(root->left), findMaxHeight(root->right)); // Max height of left and right subtrees
}

// Function to find the minimum height of the binary tree
int findMinHeight(TreeNode* root) {
    if (root == nullptr) 
        return -1; // Base case: if the node is null, return -1 (height of an empty tree)
    
    // If both left and right children are null, it's a leaf node
    if (root->left == nullptr && root->right == nullptr) 
        return 0; // Leaf node height is 0
    
    // If one of the children is null, take the height of the non-null child
    if (root->left == nullptr)
        return 1 + findMinHeight(root->right);
    if (root->right == nullptr)
        return 1 + findMinHeight(root->left);

    // If both children exist, return the minimum height of the two subtrees
    return 1 + min(findMinHeight(root->left), findMinHeight(root->right));
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

    // Find the maximum and minimum heights
    int maxHeight = findMaxHeight(root);
    int minHeight = findMinHeight(root);

    cout << "Maximum height of the binary tree: " << maxHeight << endl;
    cout << "Minimum height of the binary tree: " << minHeight << endl;

    return 0;
}
