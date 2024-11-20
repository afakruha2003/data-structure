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
class CircularDoublyLinkedList {
private:
    Node<T>* tail;

public:
    CircularDoublyLinkedList() : tail(nullptr) {}
    ~CircularDoublyLinkedList();

    void insertAtHead(const T& value);
    void insertAtTail(const T& value);
    void deleteNode(const T& value);
    void display() const;
};

// Destructor
template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    if (!tail) return;

    Node<T>* current = tail->next;
    do {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    } while (current != tail->next);
    delete tail;
    tail = nullptr;
}

// Insert at head
template <typename T>
void CircularDoublyLinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (!tail) {
        tail = newNode;
        tail->next = tail;
        tail->prev = tail;
    } else {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
    }
}

// Insert at tail
template <typename T>
void CircularDoublyLinkedList<T>::insertAtTail(const T& value) {
    insertAtHead(value);
    tail = tail->next;
}

// Delete a node
template <typename T>
void CircularDoublyLinkedList<T>::deleteNode(const T& value) {
    if (!tail) return;

    Node<T>* current = tail->next;
    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) {
                delete current;
                tail = nullptr;
            } else {
                if (current == tail) tail = current->prev;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            return;
        }
        current = current->next;
    } while (current != tail->next);
}

// Display the list
template <typename T>
void CircularDoublyLinkedList<T>::display() const {
    if (!tail) {
        std::cout << "The list is empty.\n";
        return;
    }

    Node<T>* current = tail->next;
    do {
        std::cout << current->data << " <-> ";
        current = current->next;
    } while (current != tail->next);
    std::cout << "(head)\n";
}

// Main function
int main() {
    CircularDoublyLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    std::cout << "List: ";
    list.display();

    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.display();

    return 0;
}
