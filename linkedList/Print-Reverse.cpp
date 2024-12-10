// does not reverse the main(resource) linked list itself; it only prints the elements in reverse order using recursion.

#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node
{
    int data;   // To store the value of the node
    Node *next; // To point to the next node in the linked list
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Set the value of the node
    newNode->next = nullptr;    // Set the next pointer to null

    if (head == nullptr)
    { // If the list is empty, make this the head node
        head = newNode;
    }
    else
    {
        Node *temp = head; // Traverse to the end of the list
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }
}

// Function to print the linked list in reverse order
void printReverse(Node *head)
{
    if (head == nullptr)
        return; // Base case: If the list is empty, do nothing

    printReverse(head->next);  // Recursively call for the next node
    cout << head->data << " "; // Print the current node's data after recursive calls
}

int main()
{
    Node *head = nullptr; // Initialize an empty linked list

    // Insert values into the linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    // Print the linked list in reverse order
    printReverse(head);

    return 0;
}
