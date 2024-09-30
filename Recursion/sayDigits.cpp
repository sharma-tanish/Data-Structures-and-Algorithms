#include <iostream>
using namespace std;

void sayDigits(string arr[], int n) {
    if(n == 0) {
        return;
    }
    int lastDigit = n % 10;
    n = n / 10;
    sayDigits(arr, n);
    cout << arr[lastDigit] << " ";
} 

int main() {
    int n;
    cin >> n;
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    sayDigits(arr, n);
    cout << endl;
    return 0;
}