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

// Function to find the depth of a node in a general tree
int findDepth(TreeNode* root, int target, int currentDepth = 0) {
    if (root == nullptr)
        return -1; // Base case: If root is null, return -1
    
    // If the current node is the target, return the current depth
    if (root->value == target)
        return currentDepth;

    // Search the children of the current node (first child and then siblings)
    int depth = findDepth(root->firstChild, target, currentDepth + 1); // Check first child
    if (depth != -1) // If found in first child, return depth
        return depth;

    // Check the next sibling
    return findDepth(root->nextSibling, target, currentDepth);
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

    // Find depth of node 5
    int depth = findDepth(root, 5);
    if (depth != -1)
        cout << "Depth of node 5: " << depth << endl;
    else
        cout << "Node 5 not found." << endl;

    // Find depth of node 4
    depth = findDepth(root, 4);
    if (depth != -1)
        cout << "Depth of node 4: " << depth << endl;
    else
        cout << "Node 4 not found." << endl;

    // Try for a non-existent node
    depth = findDepth(root, 7);
    if (depth != -1)
        cout << "Depth of node 7: " << depth << endl;
    else
        cout << "Node 7 not found." << endl;

    return 0;
}
