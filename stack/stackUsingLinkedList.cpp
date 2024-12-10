#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Check if stack is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get size of the stack
    int getSize() {
        return size;
    }

    // Display stack elements
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Reverse the stack
    void reverse() {
        Node *prev = nullptr, *current = top, *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        top = prev;
    }

    // Sort the stack
    void sort() {
        Stack tempStack;

        while (!isEmpty()) {
            int temp = top->data;
            pop();

            while (!tempStack.isEmpty() && tempStack.topElement() > temp) {
                push(tempStack.topElement());
                tempStack.pop();
            }
            tempStack.push(temp);
        }

        // Transfer elements back to original stack
        while (!tempStack.isEmpty()) {
            push(tempStack.topElement());
            tempStack.pop();
        }
    }

    // Find the middle element
    int findMiddle() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int midIndex = size / 2;
        Node* current = top;
        for (int i = 0; i < midIndex; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Delete the middle element
    void deleteMiddle() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        int midIndex = size / 2;
        Node* current = top;
        Node* prev = nullptr;

        for (int i = 0; i < midIndex; i++) {
            prev = current;
            current = current->next;
        }

        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            top = top->next; // If mid is the first element
        }

        delete current;
        size--;
    }

    // Find the top element
    int topElement() {
        return top ? top->data : -1;
    }

    // Find the maximum element
    int findMax() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int maxVal = top->data;
        Node* current = top->next;

        while (current != nullptr) {
            maxVal = max(maxVal, current->data);
            current = current->next;
        }

        return maxVal;
    }

    // Find the minimum element
    int findMin() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int minVal = top->data;
        Node* current = top->next;

        while (current != nullptr) {
            minVal = min(minVal, current->data);
            current = current->next;
        }

        return minVal;
    }
};

int main() {
    Stack stack;

    //  Push and Pop
    cout << "Adding elements to the stack: 1, 3, 5, 6" << endl;
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(6);
    cout << "Stack elements are: ";
    stack.display();

    cout << "Removing 2 elements..." << endl;
    stack.pop();
    stack.pop();
    cout << "Stack elements are: ";
    stack.display();

    cout << "Adding 9, 8 to the stack..." << endl;
    stack.push(9);
    stack.push(8);
    cout << "Stack elements are: ";
    stack.display();

    //  Check size and empty
    cout << "Stack is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Size of the stack: " << stack.getSize() << endl;

    // Reverse the stack
    cout << "Reversing the stack..." << endl;
    stack.reverse();
    cout << "Reversed stack: ";
    stack.display();

    //  Sort the stack
    cout << "Sorting the stack..." << endl;
    stack.sort();
    cout << "Sorted stack: ";
    stack.display();

    //  Middle element
    cout << "Middle element of the stack: " << stack.findMiddle() << endl;

    //  Delete the middle element
    cout << "Deleting the middle element..." << endl;
    stack.deleteMiddle();
    cout << "Stack elements are: ";
    stack.display();

    //  Find max and min elements
    cout << "Maximum element in the stack: " << stack.findMax() << endl;
    cout << "Minimum element in the stack: " << stack.findMin() << endl;

    return 0;
}
