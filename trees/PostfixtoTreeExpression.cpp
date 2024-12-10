#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
using namespace std;

struct TreeNode {
    char data;  // Can be operator or operand
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform the operation
int performOperation(int left, int right, char op) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default: return 0;
    }
}

// Function to build an expression tree from a postfix expression
TreeNode* buildExpressionTree(const string& postfix) {
    stack<TreeNode*> s;

    for (char c : postfix) {
        if (isdigit(c)) {
            // If the character is a digit, create a leaf node
            s.push(new TreeNode(c));
        } else if (isOperator(c)) {
            // If the character is an operator, pop two nodes and create a new subtree
            TreeNode* right = s.top(); s.pop();
            TreeNode* left = s.top(); s.pop();
            TreeNode* node = new TreeNode(c);
            node->left = left;
            node->right = right;
            s.push(node);  // Push the new subtree back onto the stack
        }
    }

    return s.top();  // The root of the expression tree
}

// Function to evaluate the expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == nullptr) return 0;

    // If it's a leaf node (digit), return its value
    if (!isOperator(root->data)) {
        return root->data - '0';  // Convert character to int
    }

    // Recursively evaluate the left and right subtrees
    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);

    // Perform the operation at the current node
    return performOperation(leftVal, rightVal, root->data);
}

int main() {
    string postfix = "23*45*+";
    TreeNode* root = buildExpressionTree(postfix);

    cout << "Evaluating postfix expression '" << postfix << "' gives result: ";
    cout << evaluateExpressionTree(root) << endl;

    return 0;
}
