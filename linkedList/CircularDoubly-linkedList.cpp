#include <iostream>

// Node class to define each element of the circular doubly linked list
template <typename T>
class Node {
public:
    T data;  // Data of the node
    Node* next;  // Pointer to the next node
    Node* prev;  // Pointer to the previous node

    Node(const T& data = T(), Node* next = nullptr, Node* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

// CircularDoublyLinkedList class that represents the circular doubly linked list
template <typename T>
class CircularDoublyLinkedList {
private:
    Node<T>* tail;  // Pointer to the tail node of the list

public:
    CircularDoublyLinkedList() : tail(nullptr) {}  // Constructor, initializes an empty list
    ~CircularDoublyLinkedList();  // Destructor to clean up memory

    void insertAtHead(const T& value);  // Insert node at the head of the list
    void insertAtTail(const T& value);  // Insert node at the tail of the list
    void deleteNode(const T& value);  // Delete a node by its value
    void display() const;  // Display the circular doubly linked list
};

// Destructor to delete all nodes and free memory
template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    if (!tail) return;  // If the list is empty, nothing to delete

    Node<T>* current = tail->next;  // Start from the head node
    do {
        Node<T>* temp = current;
        current = current->next;
        delete temp;  // Delete each node
    } while (current != tail->next);  // Stop when we loop back to the head
    delete tail;  // Delete the tail node
    tail = nullptr;  // Set tail to nullptr to mark the list as empty
}

// Insert a new node at the head of the list
template <typename T>
void CircularDoublyLinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (!tail) {  // If the list is empty, make the new node the tail (and the only node)
        tail = newNode;
        tail->next = tail;
        tail->prev = tail;
    } else {
        newNode->next = tail->next;  // New node points to the old head
        newNode->prev = tail;  // New node's previous is the tail
        tail->next->prev = newNode;  // Old head's previous is the new node
        tail->next = newNode;  // Tail's next is the new node
    }
}

// Insert a new node at the tail of the list (this is similar to inserting at the head)
template <typename T>
void CircularDoublyLinkedList<T>::insertAtTail(const T& value) {
    insertAtHead(value);  // Insert at the head
    tail = tail->next;  // Move the tail pointer to the new tail
}

// Delete a node by its value
template <typename T>
void CircularDoublyLinkedList<T>::deleteNode(const T& value) {
    if (!tail) return;  // If the list is empty, do nothing

    Node<T>* current = tail->next;  // Start from the head node
    do {
        if (current->data == value) {  // If we find the node with the specified value
            if (current == tail && current->next == tail) {  // If there's only one node in the list
                delete current;
                tail = nullptr;  // Empty the list
            } else {
                if (current == tail) tail = current->prev;  // If it's the tail, update tail
                current->prev->next = current->next;  // Bypass the current node
                current->next->prev = current->prev;  // Bypass the current node
                delete current;  // Delete the node
            }
            return;  // Node deleted, exit the function
        }
        current = current->next;  // Move to the next node
    } while (current != tail->next);  // Loop until we go back to the head
}

// Display the list from head to tail (in a circular way)
template <typename T>
void CircularDoublyLinkedList<T>::display() const {
    if (!tail) {  // If the list is empty, print a message and return
        std::cout << "The list is empty.\n";
        return;
    }

    Node<T>* current = tail->next;  // Start from the head
    do {
        std::cout << current->data << " <-> ";  // Print the current node's data
        current = current->next;  // Move to the next node
    } while (current != tail->next);  // Loop until we go back to the head
    std::cout << "(head)\n";  // Indicate that we've looped back to the head
}

// Main function to test the CircularDoublyLinkedList class
int main() {
    CircularDoublyLinkedList<int> list;  // Create a list
    list.insertAtHead(10);  // Insert 10 at the head
    list.insertAtTail(20);  // Insert 20 at the tail
    list.insertAtTail(30);  // Insert 30 at the tail

    std::cout << "List: ";
    list.display();  // Display the list

    list.deleteNode(20);  // Delete the node with value 20
    std::cout << "After deleting 20: ";
    list.display();  // Display the list again

    return 0;
}
