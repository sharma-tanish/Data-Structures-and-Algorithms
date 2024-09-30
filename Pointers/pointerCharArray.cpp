#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;
    // Attention here
    cout << ch << endl;
    
    char *ptr = &ch[0];
    // Prints entire string
    cout << ptr << endl;

    cout << *ptr << endl; 

    char temp = 'z';
    char *p = &temp;
    cout << p << endl;
    cout << *p << endl;
    return 0;
}