#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

bool hasLoop(Node* head) {
    Node* A = head;
    Node* B = head;

    while (B != nullptr && B->next != nullptr) {
        A = A->next;
        B = B->next->next;

        if (A == B) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head->next; // Create a loop

    if (hasLoop(head))
        std::cout << "The linked list contains a loop.\n";
    else
        std::cout << "The linked list does not contain a loop.\n";

    return 0;
}
