#include <iostream>
#include <queue>
using namespace std;

int main() {

    // Based on max heap
    priority_queue<int> pMax;

    // Based on min heap
    priority_queue<int, vector <int>, greater <int> > pMin;

    pMax.push(1);
    pMax.push(3);
    pMax.push(2);
    pMax.push(0);

    cout << "pMax Size: " << pMax.size() << endl;

    int pMaxSize = pMax.size();
    cout << "Printing pMax:" << endl;
    for(int i = 0; i < pMaxSize; i++) {
        cout << pMax.top() << " ";
        pMax.pop();
    }
    cout << endl;

    pMin.push(5);
    pMin.push(1);
    pMin.push(3);
    pMin.push(2);
    pMin.push(0);

    cout << "pMin Size: " << pMin.size() << endl;

    int pMinSize = pMin.size();
    cout << "Printing pMin:" << endl;
    for(int i = 0; i < pMinSize; i++) {
        cout << pMin.top() << " ";
        pMin.pop();
    }
    cout << endl;

    cout << "Empty or not? " << pMax.empty() << endl;
    cout << "Empty or not? " << pMin.empty() << endl;

    return 0;
}