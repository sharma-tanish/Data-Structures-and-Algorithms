#include <iostream>
using namespace std;

int getSum(int arr[], int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return arr[0];
    }
    int sum = arr[0] + getSum(arr + 1, n - 1);
    return sum;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Sum: " << getSum(arr, n) << endl;
    delete[] arr;
    return 0;
}