#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

    // Helper function to deep copy a stack
    void deepCopy(const Stack& other) {
        if (other.top == nullptr) {
            top = nullptr;
            return;
        }

        // Create a new node for the first element
        top = new Node{other.top->data, nullptr};

        // Traverse the other stack and copy nodes
        Node* currentOther = other.top->next;
        Node* currentThis = top;

        while (currentOther != nullptr) {
            currentThis->next = new Node{currentOther->data, nullptr};
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
    }

    // Helper function to delete the stack
    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Copy Constructor
    Stack(const Stack& other) {
        deepCopy(other);
    }

    // Assignment Operator
    Stack& operator=(const Stack& other) {
        if (this != &other) { // Prevent self-assignment
            clear();          // Clear existing stack
            deepCopy(other);  // Deep copy the other stack
        }
        return *this;
    }

    // Destructor
    ~Stack() {
        clear();
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node{x, top};
        top = newNode;
        std::cout << x << " pushed into stack\n";
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        Node* temp = top;
        int popped = top->data;
        top = top->next;
        delete temp;
        return popped;
    }

    // Peek operation
    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }
};

// Main Function
int main() {
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    // Demonstrate copy constructor
    Stack s2 = s1;
    std::cout << "Top of copied stack: " << s2.peek() << "\n";

    // Demonstrate assignment operator
    Stack s3;
    s3 = s1;
    std::cout << "Top of assigned stack: " << s3.peek() << "\n";

    // Modify original stack and show it doesn't affect the copies
    s1.pop();
    std::cout << "Top of original stack after pop: " << s1.peek() << "\n";
    std::cout << "Top of copied stack remains: " << s2.peek() << "\n";
    std::cout << "Top of assigned stack remains: " << s3.peek() << "\n";

    return 0;
}
