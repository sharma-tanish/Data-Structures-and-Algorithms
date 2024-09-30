#include <iostream>
using namespace std;

void func(int array[], int size) {
    cout << array << endl;
    cout << &array << endl; // Address changes here!
}

int main() {
    int arr[10] = {23, 122, 41, 67};

    cout << "Address of first memory block: " << arr << endl;
    cout << arr[0] << endl;
    cout << "Address of first memory block: " << &arr[0] << endl;
    cout << "Value at arr[0]: " << *arr << endl;
    cout << *arr + 1 << endl;
    cout << "Value at arr[1]:  " << *(arr + 1) << endl;
    cout << *(arr) + 1 << endl;
    cout << "Value at arr[2]: " << arr[2] << endl;
    cout << "Value at arr[2]: " << *(arr+2) << endl;

    int i = 3;
    cout << "Value at arr[3]: " << i[arr] << endl;

    int temp[10] = {1, 2};
    cout << sizeof(temp) << endl;
    cout <<  sizeof(*temp) << endl;
    cout <<  sizeof(&temp) << endl;

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl ;
    cout << sizeof(*ptr) << endl ;
    cout << sizeof(&ptr) << endl ;

    int a[20] = {1, 2, 3, 5};
    cout << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;

    int arr2[10];
    // ERROR
    // arr = arr + 1;

    int *ptr2 = &arr2[0];
    cout << ptr2 << endl;
    ptr2 = ptr2 + 1;
    cout << ptr2 << endl;

    int arr3[5] = {1, 2, 3, 4, 5};
    int (*ptr3)[5] = &arr3;
    cout << (*ptr3)[0] << endl;

    // Array of pointer
    int* ptr4[5];
    ptr4[0] = &arr3[0];
    ptr4[1] = &arr3[1];
    ptr4[2] = &arr3[2];
    ptr4[3] = &arr3[3];
    ptr4[4] = &arr3[4];
    cout << *ptr4[0] << endl;

    int array[] = {10, 20, 30, 40, 50};
    func(array, 5);
    cout << array << endl;
    cout << &array << endl;
    return 0;
}