#include <iostream>
#include <map>
using namespace std;

// Stores data in the form of key : value
// All keys are unique
// One key can't point to multiple values
// Multiple keys can point to one value

int main() {

    map<int, string> m;

    m[1] = "Tanish";
    m[13] = "Anju";
    m[2] = "Ravinder";
    // m.insert({5,"Bheem"});

    cout << "Printing m:" << endl;
    for(auto i: m) {
        cout << i.first << ":" << i.second << " ";
    }
    cout << endl;

    cout << "13 is present or not? " << m.count(13) << endl;
    cout << "-13 is present or not? " << m.count(-13) << endl;

    cout << "Printing m after erase:" << endl;
    m.erase(13);
    for(auto i: m) {
        cout << i.first << ":" << i.second << " ";
    }
    cout << endl;

    auto it = m.find(2);
    for(auto i = it; i != m.end(); i++) {
        cout << (*i).first << endl;
    }

    return 0;
}