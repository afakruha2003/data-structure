#include <iostream>
#include <stack>
using namespace std;

#define ROWS 5
#define COLS 5

// Labirent haritası (1: Geçilebilir, 0: Duvar)
int maze[ROWS][COLS] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1}
};

// Hareket yönleri: yukarı, sağ, aşağı, sol
int directions[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

// Hücreyi temsil eden yapı
struct Cell {
    int row, col;
};

// Labirent içinde verilen bir hücre geçerli mi?
bool isValid(int row, int col, bool visited[ROWS][COLS]) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
            maze[row][col] == 1 && !visited[row][col]);
}

// Labirenti çözme fonksiyonu
bool solveMaze(int startRow, int startCol, int endRow, int endCol) {
    stack<Cell> path;
    bool visited[ROWS][COLS] = {false}; // Ziyaret edilen hücreleri takip eder

    path.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!path.empty()) {
        Cell current = path.top();
        int row = current.row;
        int col = current.col;

        // Çıkış noktasına ulaşıldı mı?
        if (row == endRow && col == endCol) {
            cout << "Yol Bulundu: ";
            while (!path.empty()) {
                Cell step = path.top();
                cout << "(" << step.row << "," << step.col << ") ";
                path.pop();
            }
            cout << endl;
            return true;
        }

        // Bir sonraki geçerli hareketi bul
        bool moved = false;
        for (auto dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (isValid(newRow, newCol, visited)) {
                path.push({newRow, newCol});
                visited[newRow][newCol] = true;
                moved = true;
                break;
            }
        }

        // Eğer ilerlenemiyorsa, geri dön
        if (!moved) {
            path.pop();
        }
    }

    cout << "Labirentte yol bulunamadı.\n";
    return false;
}

int main() {
    int startRow = 0, startCol = 0;
    int endRow = 4, endCol = 4;

    cout << "Labirent çözülüyor...\n";
    if (!solveMaze(startRow, startCol, endRow, endCol)) {
        cout << "Çözüm mevcut değil.\n";
    }

    return 0;
}
