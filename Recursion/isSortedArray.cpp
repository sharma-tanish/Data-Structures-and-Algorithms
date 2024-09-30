#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int index) {
    // Base case
    if(index >= n) {
        return true;
    }
    if(arr[index - 1] > arr[index]) {
        return false;
    }
    return isSorted(arr, n, index + 1);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 1;
    if(isSorted(arr, n, index)) {
        cout << "Sorted" << endl;
    }
    else {
        cout << "Unsorted" << endl;
    }
    delete[] arr;
    return 0;
}