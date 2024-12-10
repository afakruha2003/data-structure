#include <iostream>
#include <stack>
using namespace std;

// Function to check balanced braces
bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expr = "{[()]}";
    cout << "Balanced: " << (isBalanced(expr) ? "Yes" : "No") << endl; // Output: Yes
    return 0;
}
