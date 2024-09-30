#include <iostream>
using namespace std;

int firstOccurence(int *arr, int n, int target) {
    int ans = -1;
    int start = 0;
    int end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target) {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << firstOccurence(arr, n, target) << endl;
    return 0;
}    