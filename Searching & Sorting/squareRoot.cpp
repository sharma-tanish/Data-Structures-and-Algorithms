#include <iostream>
using namespace std;

long long int sqrtInteger(int n) {
    int start = 0;
    int end = n;
    long long int ans = -1;
    while(start <= end) {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if(square > n) {
            end = mid - 1;
        }
        else if(square < n) {
            ans = mid;
            start = mid + 1;
        }
        else {
            return mid;
        }
    }
    return ans;
}

double sqrtDecimal(int n, int precisionCount, int temp) {
    double factor = 1;
    double ans = temp;
    for(int i = 0; i < precisionCount; i++) {
        factor = factor / 10;
        for(double j = ans; j * j < n; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int precisionCount;
    cout << "Enter precision count: ";
    cin >> precisionCount;
    int temp = sqrtInteger(n);
    cout << "Square root: " << sqrtDecimal(n, precisionCount, temp) << endl;
    return 0;
}