#include <iostream>
#define MAX 1000

class Stack {
    int top;
    int arr[MAX]; // Maximum size of Stack

public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Pushes an element onto the stack.
bool Stack::push(int x) {
    if (top >= MAX - 1) {
        std::cout << "Stack Overflow\n";
        return false;
    } else {
        arr[++top] = x;
        std::cout << x << " pushed into stack\n";
        return true;
    }
}

// Removes the top element of the stack.
int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

// Returns the top element without removing it.
int Stack::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty\n";
        return 0;
    } else {
        return arr[top];
    }
}

// Checks if the stack is empty.
bool Stack::isEmpty() {
    return (top < 0);
}

// Main Function
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " popped from stack\n";
    return 0;
}
