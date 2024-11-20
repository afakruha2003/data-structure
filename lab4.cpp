#include <iostream>
using namespace std;

template <class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
int partition(T a[], int first, int last)
{
    int pivotIndex = first;
    T pivot = a[pivotIndex];
    int lastS = first;

    for (int i = first; i <= last; i++)
    {
        if (a[i] < pivot) // yanlış işaret
        {
            ++lastS;
            swap(&a[i], &a[lastS]); // swap(a[i], a[pivotIndex]);
        }
    }
    swap(&a[first], &a[lastS]); // swap(a[first], a[last]);
    return lastS;
}

template <class T>
void quickSort(T a[], int first, int last)
{
    if (first < last)// eksik
    {
        
        int pivotIndex = partition(a, first, last);// int pivotIndex = first;
        quickSort(a, first, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, last);
    }
}
int main()
{
    const int maxsize = 10;
    int size;
    cout << "Enter your array size: ";
    cin >> size;

    if (size > maxsize) {
        cout << "Size exceeds maximum allowed size of " << maxsize << ". Exiting.\n";
        return 1;
    }

    int array[maxsize];
    cout << "Enter your array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    quickSort(array, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
