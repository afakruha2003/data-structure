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
    void insert(const T &value);
    Node<T> *mergeAlternatig(Node<T> *head1, Node<T> *head2);
    void display(const T &value);
    Node<T> *findHead(const T &value);
};

template <typename T>
Node<T> *LinkedList<T>::mergeAlternatig(Node<T> *head1, Node<T> *head2)
{
    Node<T> *p1 = new Node<T>(head1);
    Node<T> *p2 = new Node<T>(head2);
    Node<T> *temp = head1;

    while (head1 != nullptr && head2 != nullptr)
    {
        temp = p1->next;
        p2 = temp->next;
    }
    

    return temp;
}
template <typename T>
void LinkedList<T>::insert(const T &value)
{
    Node<T> *newNode = new Node<T>(head, value);

    head = newNode;
}
template <typename T>
void LinkedList<T>::display(const T &value)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ->";
        temp = temp->next;
    }
}

template <typename T>
Node<T> *LinkedList<T>::findHead(const T &value)
{
    Node<T> *temp = new Node<T>(head, value);
    return temp;
}
int main()
{
    LinkedList<int> list;
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
   // list.display(30);
    LinkedList<int> list2;
    list2.insert(70);
    list2.insert(80);
    list2.insert(90);
    //2list2.display(70);
    cout << endl;
    Node<int> *head1 = list.findHead(30);
    Node<int> *head2 = list.findHead(70);
    list.mergeAlternatig(head1, head2);
}