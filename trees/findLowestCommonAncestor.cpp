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

// Function to find the LCA of two nodes in a general tree
TreeNode* findLCA(TreeNode* root, int p, int q) {
    if (root == nullptr) 
        return nullptr; // If the tree is empty, return null

    // If the current node matches either of the target nodes, return the current node
    if (root->value == p || root->value == q) 
        return root;

    TreeNode* childLCA = nullptr; // To store LCA found in the child subtree
    int count = 0; // To count how many subtrees contain the target nodes

    // Traverse the children of the current node
    for (TreeNode* child = root->firstChild; child != nullptr; child = child->nextSibling) {
        TreeNode* lca = findLCA(child, p, q); // Recursive call on each child
        if (lca != nullptr) {
            count++;
            childLCA = lca;
        }
    }

    // If more than one subtree contains one of the nodes, current node is the LCA
    if (count > 1) 
        return root;

    // Otherwise, return the LCA found in the child subtree
    return childLCA;
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

    TreeNode* lca = findLCA(root, 5, 6);
    if (lca != nullptr) 
        cout << "LCA of 5 and 6: " << lca->value << endl;
    else 
        cout << "LCA not found." << endl;

    lca = findLCA(root, 5, 4);
    if (lca != nullptr) 
        cout << "LCA of 5 and 4: " << lca->value << endl;
    else 
        cout << "LCA not found." << endl;

    return 0;
}
