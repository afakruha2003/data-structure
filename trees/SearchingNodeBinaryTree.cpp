#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Search function to find a node
TreeNode* search(TreeNode* root, int value) {
    if (root == nullptr || root->data == value) {
        return root; // If the node is found or the root is null
    }

    if (value < root->data) {
        return search(root->left, value); // Search in the left subtree
    }
    return search(root->right, value); // Search in the right subtree
}

// Main function to demonstrate searching
int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);

    int valueToSearch = 30;
    TreeNode* foundNode = search(root, valueToSearch);
    if (foundNode != nullptr) {
        cout << "Node with value " << valueToSearch << " found!" << endl;
    } else {
        cout << "Node with value " << valueToSearch << " not found!" << endl;
    }

    return 0;
}
