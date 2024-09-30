#include <iostream>
#include <string>
using namespace std;

char getMaxOccuringChar(string str) {
    char arr[26] = {0};
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int index = 0;
        index = ch - 'a';
        arr[index]++;
    }
    int maximum = -1, ans = 0;
    for (int i = 0; i < 26; i++) {
        if (maximum < arr[i]) {
            ans = i;
            maximum = arr[i];
        }
    }
    int result = ans + 'a';
    return result;
}