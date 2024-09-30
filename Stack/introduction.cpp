#include <iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(top < size - 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Stack s1(5);

    s1.push(21);
    s1.push(43);
    s1.push(47);
    s1.push(21);
    s1.push(43);
    s1.push(47);
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;

    if(s1.isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}