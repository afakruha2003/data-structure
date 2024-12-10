
/* İki listeyi yerinde (in-place) birleştirir.
Kaynak listeler değişir. head1 ve head2 listeleri artık bağımsız değildir.
Bellek açısından verimlidir, çünkü ek bir liste oluşturmaz.*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

// İki listeyi yerinde (in-place) birleştirir. İlk listenin sonuna ikinci listeyi ekler.
/*List 1: 10 -> 20 -> 30 -> NULL
  List 2: 15 -> 25 -> 35 -> 45 -> NULL
Merged List :10 -> 20 -> 30 -> 15 -> 25 -> 35 -> 45 -> NULL
*/
Node* mergeAlternately(Node* head1, Node* head2) {
    if (!head1) return head2; // Eğer ilk liste boşsa, ikinci listeyi döndür
    if (!head2) return head1; // Eğer ikinci liste boşsa, birinci listeyi döndür

    Node* p1 = head1; // İlk listeyi işaret eden işaretçi

    // İlk listeyi sona kadar dolaş
    while (p1->next != nullptr) {
        p1 = p1->next;
    }

    // İkinci listeyi, ilk listenin sonuna ekle
    p1->next = head2;

    return head1; // Yeni birleşik listeyi döndür
}

// burada iki listeyi birleştirirken iki listenin ilk elemanlarını daha sonra ikinci elemanler vs diye gider
/*List 1: 10 -> 20 -> 30 -> NULL
  List 2: 15 -> 25 -> 35 -> 45 -> NULL
Merged List: 10 -> 20 -> 30 -> 15 -> 25 -> 35 -> 45 -> NULL*/
/*
Node* mergeAlternately(Node* head1, Node* head2) {
    if (!head1) return head2; // If list1 is empty, return list2
    if (!head2) return head1; // If list2 is empty, return list1

    Node* p1 = head1; // İlk listeyi işaret eden işaretçi
    Node* p2 = head2; // İkinci listeyi işaret eden işaretçi

    while (p1 != nullptr && p2 != nullptr) {
        Node* temp1 = p1->next;
        Node* temp2 = p2->next;

        p1->next = p2; // Connect p1 to p2
        if (temp1 == nullptr) break; // If list1 ends, stop
        p2->next = temp1; // Connect p2 to the next of p1

        p1 = temp1; // Move to the next node in list1
        p2 = temp2; // Move to the next node in list2
    }

    return head1; // Return the merged head
}*/

// Function to display a linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Function to insert a node at the end of a list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head1 = nullptr; // First linked list
    Node* head2 = nullptr; // Second linked list

    // Insert values into the first linked list
    insertAtEnd(head1, 10);
    insertAtEnd(head1, 20);
    insertAtEnd(head1, 30);

    // Insert values into the second linked list
    insertAtEnd(head2, 15);
    insertAtEnd(head2, 25);
    insertAtEnd(head2, 35);
    insertAtEnd(head2, 45);

    std::cout << "List 1:\n";
    display(head1);

    std::cout << "List 2:\n";
    display(head2);

    // Merge lists alternately
    Node* mergedList = mergeAlternately(head1, head2);

    std::cout << "Merged List Alternately:\n";
    display(mergedList);

    return 0;
}
