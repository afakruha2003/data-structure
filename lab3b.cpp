#include <iostream>
#include <algorithm>
using namespace std;

int largestCommonElement(int arr1[], int arr2[], size_t, size_t);

int main()
{
    int arr1[3]{2, 4, 9};
    int arr2[5]{2, 8, 9, 12, 5};
    cout << largestCommonElement(arr1, arr2, 5, 3) << endl;
}

int largestCommonElement(int arr1[], int arr2[], size_t size1, size_t size2)
{
    int largestCommon{0};
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (largestCommon < arr1[i])
                {
                    largestCommon = arr1[i];
                }
            }
        }
    }

    return largestCommon;
}
// T(n)=O(n square)