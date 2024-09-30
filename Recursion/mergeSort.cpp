#include <iostream>
using namespace std;

void merge(int *arr, int start, int end) {

    int mid = start + (end - start) / 2;
    
    // Find length for left and right arrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create left and right arrays
    int *left = new int[len1];
    int *right = new int[len2];

    // Copying values
    int index = start;
    for(int i = 0; i < len1; i++) {
        left[i] = arr[index];
        index++;
    }

    index = mid + 1;
    for(int i = 0; i < len2; i++) {
        right[i] = arr[index];
        index++;
    }

    // Merge 2 sorted arrays
    int i = 0, j = 0, k = start;

    while(i < len1 && j < len2) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        }
        else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    while(i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;

}

void mergeSort(int *arr, int start, int end) {

    // Base case
    if(start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    // Sort left partition
    mergeSort(arr, start, mid);
    
    // Sort right partition
    mergeSort(arr, mid + 1, end);

    // Merge partitions
    merge(arr, start, end);

}

int main() {

    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;

}