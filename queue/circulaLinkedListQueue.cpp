#include <iostream>
#define MAX_QUEUE 5 // Kuyruğun maksimum boyutu

using namespace std;

// Circular Queue sınıfı
class CircularQueue {
private:
    int items[MAX_QUEUE]; // Kuyruk elemanları
    int front, rear, count; // Ön, arka ve eleman sayacı

public:
    // Constructor: Kuyruğu başlat
    CircularQueue() : front(0), rear(MAX_QUEUE - 1), count(0) {}

    // Kuyruk boş mu?
    bool isEmpty() const {
        return count == 0;
    }

    // Kuyruk dolu mu?
    bool isFull() const {
        return count == MAX_QUEUE;
    }

    // Eleman ekle
    void enqueue(int newItem) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        rear = (rear + 1) % MAX_QUEUE;
        items[rear] = newItem;
        ++count;
    }

    // Eleman çıkar
    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        front = (front + 1) % MAX_QUEUE;
        --count;
    }

    // Önceki elemanı getir
    int getFront() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return items[front];
    }
};

int main() {
    CircularQueue q;

    try {
        // Kuyruğa eleman ekle
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);

        cout << "Front item: " << q.getFront() << endl;

        // Eleman çıkar ve ekle
        q.dequeue();
        q.enqueue(60);

        cout << "Front item after operations: " << q.getFront() << endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
