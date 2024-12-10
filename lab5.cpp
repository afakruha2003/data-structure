#include <iostream>
using namespace std;

template <typename T>
class Node
{

public:
    Node *next;
    T value;
    Node(Node<T> *next = nullptr, const T &value = T()) : next(next), value(value) {}
};
template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}
    void insertAtEnd(const T &value);
    Node<T> *PrintReverse(Node<T> *head);
    void display();
    Node<T> *findHead(const T &value);
};

template <typename T>
void LinkedList<T>::insertAtEnd(const T &value)
{
    Node<T> *newNode = new Node<T>(nullptr, value);

    if (head == nullptr)
    {
        head = newNode; // Liste boşsa, yeni düğüm başlangıç olur.
        return;
    }

    Node<T> *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}
template <typename T>
Node<T> *LinkedList<T>::PrintReverse(Node<T> *head)
{
    Node<T> *current = head;
    Node<T> *prev = nullptr;
    while (current != nullptr)
    {
        Node<T> *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

template <typename T>
void LinkedList<T>::display()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value;
        if (temp->next != nullptr)
            cout << " -> "; // Son düğümde "->" eklenmez.
        temp = temp->next;
    }
    cout << endl; // Yeni satır ekle.
}

template <typename T>
Node<T> *LinkedList<T>::findHead(const T &value)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            return temp; // Değer bulunduysa, düğüm işaretçisini döndür.
        }
        temp = temp->next;
    }
    return nullptr; // Değer bulunamadıysa, nullptr döndür.
}

int main()
{
    LinkedList<int> list;

    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List: ";
    list.display();

    Node<int> *reversedHead = list.PrintReverse(list.findHead(30));

    cout << "Reversed List: ";
    Node<int> *temp = reversedHead;
    while (temp != nullptr)
    {
        cout << temp->value;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

/*template <typename T>
void LinkedList<T>::insert(const T &value)
{
    Node<T> *newNode = new Node<T>(value, head);
    Node<T> *temp = new Node<T>(value, head);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp = newNode;
} */