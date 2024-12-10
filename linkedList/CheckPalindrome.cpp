//!Check if a Linked List is a Palindrome
#include <iostream>

// Define the structure for a node in the singly linked list
class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    // Reverse pointers for all nodes in the list
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;  // Return the new head of the reversed list
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;

    Node* slow = head;  // Slow pointer for the midpoint
    Node* fast = head;  // Fast pointer to traverse the list

    // Find the midpoint using the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow);  // Reverse the second half of the list
    Node* firstHalf = head;  // First half remains as-is

    // Compare both halves
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;  // If all values match, the list is a palindrome
}

// Main function to test the implementation
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if (isPalindrome(head))
        std::cout << "The linked list is a palindrome.\n";
    else
        std::cout << "The linked list is not a palindrome.\n";

    return 0;
}
