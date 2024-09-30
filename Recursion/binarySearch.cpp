#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int k) {
    if(start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if(arr[mid] == k) {
        return mid;
    }
    if(arr[mid] < k) {
        return binarySearch(arr, mid + 1, end, k);
    } 
    else {
        return binarySearch(arr, start, mid - 1, k);
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int start = 0;
    int end = n - 1;
    cout << binarySearch(arr, start, end, k) << endl;
    delete[] arr;
    return 0;
}