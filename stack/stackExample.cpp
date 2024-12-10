#include <iostream>
#include <stack>
using namespace std;

void printStackElements(stack<int> stack)
{
    while (!stack.empty())
    {
        cout<<stack.top() <<endl;
        stack.pop();
    }
    
}

int main()
{

    // empy ,size,push,pop,top
    stack<int> numberStack;
    numberStack.push(1);
    numberStack.push(2);
    numberStack.push(3);
    numberStack.pop();
    if (numberStack.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
        cout << "stack size is:" << numberStack.size() << endl;
    }
    printStackElements(numberStack);
}