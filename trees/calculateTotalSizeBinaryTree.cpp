#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int size;                // Size of the file, or 0 for directories
    bool isDirectory;        // True if the node is a directory
    TreeNode* left;          // Pointer to the left child (file or subdirectory)
    TreeNode* right;         // Pointer to the right child (file or subdirectory)

    // Constructor to initialize a new node
    TreeNode(int s, bool isDir) : size(s), isDirectory(isDir), left(nullptr), right(nullptr) {}
};

// Function to calculate the total size of all files and subdirectories in a binary tree
int calculateTotalSize(TreeNode* root) {
    if (root == nullptr) 
        return 0; // Base case: If the node is null, the size is 0

    int totalSize = 0;

    // If the node is a file, add its size
    if (!root->isDirectory) {
        totalSize += root->size;
    }

    // Recursively calculate the size for the left and right children
    totalSize += calculateTotalSize(root->left);  // Recurse on the left child
    totalSize += calculateTotalSize(root->right); // Recurse on the right child

    return totalSize; // Return the total size for this node (including its children)
}

// Example usage
int main() {
    // Create a sample binary tree:
    //        1 (Directory)
    //       / \
    //     2 (File, size 10)  0 (Directory)
    //    / \                     /  \
    //   3 (File, size 20)  4 (File, size 30) 

    TreeNode* root = new TreeNode(0, true); // Directory 1
    root->left = new TreeNode(10, false);   // File 2 (size 10)
    root->right = new TreeNode(0, true);    // Directory 3
    root->right->left = new TreeNode(20, false);  // File 4 (size 20)
    root->right->right = new TreeNode(30, false); // File 5 (size 30)

    // Calculate the total size of all files in the binary tree
    int totalSize = calculateTotalSize(root);
    cout << "Total size of all files and directories: " << totalSize << endl;

    return 0;
}
