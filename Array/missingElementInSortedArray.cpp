#include <iostream>
using namespace std;

int missingElementInSortedArray(int *arr, int n) {
    int ans = -1;
    int start = 0;
    int end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        int difference = arr[mid] - mid;
        if(difference == 1) {
            start = mid + 1;
        }
        else {
            ans = mid;
            end = mid - 1;
        }
    }
    // Special case
    if(ans + 1 == 0) {
        return n + 1;
    }
    return ans + 1;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << missingElementInSortedArray(arr, n) << endl;
    return 0;
}    