#include <iostream>
#include <algorithm>
using namespace std;

int lonConsecutive(int array2[5]);

int main()
{
    int array1[5]{1, 2, 5, 12,6};
    size_t size = 5;
    cout << lonConsecutive(array1) << endl;
    return 0;
}
int lonConsecutive(int array2[5])
{
    size_t size = 5;
    sort(array2, array2 + size);
    int longestS{1};
    int currentS{1};
    for (size_t i = 0; i < currentS; i++)
    {
        if (array2[i] + 1 == array2[i + 1])
        {
            currentS += 1;
        }
        if (currentS > longestS)
        {
            longestS = currentS;
        }
    }
    return longestS;
}
//T(n)=O(nlogn)

