#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int size;                // Size of the file, or 0 for directories
    bool isDirectory;        // True if the node is a directory
    TreeNode* firstChild;    // Pointer to the first child (file or subdirectory)
    TreeNode* nextSibling;   // Pointer to the next sibling

    // Constructor to initialize a new node
    TreeNode(int s, bool isDir) : size(s), isDirectory(isDir), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to calculate the total size of all files and subdirectories in a directory structure
int calculateTotalSize(TreeNode* root) {
    if (root == nullptr) 
        return 0; // Base case: If the node is null, the size is 0

    int totalSize = 0;

    // If the node is a file, add its size
    if (!root->isDirectory) {
        totalSize += root->size;
    }

    // Recursively calculate the size for the children (subdirectories or files)
    TreeNode* child = root->firstChild;
    while (child != nullptr) {
        totalSize += calculateTotalSize(child); // Recurse for each child
        child = child->nextSibling;            // Move to the next sibling
    }

    return totalSize; // Return the total size for this directory or file
}

// Example usage
int main() {
    // Create a sample directory structure:
    // Directory 1 (size 0):
    //   File 1 (size 10)
    //   Directory 2 (size 0):
    //     File 2 (size 20)
    //   File 3 (size 30)

    TreeNode* root = new TreeNode(0, true); // Directory 1
    root->firstChild = new TreeNode(10, false); // File 1
    root->firstChild->nextSibling = new TreeNode(0, true); // Directory 2
    root->firstChild->nextSibling->firstChild = new TreeNode(20, false); // File 2
    root->firstChild->nextSibling->nextSibling = new TreeNode(30, false); // File 3

    // Calculate the total size of all files and subdirectories
    int totalSize = calculateTotalSize(root);
    cout << "Total size of all files and directories: " << totalSize << endl;

    return 0;
}
