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

Tree *func(Tree *root, int q, int p)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    Tree *leftSide = func(root->left, q, p);
    Tree *rightSide = func(root->right, q, p);
    if (root->val < p && root->val < q)
    {
        return rightSide;
    }
    else if (root->val > p && root->val > q)
    {
        return leftSide;
    }

    return root;
}
int main()
{

    int numElement{0};
    cout << "Eneter the number of elements:";
    cin >> numElement;
    Tree *root = nullptr;
    cout << "Eneter the  elements:";
    for (int i = 0; i < numElement; i++)
    {
        int element;
        cin >> element;
        root = insert(root, element);
    }
    cout << "Enter the two values to find LCA:";
    int p, q;
    cin >> p >> q;
    cout << endl;
    Tree *lca = func(root, p, q);
    cout << "the lowest common ancestor of " << p << " and " << q << " is: " << lca->val;
}