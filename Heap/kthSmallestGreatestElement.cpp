#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int arr[], int n, int k) {
    priority_queue<int> pq;
    // First k elements ko process kardo
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    // Remaining elements ko tabhi insert karenge jab vo root se chote honge
    for(int i = k; i < n; i++) {
        if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int kthGreatestElement(int arr[], int n, int k) {
    priority_queue<int> pq;
    // First k elements ko process kardo
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    // Remaining elements ko tabhi insert karenge jab vo root se bade honge
    for(int i = k; i < n; i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main() {

    int arr[] = {3, 5, 4, 6, 9, 8, 7};
    int n = 7;
    int k = 4;
    cout << kthSmallestElement(arr, n, k) << endl;
    cout << kthGreatestElement(arr, n, k) << endl;

    return 0;
}