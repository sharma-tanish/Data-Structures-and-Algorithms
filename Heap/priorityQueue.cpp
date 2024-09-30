#include <iostream>
#include <queue>
using namespace std;

int main() {

    // Creation of max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "Top element: " << pq.top() << endl;

    cout << "Size: " << pq.size() << endl;

    cout << pq.empty() << endl;

    return 0;
}