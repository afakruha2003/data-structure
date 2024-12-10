#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};
//! bu kodla merge yeni liste oluşturur ve kaynak liseler değişmez
// Listeyi sırayla birleştiren fonksiyon (ilk liste sonra ikinci liste)
Node *mergeAlternatelyNewList(Node *head1, Node *head2)
{
    Node *result = nullptr; // Yeni birleşik listenin başı
    Node *tail = nullptr;   // Yeni listenin sonunu tutan işaretçi

    Node *temp1 = head1; // Geçici işaretçi, head1'in değiştirilmemesi için
    Node *temp2 = head2; // Geçici işaretçi, head2'nin değiştirilmemesi için

    // İlk listeyi tamamen ekleyelim
    while (temp1 != nullptr)
    {
        if (result == nullptr)
        {
            result = new Node(temp1->data);
            tail = result;
        }
        else
        {
            tail->next = new Node(temp1->data);
            tail = tail->next;
        }
        temp1 = temp1->next; // temp1'i bir sonraki elemana yönlendir
    }

    // İkinci listeyi tamamen ekleyelim
    while (temp2 != nullptr)
    {
        if (result == nullptr)
        {
            result = new Node(temp2->data);
            tail = result;
        }
        else
        {
            tail->next = new Node(temp2->data);
            tail = tail->next;
        }
        temp2 = temp2->next; // temp2'yi bir sonraki elemana yönlendir
    }

    return result; // Yeni birleşik listeyi döndürüyoruz
}

// Bağlı listenin elemanlarını yazdırır
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

// Bağlı listenin sonuna yeni bir düğüm ekler
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    insertAtEnd(head1, 10);
    insertAtEnd(head1, 20);
    insertAtEnd(head1, 30);

    insertAtEnd(head2, 15);
    insertAtEnd(head2, 25);
    insertAtEnd(head2, 35);
    insertAtEnd(head2, 45);

    std::cout << "List 1:\n";
    display(head1);

    std::cout << "List 2:\n";
    display(head2);

    Node *mergedList = mergeAlternatelyNewList(head1, head2);

    std::cout << "Merged List (List 1 First, Then List 2):\n";
    display(mergedList);

    return 0;
}
