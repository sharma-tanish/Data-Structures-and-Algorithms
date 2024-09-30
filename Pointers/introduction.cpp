#include <iostream>
using namespace std;

int main() {
    int num = 5;
    cout << num << endl;

    cout << "Address of num: " << &num << endl;

    int *ptr = &num;

    cout << "Address: " << ptr << endl;
    cout << "Value: " << *ptr << endl;

    double d = 4.3;
    double *ptr2 = &d;

    cout << "Address: " << ptr2 << endl;
    cout << "Value: " << *ptr2 << endl;

    cout << "Size of integer: " << sizeof(num) << endl;
    cout << "Size of pointer: " << sizeof(ptr) << endl;
    cout << "Size of pointer: " << sizeof(ptr2) << endl;
    return 0;
}