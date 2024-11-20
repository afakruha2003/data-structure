#include <iostream>
using namespace std;

template <class T>
void insertionSort(T a[], int size)
{

    for (size_t i = 1; i < size; i++)
    {
        T temp = a[i];
        int j = i;
        for (; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}
int main()
{
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    cout << "Insertion Sort ile sıralanmış dizi: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
template <class Item>
void insertionSort(Item a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Item temp = a[i];
        int j = i;
        for (; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

int main()
{
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    cout << "Insertion Sort ile sıralanmış dizi: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/