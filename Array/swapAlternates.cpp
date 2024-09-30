#include <iostream>
using namespace std;

void swapAlternates(int arr[], int n) {
    for(int i = 0; i < n; i += 2){
        if(i + 1 < n){
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    swapAlternates(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}