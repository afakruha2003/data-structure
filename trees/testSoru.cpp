#include <iostream>
#include <algorithm>
using namespace std;
struct binaryTree
{
    int height;
    bool isDirectory;
    int val;
    binaryTree *right;
    binaryTree *left;
    binaryTree(int data, bool isDirectory = false, int he = 0)
    {
        val = data;
        right = nullptr;
        left = nullptr;
        height = he;
        isDirectory = isDirectory;
    }
};
struct generalTree
{
    int size;
    bool isDirectory;
    generalTree *firstChild;
    generalTree *nextSibling;
    generalTree(int data, bool isDir)
    {
        size = data;
        isDirectory = isDir;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

int calculateHeight(binaryTree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}
bool areSame(binaryTree *root1, binaryTree *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

    if (root1->val == root2->val)
    {
        return areSame(root1->left, root2->left) && areSame(root1->right, root2->right);
    }
    else
    {
        return false;
    }
}
void inorder(binaryTree *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
binaryTree *mirror(binaryTree *root)
{
    if (root == nullptr)
    {
        return nullptr; // Base case: if the tree is empty, return nullptr
    }

    // Recursively mirror the left and right subtrees
    binaryTree *mirroredLeft = mirror(root->left);
    binaryTree *mirroredRight = mirror(root->right);

    // Swap the left and right subtrees
    root->left = mirroredRight;
    root->right = mirroredLeft;

    return root; // Return the root of the mirrored tree
}

void listDirectory(binaryTree *root, int depth = 0)
{
    if (root == nullptr)
    {
        return;
    }

    // Print indentation based on depth (to show hierarchy)
    for (int i = 0; i < depth; ++i)
    {
        cout << "  ";
    }

    // Print the current node
    if (root->isDirectory)
    {
        cout << "[DIR] " << root->val << endl;
    }
    else
    {
        cout << "[FILE] " << root->val << endl;
    }

    listDirectory(root->left, depth + 1);
    listDirectory(root->right, depth);
}
void listDirectoryGeneralTree(generalTree *root, int depth = 0)
{
    if (root == nullptr)
    {
        return;
    }
    for (size_t i = 0; i < depth; i++)
    {
        cout << " ";
    }

    if (root->isDirectory)
    {
        cout << "[DIR] " << root->size << endl;
    }
    else
    {
        cout << "[FILE] " << root->size << endl;
    }
    generalTree *child = root->firstChild;
    while (child != nullptr)
    {
        listDirectoryGeneralTree(child, depth + 1);
        child = child->nextSibling;
    }
    /* listDirectoryGeneralTree(root->firstChild, depth + 1);
     listDirectoryGeneralTree(root->nextSibling, depth);
 */
}
int findDepth(generalTree *root, int depth = 0)
{
    if (root == nullptr)
    {
        return -1;
    }

    return 1 + max(findDepth(root->firstChild), findDepth(root->nextSibling));
}
void preorder(binaryTree *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << "  ";
    preorder(root->left);
    preorder(root->right);
}
int findingMinHeight(binaryTree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr)
    {
        return 1 + findingMinHeight(root->right);
    }
    if (root->right == nullptr)
    {
        return 1 + findingMinHeight(root->left);
    }

    return 1 + min(findingMinHeight(root->left), findingMinHeight(root->right));
}
binaryTree *deleteLeafNode(binaryTree *root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (value < root->val)
    {
        root->left = deleteLeafNode(root->left, value);
    }

    else if (value > root->val)
    {
        root->right = deleteLeafNode(root->right, value);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
    }
    return root;
}
int getHeight(binaryTree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    return root->height;
}
int getBalanced(binaryTree *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = (root->left == nullptr) ? 0 : root->left->height;
    int rightHeight = (root->right == nullptr) ? 0 : root->right->height;

    return root->left->height - root->right->height;
}
binaryTree *rightRotate(binaryTree *root)
{
    binaryTree *x = root->left;
    binaryTree *y = x->right;
    x->right = root;
    root->left = y;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}
binaryTree *rotateLeft(binaryTree *root)
{
    binaryTree *x = root->right;
    binaryTree *y = x->left;
    x->left = root;
    root->right = y;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}
binaryTree *insertAVL(binaryTree *root, int value)
{
    if (root == nullptr)
    {
        return new binaryTree(value);
    }
    if (value < root->val)
    {
        root->left = insertAVL(root->left, value);
    }
    else if (value < root->val)
    {
        root->right = insertAVL(root->right, value);
    }
    else
    {
        return root;
    }
    int height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanced(root);
    if (balance > 1 && root->left->val > value)
    {
        return rightRotate(root);
    }
    if (balance < -1 && root->right->val < value)
    {
        return rotateLeft(root);
    }
    if (balance > 1 && root->left->val < value)
    {
        root->left = rotateLeft(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && root->right->val > value)
    {
        root->right=rightRotate(root->right);
        return rotateLeft(root);
    }
    return root;
}
int main()
{
    binaryTree *root1 = new binaryTree(5);
    root1->left = new binaryTree(4);
    root1->left->left = new binaryTree(2);
    root1->left->right = new binaryTree(8);
    root1->right = new binaryTree(3);
    root1->right->left = new binaryTree(1);
    root1->right->right = new binaryTree(9);
    // cout << calculateHeight(root1);
    binaryTree *root2 = new binaryTree(5, true);
    root2->left = new binaryTree(4, true);
    root2->right = new binaryTree(3, true);
    root2->left->left = new binaryTree(2, false);
    root2->right->left = new binaryTree(1, false);
    root2->left->right = new binaryTree(8, false);
    root2->right->right = new binaryTree(9, false);

    generalTree *root3 = new generalTree(5, true);                                       // Root directory
    root3->firstChild = new generalTree(4, true);                                        // First child (directory)
    root3->firstChild->firstChild = new generalTree(2, false);                           // File under directory 4
    root3->firstChild->firstChild->nextSibling = new generalTree(8, false);              // Another file under directory 4
    root3->firstChild->nextSibling = new generalTree(3, true);                           // Sibling directory
    root3->firstChild->nextSibling->firstChild = new generalTree(1, false);              // File under directory 3
    root3->firstChild->nextSibling->firstChild->nextSibling = new generalTree(9, false); // Another file under directory 3

    // cout << areSame(root1, root2);
    // inorder(root1);
    // cout << endl;
    // binaryTree *newroot1 = mirror(root1);
    // inorder(newroot1);
    // cout << endl;
    // listDirectory(root2);
    listDirectoryGeneralTree(root3);
    cout << endl;
    cout << findDepth(root3);
    binaryTree*root4=nullptr;
    root4=insertAVL(root4,10);
}