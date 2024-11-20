#include <iostream>
using namespace std;

template <class Item>
void bubbleSort(Item a[], int n)
{
    bool sorted = false;
    int last = n - 1;
    for (int i = 0; (i < last) && !sorted; i++)
    {
        sorted = true;
        for (int j = last; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j], a[j - 1]);
                sorted = false;
            }
        }
    }
}

template <class Object>
void swap(Object *lhs, Object *rhs)
{
    Object tmp = *lhs;
    *lhs = *rhs;
    rhs = tmp;
}


void bubble(int arr[], int n)
{

    bool sorted = false;
    for (int i = 0; i < n - 1 && !sorted; i++)
    { 
        sorted=true;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            
        }
    }
}

int main()
{
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, n);

    cout << "Bubble Sort ile sıralanmış dizi: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}




