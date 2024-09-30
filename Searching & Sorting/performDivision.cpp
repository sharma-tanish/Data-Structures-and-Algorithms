#include <iostream>
using namespace std;

int divisionInteger(int dividend, int divisor) {
    int start = 0;
    int end = dividend;
    int ans = -1;
    while(start <= end) {
        int quotient = start + (end - start) / 2;
        if(divisor * quotient > dividend) {
            end = quotient - 1;
        }
        else if(divisor * quotient < dividend) {
            ans = quotient;
            start = quotient + 1;
        }
        else {
            return quotient;
        }
    }
    return ans;
}

double divisionDecimal(int dividend, int divisor, int temp, int precisionCount) {
    double factor = 1;
    double ans = temp;
    for(int i = 0; i < precisionCount; i++) {
        factor = factor / 10;
        for(double j = ans; j * divisor < dividend; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int dividend, divisor, precisionCount;
    cin >> dividend >> divisor >> precisionCount;
    int temp = divisionInteger(abs(dividend), abs(divisor));
    double ans = divisionDecimal(abs(dividend), abs(divisor), temp, precisionCount);
    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        cout << ans * -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}