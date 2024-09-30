#include <iostream>
using namespace std;

void missingElementWithDuplicates(int *arr, int n) {
    // Visited method
    for(int i = 0; i < n; i++) {
        int index = abs(arr[i]);
        if(arr[index - 1] > 0) {
            // Mark visited
            arr[index - 1] *= -1;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Positive index is the missing element
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            cout << i + 1 << endl;
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
    missingElementWithDuplicates(arr, n);
    return 0;
}