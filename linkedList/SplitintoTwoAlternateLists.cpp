#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void alternateSplit(Node* head, Node*& list1, Node*& list2) {
    Node** tail1 = &list1;
    Node** tail2 = &list2;
    int count = 0;

    while (head != nullptr) {
        if (count % 2 == 0) {
            *tail1 = head;
            tail1 = &((*tail1)->next);
        } else {
            *tail2 = head;
            tail2 = &((*tail2)->next);
        }
        head = head->next;
        ++count;
    }

    *tail1 = nullptr; // Terminate list1
    *tail2 = nullptr; // Terminate list2
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
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node* list1 = nullptr;
    Node* list2 = nullptr;

    std::cout << "Original list:\n";
    display(head);

    alternateSplit(head, list1, list2);

    std::cout << "List 1 (Alternate nodes):\n";
    display(list1);

    std::cout << "List 2 (Alternate nodes):\n";
    display(list2);

    return 0;
}
