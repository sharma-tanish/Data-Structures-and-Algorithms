#include <iostream>
using namespace std;

int countWays(int n, int k) {
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return k + k * (k - 1);
    }
    return (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k));
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k) << endl;
    return 0;
}