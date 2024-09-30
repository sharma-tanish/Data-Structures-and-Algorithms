#include <iostream>
using namespace std;

void print(int *ptr) {
    cout << "Address: " << ptr << endl;
    cout << "Value: " << *ptr << endl;
}

void update(int *ptr) {
    // ptr = ptr + 1;
    // cout << "Inside update function: " << ptr << endl;
    *ptr = *ptr + 1;
}

int getSum(int *arr, int n) {
    cout << "Size: " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int var = 5;
    int *ptr = &var;
    
    print(ptr);

    cout << "Before updation: " << *ptr << endl;
    update(ptr);
    cout << "After updation: " << *ptr << endl;

    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << getSum(arr + 3, 3) << endl; 
    return 0;
}