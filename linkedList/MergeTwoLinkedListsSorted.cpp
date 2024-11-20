#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

// Merges two sorted linked lists into one sorted linked list
Node* mergeLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data < list2->data) {
        list1->next = mergeLists(list1->next, list2); // Recurse for the next element
        return list1;
    } else {
        list2->next = mergeLists(list1, list2->next); // Recurse for the next element
        return list2;
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
    // Create two sorted lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    std::cout << "List 1 (Sorted):\n";
    display(list1);
    std::cout << "List 2 (Sorted):\n";
    display(list2);

    // Merge the two sorted lists
    Node* mergedList = mergeLists(list1, list2);
    std::cout << "Merged Sorted List:\n";
    display(mergedList);

    return 0;
}
