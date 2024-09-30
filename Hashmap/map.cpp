#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    // Creation
    unordered_map<string, int> mapping;

    // Insertion
    pair<string, int> p = make_pair("Tanish", 21);
    
    pair<string, int> q("Dipansh", 20);
    
    pair <string, int> r;
    r.first = "Radhika";
    r.second = 19;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    mapping["Sharma"] = 32;

    cout << "Size of map: " << mapping.size() << endl;

    // Access
    cout << mapping.at("Tanish") << endl;
    cout << mapping["Tanish"] << endl;

    // Searching
    cout << mapping.count("Love") << endl;

    if(mapping.find("Babbar") != mapping.end()) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    cout << "Size of map: " << mapping.size() << endl;
    cout << mapping["Kumar"] << endl;
    cout << "Size of map: " << mapping.size() << endl;

    return 0;
}