#include <iostream>
using namespace std;

// Define the structure for a general tree node
struct TreeNode {
    int value;
    TreeNode* firstChild;  // Pointer to the first child
    TreeNode* nextSibling; // Pointer to the next sibling

    // Constructor to initialize a new node
    TreeNode(int val) : value(val), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to count the number of leaf nodes in the tree
int countLeafNodes(TreeNode* root) {
    if (root == nullptr) 
        return 0;

    // If a node has no children, it is a leaf node
    if (root->firstChild == nullptr) 
        return 1;

    // Recursively count the leaf nodes in the first child and next siblings
    return countLeafNodes(root->firstChild) + countLeafNodes(root->nextSibling);
}

// Example usage
int main() {
    // Create a sample tree:
    //        1
    //      / | \
    //     2  3  4
    //    / \
    //   5   6

    TreeNode* root = new TreeNode(1);
    root->firstChild = new TreeNode(2);
    root->firstChild->nextSibling = new TreeNode(3);
    root->firstChild->nextSibling->nextSibling = new TreeNode(4);
    root->firstChild->firstChild = new TreeNode(5);
    root->firstChild->firstChild->nextSibling = new TreeNode(6);

    cout << "Number of leaf nodes: " << countLeafNodes(root) << endl;

    return 0;
}
