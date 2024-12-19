#include <iostream>
#include <queue>
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

Tree *insert(Tree *root, int data)
{
    if (root == nullptr)
    {
        return new Tree(data);
    }
    if (data < root->val)
    {
        root->left = insert(root->left, data); // Sol alt ağaca ekle
    }
    else if (data > root->val)
    {
        root->right = insert(root->right, data); // Sağ alt ağaca ekle
    }
    return root;
}

bool search(Tree *root, int data)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->val == data)
    {
        return true;
    }
    if (data < root->val)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main()
{
    Tree *root = nullptr;

    cout << "Enter the number of nodes: ";
    int numberNodes;
    cin >> numberNodes;

    cout << "Enter " << numberNodes << " values to insert into the binary tree: " << endl;
    for (int i = 0; i < numberNodes; i++)
    {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "Preorder traversal of the binary tree: ";
    preorder(root);
    cout << endl;

    cout << "Enter a value to search in the tree: ";
    int valueSearch;
    cin >> valueSearch;
    if (search(root, valueSearch))
    {
        cout << valueSearch << " is represented in the tree." << endl;
    }
    else
    {
        cout << valueSearch << " is not represented in the tree." << endl;
    }

    return 0;
}
