#include <iostream>
using namespace std;

struct TreeNode {
    int data;            // The data of the node
    TreeNode* firstChild; // Points to the first child
    TreeNode* nextSibling; // Points to the next sibling

    // Constructor
    TreeNode(int value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to find ancestors of a node (recursively)
bool findAncestors(TreeNode* node, int target) {
    if (!node) return false; // If node is null, return false

    // If this node is the target, print its ancestors (path)
    if (node->data == target) {
        cout << "Ancestors of " << target << ": ";
        return true;
    }

    // Recursively search for the target in the first child
    if (findAncestors(node->firstChild, target)) {
        cout << node->data << " "; // Print the current node as an ancestor
        return true;
    }

    // If not found in first child, search in the next sibling
    return findAncestors(node->nextSibling, target);
}

int main() {
    // Creating nodes
    TreeNode* root = new TreeNode(1);   // Root node with value 1
    TreeNode* nodeA = new TreeNode(2);  // Node A with value 2
    TreeNode* nodeB = new TreeNode(3);  // Node B with value 3
    TreeNode* nodeC = new TreeNode(4);  // Node C with value 4

    // Setting up the tree structure
    root->firstChild = nodeA;    // Root's first child is A
    nodeA->nextSibling = nodeB;  // A's next sibling is B
    nodeB->firstChild = nodeC;   // B's first child is C

    // Finding ancestors of node 4 (C)
    if (!findAncestors(root, 4)) {
        cout << "Node not found." << endl;
    }
    cout << endl;

    return 0;
}
