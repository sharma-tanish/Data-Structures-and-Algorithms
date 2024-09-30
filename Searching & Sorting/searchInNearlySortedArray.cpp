#include <iostream>
using namespace std;

int searchInNearlySortedArray(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(mid - 1 >= 0 && arr[mid - 1] == target) {
            return mid - 1;
        }
        else if(arr[mid] == target) {
            return mid;
        }
        else if(mid + 1 < n && arr[mid + 1] == target) {
            return mid + 1;
        }
        else if(target > arr[mid]) {
            start = mid + 2;
        }
        else {
            end = mid - 2;
        }
    }
    return -1;
}

int main() {
    // Example testcase: 20 10 30 50 40 70 60
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << searchInNearlySortedArray(arr, n, target) << endl;
    return 0;
}