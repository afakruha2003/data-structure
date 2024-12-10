#include <iostream>

// Node class to define each element in a doubly linked list
template <typename T>
class Node {
public:
    T data;  // Data of the node
    Node* next;  // Pointer to the next node
    Node* prev;  // Pointer to the previous node

    Node(const T& data = T(), Node* next = nullptr, Node* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

// DoublyLinkedList class that represents a doubly linked list
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;  // Pointer to the head node
    Node<T>* tail;  // Pointer to the tail node

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}  // Constructor, initializes an empty list
    ~DoublyLinkedList();  // Destructor to clean up memory

    void insertAtHead(const T& value);  // Insert node at the head of the list
    void insertAtTail(const T& value);  // Insert node at the tail of the list
    void deleteNode(const T& value);  // Delete a node by its value
    void displayForward() const;  // Display the list from head to tail
    void displayBackward() const;  // Display the list from tail to head
};

// Destructor to delete all nodes and free memory
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;  // Delete each node
    }
}

// Insert a new node at the head of the list
template <typename T>
void DoublyLinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value, head, nullptr);
    if (head) {
        head->prev = newNode;  // Update the previous pointer of the old head
    } else {
        tail = newNode;  // If the list was empty, new node becomes the tail
    }
    head = newNode;  // Make the new node the head
}

// Insert a new node at the tail of the list
template <typename T>
void DoublyLinkedList<T>::insertAtTail(const T& value) {
    Node<T>* newNode = new Node<T>(value, nullptr, tail);
    if (tail) {
        tail->next = newNode;  // Update the next pointer of the old tail
    } else {
        head = newNode;  // If the list was empty, new node becomes the head
    }
    tail = newNode;  // Make the new node the tail
}

// Delete a node by its value
template <typename T>
void DoublyLinkedList<T>::deleteNode(const T& value) {
    Node<T>* current = head;
    while (current && current->data != value) {
        current = current->next;  // Move to the next node
    }

    if (!current) return;  // If the value is not found, do nothing

    if (current->prev) current->prev->next = current->next;  // Bypass the current node from the previous node
    else head = current->next;  // If it's the head, update head

    if (current->next) current->next->prev = current->prev;  // Bypass the current node from the next node
    else tail = current->prev;  // If it's the tail, update tail

    delete current;  // Delete the node
}

// Display the list from head to tail
template <typename T>
void DoublyLinkedList<T>::displayForward() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " <-> ";  // Print the data of each node
        current = current->next;  // Move to the next node
    }
    std::cout << "NULL\n";  // Indicate the end of the list
}

// Display the list from tail to head
template <typename T>
void DoublyLinkedList<T>::displayBackward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " <-> ";  // Print the data of each node
        current = current->prev;  // Move to the previous node
    }
    std::cout << "NULL\n";  // Indicate the end of the list
}

// Main function to test the DoublyLinkedList class
int main() {
    DoublyLinkedList<int> list;  // Create a list
    list.insertAtHead(10);  // Insert 10 at the head
    list.insertAtHead(20);  // Insert 20 at the head
    list.insertAtTail(30);  // Insert 30 at the tail

    std::cout << "List (Forward): ";
    list.displayForward();  // Display the list forward

    std::cout << "List (Backward): ";
    list.displayBackward();  // Display the list backward

    list.deleteNode(20);  // Delete the node with value 20
    std::cout << "After deleting 20 (Forward): ";
    list.displayForward();  // Display the list forward again

    return 0;
}
