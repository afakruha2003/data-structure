#include <iostream>

template <typename T>
class Node {
public:
    T data;        // The data stored in the node
    Node* next;    // Pointer to the next node

    // Constructor
    Node(const T& data = T(), Node* next = nullptr)
        : data(data), next(next) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head; // Pointer to the first node in the list

public:
    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr) {}

    // Destructor: Frees all allocated memory
    ~LinkedList();

    // Copy Constructor: Creates a deep copy of another list
    LinkedList(const LinkedList& other);

    // Assignment Operator: Assigns one list to another
    LinkedList& operator=(const LinkedList& other);

    // Insert a node at the head
    void insertAtHead(const T& value);

    // Insert a node after a given node
    void insertAfter(Node<T>* prevNode, const T& value);

    // Delete a node with a specific value
    void deleteNode(const T& value);

    // Search for a node with a specific value
    Node<T>* search(const T& value) const;

    // Display all elements in the list
    void display() const;

private:
    // Helper function for deep copying
    void copyList(const LinkedList& other);

    // Helper function to clear the list
    void clear();
};

// Destructor: Frees all nodes in the list
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// Copy Constructor: Creates a deep copy of another list
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr) {
    copyList(other);
}

// Assignment Operator: Deep copies another list
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) { // Prevent self-assignment
        clear();          // Free existing memory
        copyList(other);  // Copy the other list
    }
    return *this;
}

// Insert a node at the head
template <typename T>
void LinkedList<T>::insertAtHead(const T& value) {
    Node<T>* newNode = new Node<T>(value, head);
    head = newNode;
}

// Insert a node after a given node
template <typename T>
void LinkedList<T>::insertAfter(Node<T>* prevNode, const T& value) {
    if (prevNode == nullptr) return;

    Node<T>* newNode = new Node<T>(value, prevNode->next);
    prevNode->next = newNode;
}

// Delete a node with a specific value
template <typename T>
void LinkedList<T>::deleteNode(const T& value) {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return; // Value not found

    if (prev == nullptr) {
        head = temp->next; // Delete the head
    } else {
        prev->next = temp->next; // Bypass the node
    }
    delete temp; // Free memory
}

// Search for a node with a specific value
template <typename T>
Node<T>* LinkedList<T>::search(const T& value) const {
    Node<T>* temp = head;

    while (temp != nullptr) {
        if (temp->data == value) return temp;
        temp = temp->next;
    }
    return nullptr; // Not found
}

// Display all elements in the list
template <typename T>
void LinkedList<T>::display() const {
    Node<T>* temp = head;

    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Helper Function: Deep copy another list
template <typename T>
void LinkedList<T>::copyList(const LinkedList& other) {
    if (other.head == nullptr) return;

    head = new Node<T>(other.head->data); // Copy the first node
    Node<T>* current = head;
    Node<T>* otherCurrent = other.head->next;

    while (otherCurrent != nullptr) {
        current->next = new Node<T>(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

// Helper Function: Clear the list
template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    LinkedList<int> list;

    // Insert elements at the head
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    std::cout << "List after inserting at the head:\n";
    list.display(); // Output: 30 -> 20 -> 10 -> NULL

    // Insert after a node
    Node<int>* headNode = list.search(30);
    list.insertAfter(headNode, 25);

    std::cout << "List after inserting 25 after 30:\n";
    list.display(); // Output: 30 -> 25 -> 20 -> 10 -> NULL

    // Delete a node
    list.deleteNode(20);
    std::cout << "List after deleting 20:\n";
    list.display(); // Output: 30 -> 25 -> 10 -> NULL

    // Search for a node
    Node<int>* foundNode = list.search(10);
    if (foundNode != nullptr) {
        std::cout << "Node with value 10 found.\n";
    } else {
        std::cout << "Node with value 10 not found.\n";
    }

    // Copy the list
    LinkedList<int> copiedList = list;
    std::cout << "Copied list:\n";
    copiedList.display();

    return 0;
}


/*Features in This Code
Node Class: Defines a generic node with data and a pointer.
Insertions:
insertAtHead: Adds a new node at the beginning.
insertAfter: Adds a new node after a given node.
Deletion: Removes a node by value.
Search: Finds a node by value.
Display: Prints the list.
Copy Constructor: Creates a deep copy of another list.
Assignment Operator: Handles list assignments.
Destructor: Cleans up memory to prevent leaks. */







