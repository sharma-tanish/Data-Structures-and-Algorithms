#include <iostream>
#include "MyString.h"
#include <string>

using namespace std;

int main()
{
    MyString a = "Tanish";
    MyString b = " Sharma";
    a+=b;
    cout<<a<<endl;

    a.erase(70, 1);
    cout<<a<<endl;

    // string a = "Tanish";
    // string b = " Sharma";
    // string c = a + b;
    // cout<<c<<endl;
    return 0;
}