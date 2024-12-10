#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Yığıtı görüntülemek için yardımcı bir fonksiyon
void display(stack<int> stack1) {
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;
}

// Postfix ifadeyi değerlendirme fonksiyonu
int evaluatePostfix(string expr) {
    stack<int> s;

    for (char ch : expr) {
        // Eğer operand ise (sayı), yığıta ekle
        if (isdigit(ch)) {
            int value = ch - '0'; // Karakteri tam sayıya çevir
            s.push(value);
            cout << "Pushed: " << value << endl;
        } 
        // Eğer operatör ise, en üstteki iki elemanı kullanarak hesaplama yap
        else {
            if (s.size() < 2) {
                cerr << "Error: Invalid postfix expression." << endl;
                return -1;
            }

            int operand2 = s.top(); s.pop(); // İkinci operand (yığıttan çıkar)
            int operand1 = s.top(); s.pop(); // Birinci operand (yığıttan çıkar)
            int result = 0;

            // Operatöre göre işlem yap
            if (ch == '+') result = operand1 + operand2;
            else if (ch == '-') result = operand1 - operand2;
            else if (ch == '*') result = operand1 * operand2;
            else if (ch == '/') {
                if (operand2 == 0) {
                    cerr << "Error: Division by zero." << endl;
                    return -1;
                }
                result = operand1 / operand2;
            } else {
                cerr << "Error: Unknown operator " << ch << endl;
                return -1;
            }

            s.push(result); // Sonucu yığıta koy
            cout << "Pushed Result: " << result << endl;
        }
    }

    // Yığıtta tek bir eleman kalmalı, bu sonuçtur
    if (s.size() != 1) {
        cerr << "Error: Invalid postfix expression." << endl;
        return -1;
    }

    return s.top();
}

// Ana fonksiyon
int main() {
    string expr;
    cout << "Please enter the postfix expression: ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    if (result != -1) {
        cout << "The result is: " << result << endl;
    }

    return 0;
}
