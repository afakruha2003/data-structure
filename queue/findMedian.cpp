#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

double findMedian(queue<int> q) {
    vector<int> temp;
    
    // Kuyruğun elemanlarını geçici bir vektöre aktar
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    
    // Vektörü sırala
    sort(temp.begin(), temp.end());


    int n = temp.size();
    if (n % 2 == 1) {
        return temp[n / 2];  //index normalden 1 eksik olduğu için n/2 +1 demek yerine n/2 diye bıraktık 
    } else {
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;  // Eğer çift sayıda eleman varsa, ortadaki iki elemanın ortalaması
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    //q.push(40);
    
    cout << "Median: " << findMedian(q) << endl;

    return 0;
}
