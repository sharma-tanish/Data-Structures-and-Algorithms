#include <iostream>
#include <deque>
using namespace std;

//aka Double Ended Queue

int main() {

    deque<int> d;
    d.push_front(2);
    d.push_front(1);
    d.push_back(3);
    d.push_back(4);

    cout << "Printing d:" << endl;
    for(int i: d) {
        cout << i << " ";
    }
    cout << endl;

    // d.pop_back();
    // d.pop_front;

    // for(int i: d) {
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << "Element at 1st index: " << d.at(1) << endl; 

    cout << "First element: " << d.front() << endl;
    cout << "Last element: " << d.back() << endl;

    cout << "Empty or not? " << d.empty() << endl;

    cout << "Size before erasing: " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "Size after erasing: " << d.size() << endl;

    cout << "Printing d:" << endl;
    for(int i: d) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}