#include <iostream>
#include <vector>
#include <fstream> 
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal and save data into a file
void saveInorderToFile(Node* root, ofstream& outFile) {
    if (root == nullptr) return;

    // Traverse left subtree
    saveInorderToFile(root->left, outFile);

    // Save current node's data
    outFile << root->data << " ";

    // Traverse right subtree
    saveInorderToFile(root->right, outFile);
}

// Function to load values from a file into a vector
void loadFromFile(vector<int>& nodes, const string& filename) {
    ifstream inFile(filename);
    int value;

    while (inFile >> value) { // Read values from file
        nodes.push_back(value);
    }

    inFile.close();
}

// Function to build a balanced binary tree from sorted values
Node* buildBalancedTree(vector<int>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;

    // Create a new node with the middle element
    Node* root = new Node(nodes[mid]);

    // Recursively build left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to display the tree in inorder traversal
void displayInorder(Node* root) {
    if (root == nullptr) return;

    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}

int main() {
    // Step 1: Create a sample binary tree
    /*
            10
           /  \
          5   15
         / \    \
        3   7    18
    */
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    cout << "Original Tree (Inorder): ";
    displayInorder(root);
    cout << endl;

    // Step 2: Save the inorder traversal to a file
    string filename = "tree_inorder.txt";
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    saveInorderToFile(root, outFile);
    outFile.close();
    cout << "Inorder traversal saved to file: " << filename << endl;

    // Step 3: Load values from the file into a vector
    vector<int> nodes;
    loadFromFile(nodes, filename);

    // Step 4: Build a balanced binary tree from loaded values
    Node* newRoot = buildBalancedTree(nodes, 0, nodes.size() - 1);

    // Step 5: Display the reconstructed tree
    cout << "Reconstructed Balanced Tree (Inorder): ";
    displayInorder(newRoot);
    cout << endl;

    return 0;
}
