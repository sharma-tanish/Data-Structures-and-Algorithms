#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int index, int k) {
    if(index >= n) {
        return -1;
    }
    if(arr[index] == k) {
        return index;
    }
    return linearSearch(arr, n, index + 1, k);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 0;
    int k; 
    cin >> k;
    cout << linearSearch(arr, n, index, k) << endl;
    delete[] arr;
    return 0;
}