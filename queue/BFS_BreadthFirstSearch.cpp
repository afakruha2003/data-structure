#include <iostream>
#include <queue>

using namespace std;

// Sabit sayıda düğüm için numNodes sabitini kullanacağız
const int numNodes = 6; // Grafik için düğüm sayısı

// BFS breadthFirst Search algoritması
void BFS(int start, int graph[numNodes][numNodes])
{
    // Ziyaret edilen düğümleri izlemek için bir dizi
    bool visited[numNodes] = {false};

    // Kuyruk yapısı (BFS için kullanılır)
    queue<int> q;

    // Başlangıç düğümünü kuyruğa ekle ve ziyaret et
    visited[start] = true;
    q.push(start);

    // Kuyruk boş olana kadar işlemi tekrarla
    while (!q.empty())
    {
        int node = q.front(); // Kuyruğun ilk elemanını al
        cout << node << "-> ";  // Düğümü ziyaret et (yazdır)
        q.pop();              // Bu düğümü kuyruğundan çıkar

        // Düğümün komşularını incele
        for (int i = 0; i < numNodes; ++i)
        {
            // Eğer düğüm komşu ise ve ziyaret edilmemişse
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i); // Komşuyu kuyruğa ekle
            }
        }
    }
}

int main()
{
    // Grafik örneği - Adjacency Matrix
    // 6 düğüm var (0-5 arası indeksler)
    int graph[numNodes][numNodes] = {
        {0, 1, 1, 0, 0, 0}, // 0 -> 1, 2
        {1, 0, 1, 1, 1, 0}, // 1 -> 0, 2, 3, 4
        {1, 1, 0, 0, 0, 1}, // 2 -> 0, 1, 5
        {0, 1, 0, 0, 0, 0}, // 3 -> 1
        {0, 1, 0, 0, 0, 0}, // 4 -> 1
        {0, 0, 1, 0, 0, 0}  // 5 -> 2
    };

    // BFS'yi başlat (0. düğümden başla)
    cout << "BFS traversal starting from node 0: ";
    BFS(0, graph); // BFS(başlangıç düğümü, adjacency matrix)

    return 0;
}
