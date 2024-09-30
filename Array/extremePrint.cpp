#include <iostream>
using namespace std;

void extremePrint(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while(start <= end){
        if(start == end) {
            cout << arr[start] << endl;
            return;
        }
        cout << arr[start] << " ";
        cout << arr[end] << " ";
        start++;
        end--;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    extremePrint(arr, n);
    return 0;
}