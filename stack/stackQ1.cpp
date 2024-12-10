#include <iostream>
#include <stack>
#include <climits> // INT_MIN için gerekli
#define MAX 1000
using namespace std;
class Stack
{
    int top;
    int arr[MAX]; // Maximum size of Stack
public:
    Stack() : top(-1) {}
    void push(int);
    bool isEmpty();
    int pop();
    int findTop();
    void display();
    void sortStack();
};
bool Stack::isEmpty()
{
    return top < 0;
}
void Stack::push(int value)
{
    arr[++top] = value;
}
int Stack::findTop()
{
    int x = arr[top];
    return x;
}
int Stack::pop()
{
    if (!isEmpty())
    {
        int x = arr[top--];
        return x;
    }
    return INT_MIN;
}
void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements (top to bottom):" << endl;
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }
}

void Stack::sortStack()
{
    Stack tempStack; // Geçici yığın
    while (!isEmpty())
    {
        int temp = pop(); // Mevcut yığından eleman al
        while (!tempStack.isEmpty() && tempStack.findTop() > temp)
        {
            push(tempStack.pop()); // Elemanları geri taşı
        }
        tempStack.push(temp); // Geçici yığına ekle
    }
    // Geçici yığındaki elemanları geri taşı
    while (!tempStack.isEmpty())
    {
        push(tempStack.pop());
    }
}
// Reversing a Stack
void reverseStack(stack<int> &s)
{
    stack<int> tempStack;
    while (!s.empty())
    {
        tempStack.push(s.top());
        s.pop();
    }
    s = tempStack;
}
// Average of Stack Elements
double calculateAverage(stack<int> s)
{
    double sum = 0;
    int count = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
        count++;
    }
    return count == 0 ? 0 : sum / count;
}

// Maximum in Stack
int findMax(stack<int> s)
{
    int maxVal = s.top();
    s.pop();
    while (!s.empty())
    {
        if (s.top() > maxVal)
            maxVal = s.top();
        s.pop();
    }
    return maxVal;
}

// Find the Middle Element
int findMiddle(stack<int> s)
{
    int size = s.size();
    int midIndex = size / 2;
    for (int i = 0; i < midIndex; ++i)
    {
        s.pop();
    }
    return s.top();
}

// Delete the Middle Element
void deleteMiddle(stack<int> &s)
{
    int size = s.size();
    int midIndex = size / 2;
    stack<int> tempStack;

    for (int i = 0; i < midIndex; ++i)
    {
        tempStack.push(s.top());
        s.pop();
    }

    s.pop(); // Remove the middle element

    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Find and Remove the Largest Element
void removeLargest(stack<int> &s)
{
    stack<int> tempStack;
    int maxVal = INT_MIN;

    // Find the largest element
    while (!s.empty())
    {
        if (s.top() > maxVal)
            maxVal = s.top();
        tempStack.push(s.top());
        s.pop();
    }

    // Rebuild stack without the largest element
    while (!tempStack.empty())
    {
        if (tempStack.top() != maxVal)
            s.push(tempStack.top());
        tempStack.pop();
    }
}

// Find and Remove the Lowest Element
void removeLowest(stack<int> &stackObj)
{
    int min = INT_MIN;
    stack<int> temp;
    while (!stackObj.empty())
    {
        if (stackObj.top() < min)
        {
            min = stackObj.top();
        }
        temp.push(stackObj.top());
        stackObj.pop();
    }
    while (!temp.empty())
    {
        if (temp.top() != min)
        {
            stackObj.push(temp.top());
        }

        temp.pop();
    }
}

// Delete All Occurrences of an Item
void deleteOccurrences(stack<int> &s, int target)
{
    stack<int> tempStack;

    while (!s.empty())
    {
        if (s.top() != target)
        {
            tempStack.push(s.top());
        }
        s.pop();
    }

    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Get the Kth Element from the Top
int getKthElement(stack<int> s, int k)
{
    for (int i = 1; i < k; ++i)
    {
        s.pop();
    }
    return s.top();
}

// Replace the Kth Element
void replaceKthElement(stack<int> &s, int k, int newValue)
{
    stack<int> tempStack;

    for (int i = 1; i < k; ++i)
    {
        tempStack.push(s.top());
        s.pop();
    }

    s.pop();          // Remove the kth element
    s.push(newValue); // Add the new value

    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
int main()
{
    Stack stack1;
    stack1.push(2);
    stack1.push(1);
    stack1.push(4);
    stack1.push(3);

    cout << "Stack elements before sorting:" << endl;
    stack1.display();

    // Sıralama işlemi
    stack1.sortStack();

    cout << "Stack elements after sorting:" << endl;
    stack1.display();

    return 0;
}
