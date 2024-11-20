#include <iostream>
using namespace std;

template <class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class Obj>
void merge(Obj a[], int first, int mid, int last)
{
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    Obj temp[100];
    for (; ((first1 <= last1) && (first2 <= last2)); ++index)
    {

        if (a[first1] < a[first2]) // if (first1 < first2)
        {
            temp[index] = a[first1];
            ++first1;
        }
        else
        {
            temp[index] = a[first2];
            ++first2;
        }
    }
    for (; first1 <= last1; ++first1, ++index)
    {
        temp[index] = a[first1];
    }
    for (; first2 <= last2; ++first2, ++index)
    {
        temp[index] = a[first2];
    }
    for (index = first; index <= last; ++index)
    {
        a[index] = temp[index];
    }
}

template <class Item>
void mergeSort(Item a[], int first, int last)
{
    if (first < last) //
    {
        int mid = (last + first) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

template <class Items>
void selectionSort(Items a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min]) //
            {
                min = j;
            }
        }
        swap(&a[min], &a[i]); //
    }
}
template <class Object>
void insertionSort(Object a[], int size)
{

    for (int i = 1; i < size; i++)
    {
        Object temp = a[i];
        int j;
        for (j = i; (j > 0) && (temp < a[j - 1]); j--) //
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}
int main()
{
    const int maxsize = 10;
    int size;

    cout << "Enter your array size (max 10): ";
    cin >> size;

    if (size > maxsize)
    {
        cout << "Size exceeds maximum allowed size of " << maxsize << ". Exiting.\n";
        return 1;
    }

    int arr[maxsize];
    cout << "Enter your array elements:" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    if (size <= 4)
    {
        insertionSort(arr, size);
    }
    else if (size >= 5 && size <= 8)
    {
        selectionSort(arr, size);
    }
    else if (size >= 9)
    {
        mergeSort(arr, 0, size - 1);
    }

    cout << "Sorted array: ";
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}