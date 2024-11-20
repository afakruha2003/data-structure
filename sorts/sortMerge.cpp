#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <class DataType>
void merge(DataType theArray[], int first, int mid, int last)
{

    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int index = first1;
    DataType tempArray[MAX_SIZE]; //! important
    
    // Merging two sorted halves into tempArray using for loops
    for (; first1 <= last1 && first2 <= last2; ++index)
    {
        if (theArray[first1] < theArray[first2])
        {
            tempArray[index] = theArray[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }

    // Copy any remaining elements from the first half
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
    }

    // Copy any remaining elements from the second half
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
    }

    // Copy the merged array back into the original array
    for (index = first; index <= last; ++index)
    {
        theArray[index] = tempArray[index];
    }
}

template <class DataType>
void mergeSort(DataType theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(theArray, first, mid);
        mergeSort(theArray, mid + 1, last);
        merge(theArray, first, mid, last);
    }
}

int main()
{
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "Merge Sort ile sıralanmış dizi: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
