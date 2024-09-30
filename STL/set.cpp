#include <iostream>
#include <set>
using namespace std;

// Stores unique element
// Implementation is done using BST
// Element can't be modified once inserted
// Elements are returned in sorted order
// Set is slow compared to Unordered Set
// Elements are returned randomly in Unordered Set

int main() {

    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(2);

    cout << "Printing s:" << endl;
    for(auto i: s) {
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);

    cout << "Printing s:" << endl;
    for(auto i: s) {
        cout << i << " ";
    }
    cout << endl;

    cout << "5 is present or not? " << s.count(5) << endl;
    cout << "-5 is present or not? " << s.count(-5) << endl;

    set<int>::iterator it2 = s.find(5);
    cout << "Value of it2: " << *it2 << endl;

    for(auto i=it2; i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}