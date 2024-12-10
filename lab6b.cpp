#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Yığıtı görüntülemek için yardımcı bir fonksiyon
void display(stack<char> stack1) {
    stack<char> temp = stack1; // Yığıtın bir kopyası
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    cout << endl;
}

// Parantezlerin dengeliliğini kontrol eden fonksiyon
bool isBalanced(string expr) {
    stack<char> s; // Yığıt tanımlama
    for (char ch : expr) {
        // Eğer açılış parantezi ise, yığıta ekle
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
            display(s); // Yığıtın durumunu görüntüle
        } 
        // Eğer kapanış parantezi ise, kontrol et
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                cout << "The stack is empty" << endl;
                return false; // Yığıt boşsa, dengeli değil
            }

            char top = s.top();
            s.pop();

            // Eşleşmeyen parantez durumu
            if ((top == '(' && ch != ')') || 
                (top == '{' && ch != '}') || 
                (top == '[' && ch != ']')) {
                return false;
            }
        }
    }

    // Döngü bittiğinde, yığıt boş olmalı
    return s.empty();
}

int main() {
    string expr;
    cout << "Please enter your string: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "The string is balanced." << endl;
    } else {
        cout << "The string is not balanced." << endl;
    }

    return 0;
}
