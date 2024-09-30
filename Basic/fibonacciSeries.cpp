#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t1 = 0;
    int t2 = 1;
    cout << t1 << " ";
    cout << t2 << " ";
    for(int i = 1; i <= n - 2; i++) {
        int next = t1 + t2;
        cout << next << " ";
        t1 = t2;
        t2 = next;
    }
    cout << endl;
    return 0;
}