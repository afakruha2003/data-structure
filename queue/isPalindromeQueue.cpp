#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string word)
{
    stack<char> s;
    queue<char> q;

    for (char ch : word)
    {
        q.push(ch);
        s.push(ch);
    }
    while (!q.empty())
    {
        if (q.front() == s.top())
        {

            q.pop();
            s.pop();
        }
        else
        {
            return false;
        }
    }

    return q.empty();
}
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isNumericPalindrome(int number) {
    queue<int> q;
    stack<int> s;

    // Rakamları kuyruğa ve yığına ekle
    while (number > 0) {
        int digit = number % 10;
        q.push(digit);
        s.push(digit);
        number /= 10;
    }

    // Kuyruk ve yığından çıkararak kontrol et
    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }
        q.pop();
        s.pop();
    }

    return true;
}

int main()
{
    string word = "mumu";
    if (isPalindrome(word))
    {
        cout << word << " is a palindrome!" << endl;
    }
    else
    {
        cout << word << " is not a palindrome!" << endl;
    }
}