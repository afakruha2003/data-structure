#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& data = T(), Node* next = nullptr)
        : data(data), next(next) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* tail;

public:
    CircularLinkedList() : tail(nullptr) {}
    ~CircularLinkedList();

    void insertAtHead(const T& value);
    void insertAtTail(const T& value);
    void deleteNode(const T& value);
    void display() const;
};

// Destructor
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
    tail = nullptr;
}

// Insert at head
template <typename T>
void CircularLinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Insert at tail
template <typename T>
void CircularLinkedList<T>::insertAtTail(const T& value) {
    insertAtHead(value);
    tail = tail->next;
}

// Delete a node
template <typename T>
void CircularLinkedList<T>::deleteNode(const T& value) {
    if (!tail) return;

    Node<T>* current = tail->next;
    Node<T>* prev = tail;

    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) {
                delete current;
                tail = nullptr;
            } else {
                if (current == tail) tail = prev;
                prev->next = current->next;
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);
}

// Display the list
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

// Main function
int main() {
    CircularLinkedList<int> list;
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
