#include <iostream>
#include <queue>
using namespace std;

int FindPositionElementQueue(queue<int> &q, int n)
{
    queue<int> tempq = q;
    int position = 1;
    while (!tempq.empty())
    {
        if (tempq.front() == n)
        {
            return position;
        }
        position++;
        tempq.pop();
    }

    return -1;
}
int main()
{
}