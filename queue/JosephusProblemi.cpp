#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int josephusQueue(int n, int k)
{
    // Kişileri 1'den n'e kadar kuyrukta tutuyoruz
    queue<int> q;

    // Kuyruğa 1'den n'e kadar olan sayıları ekliyoruz
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    // Elimination işlemi
    while (q.size() > 1)
    { // Sadece bir kişi kalana kadar<
        // k-1 kişiyi sırayla kuyruktan çıkarıyoruz ve başa ekliyoruz
        for (int i = 1; i < k; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front); // Kuyruğun sonuna ekle
        }

        // k. kişiyi öldürüyoruz (kuyruktan çıkarıyoruz)
        q.pop();
    }

    // Son olarak kalan tek kişiyi döndürüyoruz
    return q.front();
}
int josephus(int n)
{
    int a = 0;
    int temp = n;
    while (temp > 1)
    {
        temp /= 2;
        a++;
    }

    int b = n - pow(2, a);
    return 2 * b + 1;
}
int main()
{
    int n, k;

    cout << "Kişi sayısını girin (n): ";
    cin >> n;
    // cout << "Her k. kişiyi öldürmek için k'yi girin: ";
    // cin >> k;


    int winner = josephus(n);
    cout << "Kazanan kişi: " << winner << endl;

    return 0;
}
