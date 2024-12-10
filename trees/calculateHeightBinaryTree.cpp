#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

int calculateHeight(TreeNode* root) {
    if (root == nullptr)
        return -1; // Height of an empty tree is -1
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Example usage
int main() {
    TreeNode* root = new TreeNode{1, nullptr, nullptr};
    root->left = new TreeNode{2, nullptr, nullptr};
    root->right = new TreeNode{3, nullptr, nullptr};
    root->left->left = new TreeNode{4, nullptr, nullptr};

    cout << "Height of the tree: " << calculateHeight(root) << endl;
    return 0;
}
