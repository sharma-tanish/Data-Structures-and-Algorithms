#include <iostream>
using namespace std;

void shiftNegativeToLeft1(int *arr, int n) {
    int left = 0; // Keeps track for negative numbers
    int right = n - 1; // Keeps track for positive numbers
    while(left < right) {
        if(arr[left] < 0) {
            left++;
        }
        else if(arr[right] > 0) {
            right--;
        }
        else {
            swap(arr[left], arr[right]);
        }
    }
}

void shiftNegativeToLeft2(int *arr, int n) {
    int i = 0, j = 0; // i tracks positive number & j tracks negative number
    while(i < n) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    shiftNegativeToLeft1(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}