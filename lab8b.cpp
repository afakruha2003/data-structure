#include <iostream>
#include <algorithm>
using namespace std;

struct Tree
{
    Tree *right;
    Tree *left;
    int val;
    Tree(int data) : right(nullptr), left(nullptr)
    {
        val = data;
    }
};
Tree *insert(Tree *root, int data)
{
    if (root == nullptr)
    {

        Tree *newNode = new Tree(data);
        return newNode;
    }

    if (root->val < data)
    {
        root->right = insert(root->right, data);
    }
    else if (root->val > data)
    {
        root->left = insert(root->left, data);
    }
    return root;
}
void preorder(Tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " "; // Preorder: Önce kök, sonra sol, sonra sağ
    preorder(root->left);
    preorder(root->right);
}
int findMinBinarySearchTree(Tree *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return -1; 
    }
    while (root->left != nullptr)
    {
        root = root->left; 
    }
    return root->val;
}
int findMinBinaryTree(Tree *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return INT_MAX;
    }

    int leftMin = findMinBinaryTree(root->left);
    int rightMin = findMinBinaryTree(root->right);

    return min(root->val, min(leftMin, rightMin));
}

int main()

{

    cout << "enter the number of nodes: " << endl;
    int numberNodes;
    cin >> numberNodes;
    cout << "enter " << numberNodes << " values to insert into binary tree: " << endl;

    Tree *root = nullptr;

    for (int i = 0; i < numberNodes; i++)
    {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "Preorder traversal of the binary tree: " << endl;
    preorder(root);
    cout << endl;

    int minValue = findMinBinaryTree(root);
    if (minValue != -1)
    {
        cout << "Minimum value in the binary tree: " << minValue << endl;
    }

    return 0;
}