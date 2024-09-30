#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end) {

    int mid = start + (end - start) / 2;

    vector<int> temp;      // Temporary array
    
    int left = start;      // Starting index of left half of arr
    int right = mid + 1;   // Starting index of right half of arr

    // Storing elements in the temporary array in a sorted manner
    while(left <= mid && right <= end) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If elements on the left half are still left
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If elements on the right half are still left 
    while(right <= end) {
        temp.push_back(arr[right]);
        right++;
    }

    // Transfering all elements from temporary to arr 
    for(int i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }

}

void mergeSort(vector<int> &arr, int start, int end) {

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

    int n, element;
    vector<int> arr;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }

    mergeSort(arr, 0, n - 1);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;

    return 0;

}