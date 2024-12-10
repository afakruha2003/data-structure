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

// Preorder traversal (Root, Left, Right)
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->value << " ";   // Visit the root
    preorder(root->left);         // Traverse left subtree
    preorder(root->right);        // Traverse right subtree
}

// Inorder traversal (Left, Root, Right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);          // Traverse left subtree
    cout << root->value << " ";   // Visit the root
    inorder(root->right);         // Traverse right subtree
}

// Postorder traversal (Left, Right, Root)
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);        // Traverse left subtree
    postorder(root->right);       // Traverse right subtree
    cout << root->value << " ";   // Visit the root
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

    cout << "Preorder Traversal: ";
    preorder(root); // Output: 10 5 3 7 15 20
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root); // Output: 3 5 7 10 15 20
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root); // Output: 3 7 5 20 15 10
    cout << endl;

    return 0;
}
