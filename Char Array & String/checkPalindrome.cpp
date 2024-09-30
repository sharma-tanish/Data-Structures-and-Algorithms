#include <iostream>
using namespace std;

bool isValid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return 1;
    }
    return 0;
}

char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    else {
        return ch;
    }
}

bool isPalindrome(string s) {
    int start = 0;
    int end = s.length() - 1;
    while (start <= end) {
        if (s[start] == s[end]) {
            start++;
            end--;
        }
        else {
            return 0;
        }
    }
    return 1;
}

bool checkPalindrome(string s) {
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (isValid(s[i])) {
            temp.push_back(s[i]);
        }
    }
    for (int i = 0; i < temp.length(); i++) {
        temp[i] = toLowerCase(temp[i]);
    }
    return isPalindrome(temp);
}

int main() {
    string s;
    // cin >> s;
    getline(cin, s);
    cout << checkPalindrome(s) << endl;
}