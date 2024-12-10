#include <iostream>

// Node class for a singly linked list
class Node {
public:
    int data;  // Data of the node
    Node* next;  // Pointer to the next node
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

// Function to detect if a linked list contains a loop using Floyd’s cycle-finding algorithm
bool hasLoop(Node* head) {
    Node* A = head;
    Node* B = head;

    while (B != nullptr && B->next != nullptr) {
        A = A->next;  // Move pointer A one step
        B = B->next->next;  // Move pointer B two steps

        if (A == B) return true;  // If the two pointers meet, there is a loop
    }
    return false;  // No loop if pointers do not meet
}

int main() {
    Node* head = new Node(10);  // Create a new node with data 10
    head->next = new Node(20);  // Add a node with data 20
    head->next->next = new Node(30);  // Add a node with data 30
    head->next->next->next = head->next;  // Create a loop (30 -> 20)

    if (hasLoop(head))  // Check if the list contains a loop
        std::cout << "The linked list contains a loop.\n";
    else
        std::cout << "The linked list does not contain a loop.\n";

    return 0;
}
