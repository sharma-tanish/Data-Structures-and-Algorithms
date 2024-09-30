#include <iostream>
using namespace std;

int exponentiation(int a, int b) {
    if(b == 0) {
        return 1;
    }
    if(b == 1) {
        return a;
    }
    int ans = exponentiation(a, b / 2);
    if(b % 2 == 0) {
        return ans * ans;
    }
    else {
        return a * (ans * ans);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << exponentiation(a, b) << endl;
    return 0;
}