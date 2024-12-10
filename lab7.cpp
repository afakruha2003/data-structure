#include <iostream>
#include <queue>
using namespace std;

void removeEvenNumbers(queue<int> &q)
{
    queue<int> temp1;
    while (!q.empty())
    {
        if (q.front() % 2 == 1)
        {
            temp1.push(q.front());
        }

        q.pop();
    }
    while (!temp1.empty())
    {
        q.push(temp1.front());
        temp1.pop();
    }
}
int main()
{
    cout << "enter the number of elements to insert into queue(max 10): ";
    int numElement = 0;
    cin >> numElement;
    if (numElement > 10)
    {
        cout << "max 10 enter again" << endl;
        cin >> numElement;
    }
    else
    {
        int number=0;
        queue<int> q;
        cout<<"please enter numbers: "<<endl;
        for (int i = 0; i < numElement; i++)
        {
            cin>>number;
            q.push(number);
        }
        queue<int> temp = q;
        cout<<"the eleents you entered :"<<endl;
        while (!temp.empty())
        {
            cout << temp.front()<<"  ";
            temp.pop();
        }
        cout<<endl;
        removeEvenNumbers(q);
        cout<<"only odd number queue :";
        while (!q.empty())
        {
            cout << q.front()<<"  ";
            q.pop();
        }
    }
}