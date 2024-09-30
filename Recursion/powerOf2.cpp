#include <iostream>
using namespace std;

int powerOf2(int n) {
    // Base case
    if(n == 0) {
        return 1;
    }
    return 2 * powerOf2(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << powerOf2(n) << endl;
    return 0;
}