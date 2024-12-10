#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to define operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";

    for (char ch : infix) {
        // If the character is an operand, add it to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            operators.push(ch);
        }
        // If the character is ')', pop from stack to output until '(' is found
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '('
        }
        // If the character is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop all the remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix = "A+B*(C-D)";
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl; // Output: AB_CD-*+
    return 0;
}
