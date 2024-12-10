//!Circular Singly Linked List
#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& data = T(), Node* next = nullptr) : data(data), next(next) {}
};

// Circular linked list implementation
template <typename T>
class CircularLinkedList {
private:
    Node<T>* tail;  // Points to the last node in the list

public:
    CircularLinkedList() : tail(nullptr) {}
    ~CircularLinkedList();

    void insertAtHead(const T& value);
    void insertAtTail(const T& value);
    void deleteNode(const T& value);
    void display() const;
};

// Destructor to clean up memory
template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    if (!tail) return;

    Node<T>* current = tail->next;
    while (current != tail) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    delete tail;
}

// Insert at the head of the circular list
template <typename T>
void CircularLinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (!tail) {
        tail = newNode;
        tail->next = tail;  // Circular reference
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Insert at the tail of the circular list
template <typename T>
void CircularLinkedList<T>::insertAtTail(const T& value) {
    insertAtHead(value);  // Insert at head
    tail = tail->next;    // Move the tail pointer
}

// Display the circular linked list
template <typename T>
void CircularLinkedList<T>::display() const {
    if (!tail) {
        std::cout << "The list is empty.\n";
        return;
    }

    Node<T>* current = tail->next;
    do {
        std::cout << current->data << " -> ";
        current = current->next;
    } while (current != tail->next);
    std::cout << "(head)\n";
}

int main() {
    CircularLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    std::cout << "Circular List: ";
    list.display();
    return 0;
}
