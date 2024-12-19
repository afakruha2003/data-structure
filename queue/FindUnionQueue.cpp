#include <iostream>
#include <queue>
using namespace std;

bool isElementInQueue(queue<int>& q, int element) {
    queue<int> tempQueue = q;  // Create a copy of the queue
    while (!tempQueue.empty()) {
        if (tempQueue.front() == element) {
            return true;  // Element found in queue
        }
        tempQueue.pop();
    }
    return false;  // Element not found
}

queue<int> findUnion(queue<int>& q1, queue<int>& q2) {
    queue<int> result;
    
    // Add elements from q1 to the result queue if they are not already in it
    queue<int> tempQ1 = q1;
    while (!tempQ1.empty()) {
        int frontElement = tempQ1.front();
        if (!isElementInQueue(result, frontElement)) {
            result.push(frontElement);
        }
        tempQ1.pop();
    }
    
    // Add elements from q2 to the result queue if they are not already in it
    queue<int> tempQ2 = q2;
    while (!tempQ2.empty()) {
        int frontElement = tempQ2.front();
        if (!isElementInQueue(result, frontElement)) {
            result.push(frontElement);
        }
        tempQ2.pop();
    }
    
    return result;
}

int main() {
    queue<int> q1;
    queue<int> q2;
    
    // Add elements to q1
    q1.push(10);
    q1.push(20);
    q1.push(30);
    
    // Add elements to q2
    q2.push(20);
    q2.push(30);
    q2.push(40);
    
    queue<int> unionQueue = findUnion(q1, q2);
    
    cout << "Union: ";
    while (!unionQueue.empty()) {
        cout << unionQueue.front() << " ";
        unionQueue.pop();
    }
    cout << endl;
    
    return 0;
}
