#include <iostream>
using namespace std;

template <class Item>
void selectionSort(Item a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

template <class Object>
void swap(Object &lhs, Object &rhs) {
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main() {
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);

    cout << "Selection Sort ile sıralanmış dizi: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
