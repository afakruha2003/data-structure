#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Insert function to add a node to the tree
TreeNode* insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value); // Create a new node if the current node is nullptr
    }

    if (value < node->data) {
        node->left = insert(node->left, value); // Insert into the left subtree
    } else {
        node->right = insert(node->right, value); // Insert into the right subtree
    }
    return node;
}

// Main function to demonstrate insertion
int main() {
    TreeNode* root = nullptr;

    // Insert nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nodes inserted successfully!" << endl;
    return 0;
}
