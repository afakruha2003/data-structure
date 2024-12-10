#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // New head
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    std::cout << "Original list:\n";
    display(head);

    head = reverseList(head);

    std::cout << "Reversed list:\n";
    display(head);

    return 0;
}
