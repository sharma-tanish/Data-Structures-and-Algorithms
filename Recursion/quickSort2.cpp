#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if(low >= high) {
        return;
    }
    int pivot = high;
    int i = low - 1;
    int j = low;
    while(j < pivot) {
        if(arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}