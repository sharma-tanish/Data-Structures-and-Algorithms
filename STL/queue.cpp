#include <iostream>
#include <queue>
using namespace std;

// First In First Out (FIFO)

int main() {

    queue<string> q;
    q.push("Tanish");
    q.push("Ravinder");
    q.push("Anju");

    cout << "First element: " << q.front() << endl;

    cout << "Size before pop operation: " << q.size() << endl;
    q.pop();
    cout << "First element: " << q.front() << endl;

    cout << "Size after pop operation: " << q.size() << endl;

    cout << "Empty or not? " << q.empty() << endl;

    return 0;
}