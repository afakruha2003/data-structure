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

// Function to calculate the height of the tree
int calculateHeight(TreeNode* root) {
    if (root == nullptr)
        return -1; // Height of an empty tree is -1

    // Recursively calculate the height of the first child
    int childHeight = calculateHeight(root->firstChild);

    // Recursively calculate the height of the next sibling
    int siblingHeight = calculateHeight(root->nextSibling);

    // Height is the greater value between childHeight + 1 and siblingHeight
    return max(childHeight + 1, siblingHeight);
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

    cout << "Height of the tree: " << calculateHeight(root) << endl;

    return 0;
}
