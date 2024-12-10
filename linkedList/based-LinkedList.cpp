#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    // Constructor to initialize data and next pointer
    Node(T d) : data(d), next(nullptr) {}

    // Constructor with a next pointer
    Node(T d, Node *n) : data(d), next(n) {}
};

/*  */

template <typename T>
class LinkedList
{
public:
    Node<T> *head;

    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to clear memory
    ~LinkedList()
    {
        clear();
    }

    // Insert at the beginning
    void insertFirst(T newValue);

    // Insert at the end
    void insertLast(T value);

    // Insert after a given node
    void insertAfter(Node<T> *prevNode, T newValue);

    // Display the list
    void display() const;

    // Check if the list is empty
    bool isEmpty() const;

    // Check if a value exists in the list
    void check(T value) const;

    // Delete a node by value
    void deleteNode(T value);

    // Clear the list (free all nodes)
    void clear();

    // Search for a node by value
    Node<T> *search(T value) const;

    // Assignment operator (deep copy)
    LinkedList &operator=(const LinkedList &other);

    // Copy constructor (deep copy)
    LinkedList(const LinkedList &other);

    // Helper function to deep copy from another list
    void copyFrom(const LinkedList &other);
};


// Helper function to deep copy from another list
template <typename T>
void LinkedList<T>::copyFrom(const LinkedList<T> &other)
{
    if (other.head == nullptr)
    {
        head = nullptr;
        return;
    }

    head = new Node<T>(other.head->data); // Copy the first node
    Node<T> *current = head;
    Node<T> *temp = other.head->next;

    while (temp != nullptr)
    {
        current->next = new Node<T>(temp->data); // Create new node for each element
        current = current->next;                 // Move current to the new node
        temp = temp->next;                       // Move temp to the next node in the original list
    }
}

// Insert at the beginning
template <typename T>
void LinkedList<T>::insertFirst(T newValue)
{
    Node<T> *newNode = new Node<T>(newValue, head);
    head = newNode;
}

// Insert at the end
template <typename T>
void LinkedList<T>::insertLast(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode; // If the list is empty, the new node becomes the head
        return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert after a given node
template <typename T>
void LinkedList<T>::insertAfter(Node<T> *prevNode, T newValue)
{
    if (prevNode == nullptr)
    {
        cout << "The previous node cannot be nullptr." << endl;
        return;
    }
    Node<T> *newNode = new Node<T>(newValue, prevNode->next);
    prevNode->next = newNode;
}

// Display the list
template <typename T>
void LinkedList<T>::display() const
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Check if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return (head == nullptr);
}

// Check if a value exists in the list
template <typename T>
void LinkedList<T>::check(T value) const
{
    Node<T> *temp = head;
    bool found = false;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found)
    {
        cout << "The value " << value << " exists in the list." << endl;
    }
    else
    {
        cout << "The value " << value << " does not exist in the list." << endl;
    }
}

// Delete a node by value
template <typename T>
void LinkedList<T>::deleteNode(T value)
{
    Node<T> *temp = head;
    Node<T> *prev = nullptr;

    while (temp != nullptr && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Value not found in the list." << endl;
        return; // Value not found
    }

    if (prev == nullptr)
    { // If the node to be deleted is the head
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp; // Free memory
    cout << "Node with value " << value << " deleted." << endl;
}

// Clear the list (free all nodes)
template <typename T>
void LinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    cout << "The list has been cleared." << endl;
}

// Search for a node by value
template <typename T>
Node<T> *LinkedList<T>::search(T value) const
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return temp; // Return the found node
        }
        temp = temp->next;
    }
    return nullptr; // Not found
}

// Assignment operator (deep copy)
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (this != &other)
    {            // Prevent self-assignment
        clear(); // Free the current list
        Node<T> *temp = other.head;
        while (temp != nullptr)
        {
            insertLast(temp->data); // Insert each element from the other list
            temp = temp->next;
        }
    }
    return *this;
}

// Copy constructor (deep copy)
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) : head(nullptr)
{
    Node<T> *temp = other.head;
    while (temp != nullptr)
    {
        insertLast(temp->data); // Insert each element from the other list
        temp = temp->next;
    }
}

int main()
{
    LinkedList<int> A;

    // Insert elements into the list
    A.insertFirst(1);
    A.insertFirst(2);
    A.insertLast(4);

    // Display the list
    cout << "List after insertions: ";
    A.display(); // Output: 2 1 4

    // Insert after a given node (after the node with value 1)
    Node<int> *node = A.search(1); // Search for node with value 1
    if (node != nullptr)
    {
        A.insertAfter(node, 3); // Insert 3 after node with value 1
    }

    // Display the list after insertion
    cout << "List after inserting 3 after 1: ";
    A.display(); // Output: 2 1 3 4

    // Check for a value in the list
    A.check(2); // Output: The value 2 exists in the list.
    A.check(3); // Output: The value 3 exists in the list.

    // Delete a node
    A.deleteNode(1); // Output: Node with value 1 deleted.
    A.display();     // Output: 2 3 4

    // Clear the list
    A.clear();   // Output: The list has been cleared.
    A.display(); // Output: (empty list)

    // Copy the list
    LinkedList<int> B;
    B.insertFirst(10);
    B.insertFirst(20);
    cout << "List B: ";
    B.display(); // Output: 20 10

    // Using assignment operator
    A = B;
    cout << "List A (after assignment): ";
    A.display(); // Output: 20 10

    return 0;
}

/* LAYAN CODE WİTHOUT TEMPLATE


#include <iostream>
using namespace std;

class Node{
    public:
    Node(int d){
        data=d;
        next=NULL;

    }
     Node(int d, Node * n){
        data=d;
        next=n;

    }
    int data;
    Node* next;
};

class List{
    public:
  Node* head= NULL;
  void insertfirst(int newvalue){
      Node*newnode= new Node(newvalue,head);
      head=newnode;
  }
  void insertlast(int value){
      Node* newnode=new Node(value);
      Node* temp=head;
      while(temp->next!=NULL){
              temp=temp->next;}
          temp->next=newnode;

  }
  void display(){
      Node* temp=head;
      while(temp!=NULL){
          cout<<temp->data;
          temp=temp->next;
      }

  }
  bool isempty(){
      return(head==NULL);
  }
  void Cheak(int value){
     Node* temp=head;
     while(temp!=NULL){
        if(temp->data==value)
        cout<<"the value exixt";

        temp=temp->next;



     }
  }
};

int main() {

    std::cout << "Try programiz.pro "<<endl;
    List A;
    A.insertfirst(1);
    A.insertfirst(2);
    A.insertlast(4);
    A.display();
    A.Cheak(2);

    return 0;
}
*/