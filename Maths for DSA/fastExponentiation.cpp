#include <iostream>
using namespace std;

int fastExponentiation(int a, int b) {
	int ans = 1;
    while(b > 0) {
        if(b & 1) {
            // Odd
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return ans;
}
// O(log b)

int main() {
    int a, b;
    cin >> a >> b;
    cout << fastExponentiation(a, b) << endl;
}