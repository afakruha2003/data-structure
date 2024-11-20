#include <iostream>
#include <utility> //! Include this to use std::swap
using namespace std;

template <class T>
int partition(T a[], int first, int last)
{
*
    int pivotIndex = first;
    T pivot = a[pivotIndex];
    int left = first;
    for (int i = first + 1; i <= last; i++)
    {
        if (a[i] < pivot)
        {
            ++left;
            swap(a[i], a[left]);
        }
    }
    
    swap(a[first], a[left]);
    return left;
}

template <class T>
void quickSort(T a[], int first, int last)
{

    if (first < last)
    {
        int pivotIndex = partition(a, first, last);
        quickSort(a, first, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, last);
    }
}

/*
template <class DataType>
int partition(DataType theArray[], int first, int last) {
    int pivotIndex = first;
    DataType pivot = theArray[pivotIndex];
    int lastS1 = first;

    for (int i = first + 1; i <= last; ++i) {
        if (theArray[i] < pivot) {
            ++lastS1;
            std::swap(theArray[i], theArray[lastS1]);
        }
    }
    std::swap(theArray[first], theArray[lastS1]);
    return lastS1;
}


template <class DataType>
void quickSort(DataType theArray[], int first, int last) {
    if (first < last) {
        int pivotIndex = partition(theArray, first, last);
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }
}
*/
int main()
{
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    cout << "Quick Sort ile sıralanmış dizi: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
