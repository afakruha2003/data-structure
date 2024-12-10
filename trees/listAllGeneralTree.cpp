#include <iostream>
using namespace std;

// Define the structure for a general tree node
struct TreeNode {
    string name;                // Name of the file or directory
    bool isDirectory;           // True if the node is a directory
    TreeNode* firstChild;       // Pointer to the first child (file or subdirectory)
    TreeNode* nextSibling;      // Pointer to the next sibling

    // Constructor to initialize a new node
    TreeNode(string n, bool isDir) : name(n), isDirectory(isDir), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to list all files and directories in a tree using preorder traversal
void listAll(TreeNode* root) {
    if (root == nullptr) return;

    // Print the current node (directory or file)
    if (root->isDirectory) {
        cout << "Directory: " << root->name << endl;
    } else {
        cout << "File: " << root->name << endl;
    }

    // Recursively list the children (preorder traversal)
    TreeNode* child = root->firstChild;
    while (child != nullptr) {
        listAll(child);           // Recurse on the first child
        child = child->nextSibling; // Move to the next sibling
    }
}

// Function to count the total number of directories and files (size of the directory)
int sizeOfDirectory(TreeNode* root) {
    if (root == nullptr) return 0;

    int size = 1;  // Count the current node (directory or file)

    // Recursively count all children (subdirectories or files)
    TreeNode* child = root->firstChild;
    while (child != nullptr) {
        size += sizeOfDirectory(child);  // Recursively count children
        child = child->nextSibling;      // Move to the next sibling
    }

    return size;
}

// Function to check if there is a directory/file with a specific name
bool findNode(TreeNode* root, const string& targetName) {
    if (root == nullptr) return false;

    // If the current node matches the target name
    if (root->name == targetName) return true;

    // Check the children and siblings
    TreeNode* child = root->firstChild;
    while (child != nullptr) {
        if (findNode(child, targetName)) return true;  // Check the child
        child = child->nextSibling;                     // Move to the next sibling
    }

    return false;  // Target not found
}

// Main function to demonstrate the general tree with directories and files
int main() {
    // Create a sample tree structure:
    // Directory 1
    //   |-- File 1
    //   |-- Directory 2
    //         |-- File 2
    //         |-- File 3
    //   |-- File 4

    TreeNode* root = new TreeNode("Directory 1", true); // Root Directory 1
    root->firstChild = new TreeNode("File 1", false);  // File 1
    root->firstChild->nextSibling = new TreeNode("Directory 2", true); // Directory 2
    root->firstChild->nextSibling->firstChild = new TreeNode("File 2", false); // File 2
    root->firstChild->nextSibling->firstChild->nextSibling = new TreeNode("File 3", false); // File 3
    root->firstChild->nextSibling->nextSibling = new TreeNode("File 4", false); // File 4

    // List all files and directories in the tree
    cout << "Listing all nodes in the tree (preorder traversal): " << endl;
    listAll(root);

    // Find the total size of the directory (number of files and directories)
    int totalSize = sizeOfDirectory(root);
    cout << "\nTotal number of files and directories: " << totalSize << endl;

    // Search for a node by name (example: find 'File 2')
    string targetName = "File 2";
    if (findNode(root, targetName)) {
        cout << "\nFound: " << targetName << endl;
    } else {
        cout << "\n" << targetName << " not found!" << endl;
    }

    return 0;
}

//----------------------------------------------------------------------------------------------------------------
/*
//for int data
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(int value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to list all nodes (all nodes in preorder)
void listAll(TreeNode* node) {
    if (!node) return;
    cout << node->data << " ";  // Print the node
    listAll(node->firstChild);  // Visit the first child
    listAll(node->nextSibling); // Visit the next sibling
}

int main() {
    // Creating a general tree
    TreeNode* root = new TreeNode(1);
    root->firstChild = new TreeNode(2);
    root->firstChild->nextSibling = new TreeNode(3);
    root->firstChild->firstChild = new TreeNode(4);
    root->firstChild->nextSibling->firstChild = new TreeNode(5);

    cout << "Listing all nodes: ";
    listAll(root);
    cout << endl;

    return 0;
}

 */