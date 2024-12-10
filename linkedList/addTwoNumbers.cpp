//! Add Two Numbers Represented by Linked Lists
#include <iostream>

// Define the structure for a node in the singly linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

// Function to add two linked lists representing numbers
Node *addLists(Node *list1, Node *list2)
{
    Node *result = nullptr; // Resultant linked list
    Node *tail = nullptr;   // Pointer to the tail of the result list
    int carry = 0;          // Carry for the addition

    // Traverse both lists until all nodes are processed
    while (list1 != nullptr || list2 != nullptr || carry != 0)
    {
        int sum = carry; // Start with carry

        if (list1 != nullptr)
        {
            sum += list1->data; // Add value from list1
            list1 = list1->next;
        }
        if (list2 != nullptr)
        {
            sum += list2->data; // Add value from list2
            list2 = list2->next;
        }

        carry = sum / 10;                   // Update carry
        Node *newNode = new Node(sum % 10); // Create a new node with the sum's last digit

        if (result == nullptr)
        {
            result = newNode; // Initialize result list
            tail = newNode;
        }
        else
        {
            tail->next = newNode; // Append the new node
            tail = newNode;
        }
        /*  else Kısmı:
    Eğer result zaten bir düğüm içeriyorsa (yani liste zaten başlatıldıysa), yeni bir düğüm ekliyoruz:
    tail->next = newNode;: Bu, mevcut listenin sonuna yeni düğümü ekler. tail işaretçisi, son düğümün next işaretçisini, yeni düğüme yönlendirecek.
    tail = newNode;: Son olarak, tail işaretçisini yeni eklenen düğümü işaret edecek şekilde güncelliyoruz. Bu, ilerleyen adımlarda yeni düğüm eklerken doğru son düğümün işaret edilmesini sağlar.*/
    }

    return result; // Return the resultant list
}

// Function to display a linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Main function to test the implementation
int main()
{
    Node *list1 = new Node(7);
    list1->next = new Node(1);
    list1->next->next = new Node(6); // Represents 617

    Node *list2 = new Node(5);
    list2->next = new Node(9);
    list2->next->next = new Node(2); // Represents 295

    std::cout << "List 1:\n";
    display(list1);
    std::cout << "List 2:\n";
    display(list2);

    Node *sum = addLists(list1, list2);
    std::cout << "Sum of lists:\n";
    display(sum);

    return 0;
}
