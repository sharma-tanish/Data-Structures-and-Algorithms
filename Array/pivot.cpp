#include <iostream>
using namespace std;

int getPivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] >= arr[0]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return start;
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3};
    int pivot = getPivot(arr, 5);
    cout << arr[pivot] << endl;
    return 0;
}