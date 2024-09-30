#include <iostream>

using namespace std;

inline void display(int num) {
    cout << num << endl;
}

// Inline fuction surpasses function calling overhead

int main() {
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    display(10);
    return 0;
}