#include <iostream>
using namespace std;

int main() {
    // Null pointer
    int *p = 0;

    int num = 5;
    int a = num;
    cout << "num before a++: " << num << endl;
    a++;
    cout << "num after a++: " << num << endl;

    int *ptr = &num;
    cout << "Before (*ptr)++: " << num << endl;
    (*ptr)++;
    cout << "After (*ptr)++: " << num << endl;

    // Copying a pointer
    int *ptr2 = ptr;
    cout << ptr << " - " << ptr2 << endl;
    cout << *ptr << " - " << *ptr2 << endl;

    // Pointer Arithmetic
    int i = 3;
    int *ptr3 = &i;
    *ptr3 = *ptr3 + 1;
    cout << *ptr3 << endl;
    cout << "Before ptr3++: " << ptr3 << endl;
    ptr3 = ptr3 + 1;
    cout << "After ptr3++: " << ptr3 << endl;
    return 0;
}