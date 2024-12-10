#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    string name;                // Name of the file or directory
    bool isDirectory;           // True if the node is a directory
    TreeNode* left;             // Pointer to the left child (file or subdirectory)
    TreeNode* right;            // Pointer to the right child (file or subdirectory)

    // Constructor to initialize a new node
    TreeNode(string n, bool isDir) : name(n), isDirectory(isDir), left(nullptr), right(nullptr) {}
};

// Function to list all files and directories in a binary tree using preorder traversal
void listAll(TreeNode* root) {
    if (root == nullptr) return;

    // Print the current node (directory or file)
    if (root->isDirectory) {
        cout << "Directory: " << root->name << endl;
    } else {
        cout << "File: " << root->name << endl;
    }

    // Recursively list the left and right children (preorder traversal)
    listAll(root->left);    // Recurse on the left child
    listAll(root->right);   // Recurse on the right child
}

// Example usage
int main() {
    // Create a sample binary tree structure:
    //        Directory 1
    //       /             \
    //   File 1        Directory 2
    //                        /    \
    //                 File 2   File 3

    TreeNode* root = new TreeNode("Directory 1", true); // Root Directory 1
    root->left = new TreeNode("File 1", false); // File 1
    root->right = new TreeNode("Directory 2", true); // Directory 2
    root->right->left = new TreeNode("File 2", false); // File 2
    root->right->right = new TreeNode("File 3", false); // File 3

    // List all files and directories in the tree
    listAll(root);

    return 0;
}
