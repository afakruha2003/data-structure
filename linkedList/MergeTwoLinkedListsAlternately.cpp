#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void mergeAlternately(Node*& head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != nullptr && p2 != nullptr) {
        Node* temp1 = p1->next;
        Node* temp2 = p2->next;

        p1->next = p2;
        p2->next = temp1;

        p1 = temp1;
        p2 = temp2;
    }
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
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    Node* head2 = new Node(15);
    head2->next = new Node(25);

    std::cout << "List 1:\n";
    display(head1);

    std::cout << "List 2:\n";
    display(head2);

    mergeAlternately(head1, head2);

    std::cout << "Merged list alternately:\n";
    display(head1);

    return 0;
}
