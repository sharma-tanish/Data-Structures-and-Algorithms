#include <iostream>
using namespace std;

int getSum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    // Variable size array
    int *arr = new int[n];

    // Taking input in array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sum: " << getSum(arr, n) << endl;

    // Manually releasing the allocated memory in heap
    delete[] arr;

    // // BAD PRACTICE!
    // // Case 1
    // while(true) {
    //     int i = 5;
    // }
    
    // // Case 2
    // while(true) {
    //     int* ptr = new int;
    // }
    return 0;
}