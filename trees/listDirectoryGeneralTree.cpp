#include <iostream>
using namespace std;

struct TreeNode {
    string name;              // Name of the directory or file
    TreeNode* firstChild;     // Points to the first child (subdirectory or file)
    TreeNode* nextSibling;    // Points to the next sibling
    bool isDirectory;         // Flag to check if it's a directory or file

    TreeNode(string name, bool isDirectory) : name(name), firstChild(nullptr), nextSibling(nullptr), isDirectory(isDirectory) {}
};

// Function to list directory structure (simulating directories and files)
void listDirectory(TreeNode* node, int depth = 0) {
    if (!node) return;

    // Indentation based on depth to show hierarchical structure
    for (int i = 0; i < depth; i++) cout << "  ";

    if (node->isDirectory) {
        cout << "[DIR] " << node->name << endl;
    } else {
        cout << "[FILE] " << node->name << endl;
    }

    // Recursively list the children (subdirectories or files)
    listDirectory(node->firstChild, depth + 1);
    listDirectory(node->nextSibling, depth);
}

int main() {
    // Creating a simulated directory structure
    TreeNode* root = new TreeNode("Root", true);
    root->firstChild = new TreeNode("Documents", true);
    root->firstChild->firstChild = new TreeNode("Resume.doc", false);
    root->firstChild->nextSibling = new TreeNode("Pictures", true);
    root->firstChild->nextSibling->firstChild = new TreeNode("Vacation.jpg", false);
    root->firstChild->nextSibling->nextSibling = new TreeNode("Music", true);
    root->firstChild->nextSibling->nextSibling->firstChild = new TreeNode("Song.mp3", false);

    cout << "Directory Structure: " << endl;
    listDirectory(root);
    return 0;
}
