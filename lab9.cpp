#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Tree {
    Tree *right;
    Tree *left;
    int val;
    Tree(int data) : right(nullptr), left(nullptr) {
        val = data;
    }
};

// Function to print the tree level by level
void printTraverse(Tree *root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Tree*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int nodesAtCurrentLevel = q.size();
        cout << "Level " << level << ": ";

        while (nodesAtCurrentLevel--) {
            Tree *current = q.front();
            q.pop();

            cout << current->val << " ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
        level++;
    }
}
// Function to create a binary tree of given depth with random values
Tree* insertDepth(Tree *root, int depth) {
    if (depth <= 0) {
        return nullptr;
    }

    root = new Tree(rand() % 100); // Root with random value
    queue<Tree*> q;
    q.push(root);

    for (int level = 1; level < depth; ++level) {
        int nodesAtCurrentLevel = q.size();

        while (nodesAtCurrentLevel--) {
            Tree *current = q.front();
            q.pop();

            // Randomly add left and right children
            if (rand() % 2) {
                current->left = new Tree(rand() % 100);
                q.push(current->left);
            }
            if (rand() % 2) {
                current->right = new Tree(rand() % 100);
                q.push(current->right);
            }
        }
    }

    return root;
}

int main() {
    srand(time(0)); // Seed for random number generation

    Tree *root = nullptr;
    root = insertDepth(root, 3); // Create a tree with depth 3

    cout << "Level Order Traversal of the Tree:" << endl;
    printTraverse(root);

    return 0;
}





//!wrong code
/*

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <stdlib.h>
#include <cstdlib>
#include <queue>
#include <cmath>
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
void printTraverse(Tree *root, int depth)
{
    queue<int> q;
    q.push(root->val);

    queue<int> temp = q;
    int currentDepth = depth;
    while (!temp.empty())
    {

        cout << "level " << depth << ":";
        cout << " " << temp.front() << "  ";

        if (root->left)
        {
            temp.push(root->left->val);
        }
        if (root->right)
        {
            temp.push(root->right->val);
        }
        temp.pop();
        printTraverse(root->left, depth - 1);
        //printTraverse(root->right, depth);
        currentDepth--;
    }

    q.pop();
}
Tree *insert(Tree *root, int data)
{
    if (root == nullptr)
    {

        Tree *newNode = new Tree(data);
        return newNode;
    }

    root->right = insert(root->right, data);

    root->left = insert(root->left, data);

    return root;
}
Tree *insertDepth(Tree *root, int depth)
{
    int currentDepth = pow(2, depth + 1) - 1;
    while (currentDepth != 0)
    {
        int x = rand();
        ctime(0);

        root = insert(root, x);
        currentDepth--;
    }
}
void inorder(Tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << "   ";
    inorder(root->right);
}

int main()
{
    Tree *root = nullptr;
    root = insertDepth(root, 3);
    printTraverse(root, 2);
    cout << endl;
    // inorder(root);
}
*/