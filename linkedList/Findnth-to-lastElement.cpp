#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

Node* findNthToLast(Node* head, int n) {
    Node* A = head; // Fast pointer
    Node* B = head; // Slow pointer

    // Move A n steps ahead
    for (int i = 0; i < n; ++i) {
        if (A == nullptr) return nullptr; // n is larger than the list size
        A = A->next;
    }

    // Move A and B one step at a time
    while (A != nullptr) {
        A = A->next;
        B = B->next;
    }

    return B; // B is now the nth-to-last node
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int n = 2;
    Node* result = findNthToLast(head, n);

    if (result)
        std::cout << "The " << n << "-to-last element is: " << result->data << std::endl;
    else
        std::cout << "The list is shorter than " << n << " elements.\n";

    return 0;
}
