#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void dequeue(queue<int> &q, int num)
{
    queue<int> temp;
    while (!q.empty())
    {

        if (q.front() != num)
        {
            temp.push(q.front());
        }

        q.pop();
    }
    while (!temp.empty())
    {

        q.push(temp.front());
        temp.pop();
    }
}

int thirdHighest(queue<int> &q)
{

    int maxNum = 0;
    int maxNum2 = 0;
    int maxNum3 = 0;

    queue<int> temp = q;
    queue<int> temp2 = q;
    queue<int> temp3 = q;
    while (!temp.empty())
    {

        maxNum = max(maxNum, temp.front());
        temp.pop();
    }
    dequeue(temp2, maxNum);
    dequeue(temp3, maxNum);

    while (!temp2.empty())
    {

        maxNum2 = max(maxNum2, temp2.front());
        temp2.pop();
    }

    dequeue(temp3, maxNum2);

    while (!temp3.empty())
    {

        maxNum3 = max(maxNum3, temp3.front());
        temp3.pop();
    }
    return maxNum3;
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
        int number = 0;
        queue<int> q;
        cout << "please enter numbers: " << endl;
        for (int i = 0; i < numElement; i++)
        {
            cin >> number;
            q.push(number);
        }
        queue<int> temp = q;
        cout << "the elements you entered :" << endl;
        while (!temp.empty())
        {
            cout << temp.front() << "  ";
            temp.pop();
        }
        cout << endl;
        cout << "the third max num is :" << thirdHighest(q) << endl;

        cout << "enter the number of extra elements to insert into queue(max 10): ";
        int numElement2 = 0;
        cin >> numElement2;
        if (numElement2 > 10)
        {
            cout << "max 10 numbers enter again" << endl;
            cin >> numElement2;
        }
        else
        {
            int number2 = 0;
            cout << "please enter extra numbers: " << endl;
            for (int i = 0; i < numElement2; i++)
            {
                cin >> number;
                q.push(number);
            }
            queue<int> temp2 = q;
            cout << "the elements you entered :" << endl;
            while (!temp2.empty())
            {
                cout << temp2.front() << "  ";
                temp2.pop();
            }
            cout << endl;
            cout << "the third max num is :" << thirdHighest(q);
        }
    }
}

/*
int thirdHighest(queue<int> &q)
{

    int maxNum = 0;

    queue<int> temp = q;
    queue<int> temp2 = q;
    while (!temp.empty())
    {

        maxNum = max(maxNum, temp.front());
        temp.pop();
    }

    //----------------------------------------------
    queue<int> temp3;
    while (!temp2.empty() && temp2.front() != maxNum)
    {
        temp3.push(temp2.front());

        temp2.pop();
    }
    temp = temp3;

    int maxNum2 = 0;
    while (!temp.empty())
    {

        maxNum2 = max(maxNum2, temp.front());
        temp.pop();
    }
    //----------------------------------------------------
    queue<int> temp4;
    while (!temp3.empty() && temp3.front() != maxNum2)
    {
        temp4.push(temp3.front());

        temp3.pop();
    }
    temp = temp4;

    int maxNum3 = 0;
    while (!temp.empty())
    {

        maxNum3 = max(maxNum3, temp.front());
        temp.pop();
    }

    return maxNum3;
}*/