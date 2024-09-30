#include <iostream>
using namespace std;

int oddOccuringElement(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(start == end) {
            // Single element
            return start;
        }
        else if(mid & 1) {
            // Odd
            if(mid - 1 >= 0 && arr[mid - 1] == arr[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        else {
            // Even
            if(mid + 1 < n && arr[mid] == arr[mid + 1]) {
                // Left part
                start = mid + 2;
            }
            else {
                // Right part or ans
                end = mid;
            }
        }
    }
    return -1;
}

int main() {
    // Example testcase: 10 10 2 2 5 5 2 5 5 20 20 11 11
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << arr[oddOccuringElement(arr, n)] << endl;
    return 0;
}