#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {

    int pivot = arr[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at right position
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    // Satisfying condition: < a | a | > a
    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int start, int end) {

    // Base case
    if(start >= end) {
        return;
    }

    // Partition
    int index = partition(arr, start, end);

    // Sort left half of the array
    quickSort(arr, start, index - 1);

    // Sort right half of the array
    quickSort(arr, index + 1, end);

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