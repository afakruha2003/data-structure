#include <iostream>
using namespace std;

struct TreeNode {
    int data;            // The data of the node
    TreeNode* firstChild; // Points to the first child
    TreeNode* nextSibling; // Points to the next sibling

    // Constructor
    TreeNode(int value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to find descendants (recursively)
void findDescendants(TreeNode* node) {
    if (!node) return; // Base case: if the node is null, return

    cout << node->data << " ";  // Print the current node's data (it's a descendant)

    // First, find descendants of the first child
    findDescendants(node->firstChild);

    // Then, find descendants of the next sibling
    findDescendants(node->nextSibling);
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

    // Finding descendants of root
    cout << "Descendants of root: ";
    findDescendants(root);
    cout << endl;

    return 0;
}
