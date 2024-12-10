#include <iostream>
#include <stack>
using namespace std;

class TextEditor {
    stack<string> undoStack; // Stores states for undo
    stack<string> redoStack; // Stores states for redo

public:
    // Function to type text
    void typeText(string text) {
        undoStack.push(text);  // Save the current state
        while (!redoStack.empty()) redoStack.pop(); // Clear redo history
        cout << "Current Text: " << text << endl;
    }

    // Undo the last action
    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(undoStack.top()); // Move the current state to redo stack
            undoStack.pop(); // Remove the current state
            cout << "Undo Complete. Current Text: " 
                 << (undoStack.empty() ? "[Empty]" : undoStack.top()) << endl;
        } else {
            cout << "Nothing to Undo." << endl;
        }
    }

    // Redo the last undone action
    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(redoStack.top()); // Restore the state from redo stack
            redoStack.pop(); // Remove it from redo stack
            cout << "Redo Complete. Current Text: " << undoStack.top() << endl;
        } else {
            cout << "Nothing to Redo." << endl;
        }
    }
};

int main() {
    TextEditor editor;

    // Perform actions
    editor.typeText("Hello");
    editor.typeText("Hello World");

    // Undo actions
    editor.undo(); // Undo to "Hello"
    editor.undo(); // Undo to "[Empty]"

    // Redo actions
    editor.redo(); // Redo to "Hello"
    editor.redo(); // Redo to "Hello World"

    // Type new text
    editor.typeText("New Text");

    // Undo and redo again
    editor.undo(); // Undo to "Hello World"
    editor.redo(); // Redo to "New Text"

    return 0;
}





/*
#include <iostream>
#include <stack>
using namespace std;

class TextEditor {
    stack<string> states;

public:
    void typeText(string text) {
        states.push(text);
        cout << "Current Text: " << text << endl;
    }

    void undo() {
        if (!states.empty()) {
            states.pop();
            cout << "Undo Complete. Current Text: " 
                 << (states.empty() ? "[Empty]" : states.top()) << endl;
        } else {
            cout << "Nothing to Undo." << endl;
        }
    }
};

int main() {
    TextEditor editor;
    editor.typeText("Hello");
    editor.typeText("Hello World");
    editor.undo(); // Undo to "Hello"
    editor.undo(); // Undo to "[Empty]"
    return 0;
}
*/

/*#include <iostream>
#include <stack>
using namespace std;

void undoSequence() {
    stack<char> undoStack;
    char input;
    cout << "Metni girin (geri almak için '<' karakterini kullanın, bitirmek için '.' karakteri girin):\n";
    while (cin >> input && input != '.') {
        if (input == '<') {
            if (!undoStack.empty())
                undoStack.pop(); // Son karakteri geri al
        } else {
            undoStack.push(input); // Karakteri yığına ekle
        }
    }

    cout << "Son hali: ";
    while (!undoStack.empty()) {
        cout << undoStack.top();
        undoStack.pop();
    }
    cout << endl;
}

int main() {
    undoSequence();
    return 0;
}
*/