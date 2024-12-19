#include <iostream>
#include <queue>
using namespace std;

queue<int> findIntersection(queue<int>& q1, queue<int>& q2) {
    queue<int> result;

    // q1'in her elemanını kontrol et
    while (!q1.empty()) {
        int frontQ1 = q1.front();
        bool found = false;

        // q2 kuyruğunun bir kopyasını oluştur
        queue<int> tempQ2 = q2;
        
        // q2'de bu elemanı bulmaya çalış
        while (!tempQ2.empty()) {
            if (tempQ2.front() == frontQ1) {
                found = true;
                break;
            }
            tempQ2.pop();
        }

        // Eğer eleman q2'de varsa, sonucu kuyruğa ekle
        if (found) {
            result.push(frontQ1);
        }

        // q1'den bir eleman çıkar
        q1.pop();
    }

    return result;
}

int main() {
    queue<int> q1;
    queue<int> q2;

    // q1 kuyruğuna eleman ekle
    q1.push(10);
    q1.push(20);
    q1.push(30);
    
    // q2 kuyruğuna eleman ekle
    q2.push(20);
    q2.push(30);
    q2.push(40);
    
    // Kesişimi bul
    queue<int> intersection = findIntersection(q1, q2);
    
    // Sonuçları yazdır
    cout << "Intersection: ";
    while (!intersection.empty()) {
        cout << intersection.front() << " ";
        intersection.pop();
    }
    cout << endl;
    
    return 0;
}
