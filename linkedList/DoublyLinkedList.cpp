#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& data = T(), Node* next = nullptr, Node* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();

    void insertAtHead(const T& value);
    void insertAtTail(const T& value);
    void deleteNode(const T& value);
    void displayForward() const;
    void displayBackward() const;
};

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

// Insert at head
template <typename T>
void DoublyLinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value, head, nullptr);
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

// Insert at tail
template <typename T>
void DoublyLinkedList<T>::insertAtTail(const T& value) {
    Node<T>* newNode = new Node<T>(value, nullptr, tail);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

// Delete a node
template <typename T>
void DoublyLinkedList<T>::deleteNode(const T& value) {
    Node<T>* current = head;
    while (current && current->data != value) {
        current = current->next;
    }

    if (!current) return;

    if (current->prev) current->prev->next = current->next;
    else head = current->next;

    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;

    delete current;
}

// Display forward
template <typename T>
void DoublyLinkedList<T>::displayForward() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

// Display backward
template <typename T>
void DoublyLinkedList<T>::displayBackward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "NULL\n";
}


int main() {
    DoublyLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);

    std::cout << "List (Forward): ";
    list.displayForward();

    std::cout << "List (Backward): ";
    list.displayBackward();

    list.deleteNode(20);
    std::cout << "After deleting 20 (Forward): ";
    list.displayForward();

    return 0;
}
