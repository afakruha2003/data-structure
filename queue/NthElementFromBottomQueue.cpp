#include <iostream>
#include <queue>
using namespace std;

int getNthElementFromBottom(queue<int> &q, int n)
{
    queue<int> tempQueue = q;
    int size = tempQueue.size();

    if (n > size)
    {
        cout << "Invalid position." << endl;
        return -1; // Return -1 for invalid position
    }

    for (int i = 0; i < size - n; ++i)
    {
        tempQueue.pop();
    }

    return tempQueue.front();
}
/*
int getNthElementFromBottom(queue<int> &q, int n)
{
    int size = q.size();
    int elementFromFront = size - n +1;
    queue<int> temp;
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }

    for (size_t i = 1; i < elementFromFront; i++)

    {

        q.push(temp.front());
        temp.pop();
    }
    int result = temp.front();
    for (size_t i = elementFromFront; i <= size; i++)

    {

        q.push(temp.front());
        temp.pop();
    }
    return result;
}*/
int main()
{

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout << getNthElementFromBottom(q, 3);
}