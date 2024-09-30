#include <iostream>
using namespace std;

void passByValue(int n) {
    n++;
}

void passByReference(int &n) {
    n++;
}

int main() {
    int i = 5;
    // Creating a reference variable
    int &j = i;
    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    cout << j << endl;

    int n = 10;
    cout << "Before: " << n << endl;
    passByValue(n);
    cout << "After: " << n << endl;
    
    cout << "Before: " << n << endl;
    passByReference(n);
    cout << "After: " << n << endl;
    return 0;
}