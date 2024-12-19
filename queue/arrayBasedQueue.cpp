#include <iostream>
#define MAX_QUEUE 5

using namespace std;
//circular queue boş/dou olup olmadığını kontrol etmek önemli bir sorundur .bunlar 3 çözümü
//! count Sayacı Kullanma
class CircularQueue {
private:
    int items[MAX_QUEUE];
    int front, backend, count; // front: Ön işaretçisi, backend: Arka işaretçisi, count: Eleman sayısı

public:
    CircularQueue() : front(0), backend(MAX_QUEUE - 1), count(0) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == MAX_QUEUE;
    }

    void enqueue(int newItem) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        backend = (backend + 1) % MAX_QUEUE;
        items[backend] = newItem;
        ++count;
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        front = (front + 1) % MAX_QUEUE;
        --count;
    }

    int getFront() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return items[front];
    }
};

//!Çözüm 2: isFull Bayrağını Kullanma
class CircularQueue2 {
private:
    int items[MAX_QUEUE];
    int front, backend;
    bool isFullFlag; // Kuyruğun doluluk durumunu belirten bayrak

public:
    CircularQueue2() : front(0), backend(MAX_QUEUE - 1), isFullFlag(false) {}

    bool isEmpty() const {
        return !isFullFlag && (front == (backend + 1) % MAX_QUEUE);
    }

    bool isFull() const {
        return isFullFlag;
    }

    void enqueue(int newItem) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        backend = (backend + 1) % MAX_QUEUE;
        items[backend] = newItem;
        if (front == backend) {
            isFullFlag = true;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        front = (front + 1) % MAX_QUEUE;
        isFullFlag = false;
    }

    int getFront() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return items[front];
    }
};

//! Ekstra Bir Konum (Bir Boş Alan Bırakma)
class CircularQueue3 {
private:
    int items[MAX_QUEUE];
    int front, backend;

public:
    CircularQueue3() : front(0), backend(0) {}

    bool isEmpty() const {
        return front == backend;
    }

    bool isFull() const {
        return (backend + 1) % MAX_QUEUE == front;
    }

    void enqueue(int newItem) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        backend = (backend + 1) % MAX_QUEUE;
        items[backend] = newItem;
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        front = (front + 1) % MAX_QUEUE;
    }

    int getFront() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return items[(front + 1) % MAX_QUEUE];
    }
};
int main() {
    CircularQueue q;

    try {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);

        cout << "Front item: " << q.getFront() << endl;

        q.dequeue();
        cout << "Front item after dequeue: " << q.getFront() << endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
