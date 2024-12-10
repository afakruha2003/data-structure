#include <iostream>
#include <stack>
using namespace std;

// Recursive factorial
int recursiveFactorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * recursiveFactorial(n - 1);
}

// Non-recursive factorial using a stack
int stackFactorial(int n) {
    stack<int> s;
    int result = 1;

    for (int i = n; i > 0; i--) {
        s.push(i);
    }

    while (!s.empty()) {
        result *= s.top();
        s.pop();
    }

    return result;
}

// Main function
int main() {
    int n = 5;
    cout << "Recursive Factorial: " << recursiveFactorial(n) << endl; // Output: 120
    cout << "Stack-Based Factorial: " << stackFactorial(n) << endl; // Output: 120
    return 0;
}
