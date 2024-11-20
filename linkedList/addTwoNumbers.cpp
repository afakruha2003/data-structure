#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

Node* addLists(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (list1 != nullptr || list2 != nullptr || carry != 0) {
        int sum = carry;
        if (list1 != nullptr) {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2 != nullptr) {
            sum += list2->data;
            list2 = list2->next;
        }

        carry = sum / 10;
        Node* newNode = new Node(sum % 10);

        if (result == nullptr) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
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
    Node* list1 = new Node(7);
    list1->next = new Node(1);
    list1->next->next = new Node(6);  // 617

    Node* list2 = new Node(5);
    list2->next = new Node(9);
    list2->next->next = new Node(2);  // 295

    std::cout << "List 1:\n";
    display(list1);
    std::cout << "List 2:\n";
    display(list2);

    Node* sum = addLists(list1, list2);
    std::cout << "Sum of lists:\n";
    display(sum);

    return 0;
}
