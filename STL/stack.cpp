#include <iostream>
#include <stack>
using namespace std;

// Last In First Out (LIFO)

int main() {

    stack<string> s;
    s.push("Tanish");
    s.push("Ravinder");
    s.push("Anju");

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element: " << s.top() << endl;

    cout << "Size: " << s.size() << endl;

    cout << "Empty or not? " << s.empty() << endl;

    return 0;
}