#include <iostream>
using namespace std;

int minimum(int arr[], int n, int index, int mini) {
    if(index >= n) {
        return mini;
    }
    mini = min(mini, arr[index]);
    return minimum(arr, n, index + 1, mini);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 0, mini = INT_MAX;
    cout << minimum(arr, n, index, mini) << endl;
    return 0;
}