#include <iostream>
#include <queue>
using namespace std;

int main() {

    // Creation of min heap
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(100);
    pq.push(90);
    pq.push(70);

    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;

    cout << "Size: " << pq.size() << endl;

    if(pq.empty()) {
        cout << "Empty" << endl;
    }
    else {
        cout << "Not empty" << endl;
    }

    return 0;
}