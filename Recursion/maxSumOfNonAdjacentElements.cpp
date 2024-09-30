#include <iostream>
using namespace std;

int maxSum(int arr[], int size, int index) {
    if(index >= size) {
        return 0;
    }
    int option1 = arr[index] + maxSum(arr, size, index + 2);
    int option2 = 0 + maxSum(arr, size, index + 1);
    return max(option1, option2);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 0;
    cout << maxSum(arr, n, index) << endl;
    return 0;
}