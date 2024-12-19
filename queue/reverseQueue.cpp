#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

void reversestring(string &word)
{
    queue<char> q;
    stack<char> s;
    string reversed = "";
    for (char ch : word)
    {
        s.push(ch);
    }
    while (!s.empty())
    {
        q.push(s.top());
        reversed += s.top();
        s.pop();
    }

    word = reversed;
    cout << "reversed word is :" << word;
}

int main()
{
    string word = "mamy";
    reversestring(word);
}