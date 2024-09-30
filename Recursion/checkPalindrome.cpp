#include <iostream>
using namespace std;

bool checkPalindrome(string s, int start, int end) {
    if(start > end) {
        return true;
    }
    if(s[start] != s[end]) {
        return false;
    }
    else {
        return checkPalindrome(s, start + 1, end - 1);
    }
}

int main() {
    string str;
    cin >> str; 
    cout << checkPalindrome(str, 0, str.length() - 1) << endl;
    return 0;
}