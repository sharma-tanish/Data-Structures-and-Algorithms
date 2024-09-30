#include <iostream>
#include <list>
using namespace std;

int main() {

    list<int> l;
    list<int> l2(5, 100);
    l.push_front(2);
    l.push_front(1);
    l.push_back(3);
    l.push_back(4);

    cout << "Printing l:" << endl;
    for(int i: l) {
        cout << i << " ";
    }
    cout << endl;

    l.pop_back();
    l.pop_back();

    cout << "Printing l after pop operation:" << endl;
    for(int i: l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Printing l2:" << endl;
    for(int i: l2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "First element: " << l.front() << endl; 
    cout << "Last element: " << l.back() << endl;

    cout << "Empty or not? " << l.empty() << endl;

    l.erase(l.begin());
    cout << "Printing l after erasing: " << endl;
    for(int i: l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Size: " << l.size() << endl;

    return 0;
}