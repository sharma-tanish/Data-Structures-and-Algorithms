#include <iostream>
using namespace std;

int var = 15;

void a(int &i) {
    cout << var << " in a" << endl;
    var++;
    cout << i << endl;
}

void b(int &i) {
    cout << var << " in b" << endl;
    cout << i << endl;
}

int main() {
    int i = 5;
    cout << var << " in main" << endl;
    a(i);
    b(i);
    {
        int var = 23;
        cout << var << endl;
        cout << ::var << endl;
    }
    return 0;
}