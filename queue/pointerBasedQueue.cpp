#include <iostream>
#include <stdexcept>

using namespace std;

// Node sınıfı
template <typename T>
class Node
{
public:
    T data;     // Node'un verisi
    Node *next; // Sonraki node'a işaretçi

    Node(T value) : data(value), next(nullptr) {}
};

// Kuyruk sınıfı
template <typename T>
class LinkedQueue
{
private:
    Node<T> *front;   // Kuyruğun ön işaretçisi
    Node<T> *backend; // Kuyruğun arka işaretçisi (backend)

public:
    // Constructor: Kuyruğu başlat
    LinkedQueue() : front(nullptr), backend(nullptr) {}

    // Kuyruk boş mu?
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Eleman ekle
    void enqueue(const T &newItem)
    {
        Node<T> *newNode = new Node<T>(newItem);
        if (isEmpty())
        {
            front = backend = newNode;
        }
        else
        {
            backend->next = newNode;
            backend = newNode;
        }
    }

    // Eleman çıkar: *dequeue* (sadece veri almaz, ön node'u siler)
    void dequeue()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty!");
        }
        Node<T> *temp = front;
        front = front->next;
        if (front == backend)
        {                              // Eğer kuyruğun tek bir elemanı varsa
            front = backend = nullptr; // Hem ön hem arka pointer'ları sıfırla
        }
        else
        {
            front = front->next; // Ön pointer'ı bir sonraki düğüme taşı
        }
        delete temp;
    }

    // Eleman çıkar ve veriyi döndür: *dequeue with return value*
    T dequeueWithReturn()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty!");
        }
        Node<T> *temp = front;
        T data = temp->data; // Çıkarılan elemanın verisini sakla
        front = front->next;
        if (front == backend)
        {                              // Eğer kuyruğun tek bir elemanı varsa
            front = backend = nullptr; // Hem ön hem arka pointer'ları sıfırla
        }
        else
        {
            front = front->next; // Ön pointer'ı bir sonraki düğüme taşı
        }
        delete temp;
        return data;
    }

    // Önceki elemanı getir
    T getFront() const
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty!");
        }
        return front->data;
    }

    // Destructor: Belleği temizle
    ~LinkedQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    LinkedQueue<int> q;

    try
    {
        // Kuyruğa eleman ekle
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        // Kuyruğun ön elemanını getir
        cout << "Front item: " << q.getFront() << endl;

        // İlk elemanı çıkar
        q.dequeue();
        cout << "Front item after dequeue: " << q.getFront() << endl;

        // Eleman çıkarma işlemi ile veriyi döndür
        int removedItem = q.dequeueWithReturn();
        cout << "Removed item: " << removedItem << endl;

        // Kalan ön elemanı getir
        cout << "Remaining front item: " << q.getFront() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
