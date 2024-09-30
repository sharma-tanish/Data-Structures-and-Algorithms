#include <iostream>
using namespace std;

void separateEven(int arr[], int n, int index, vector<int> &ans) {
    if(index >= n) {
        return;
    }
    if((arr[index] & 1) != 1) {
        ans.push_back(arr[index]);
    }
    separateEven(arr, n, index + 1, ans);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 0;
    vector<int> ans;
    separateEven(arr, n, index, ans);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}