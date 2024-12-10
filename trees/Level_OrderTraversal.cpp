#include <iostream>
#include <queue>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int data;            // Node value
    TreeNode* left;      // Left child
    TreeNode* right;     // Right child

    // Constructor to initialize the node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform Level-Order Traversal
void levelOrder(TreeNode* root) {
    if (root == nullptr) {
        return; // If the tree is empty, do nothing
    }

    queue<TreeNode*> q; // Create a queue to hold nodes for processing
    q.push(root);       // Push the root into the queue

    while (!q.empty()) {
        TreeNode* current = q.front(); // Get the node at the front of the queue
        q.pop(); // Remove the node from the queue

        cout << current->data << " ";  // Print the data of the current node

        // If the current node has a left child, push it to the queue
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // If the current node has a right child, push it to the queue
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);          // Root node
    root->left = new TreeNode(2);              // Left child of root
    root->right = new TreeNode(3);             // Right child of root
    root->left->left = new TreeNode(4);        // Left child of node 2
    root->left->right = new TreeNode(5);       // Right child of node 2
    root->right->right = new TreeNode(6);      // Right child of node 3

    cout << "Level-Order Traversal: ";
    levelOrder(root); // Call the levelOrder function
    cout << endl;

    return 0;
}
