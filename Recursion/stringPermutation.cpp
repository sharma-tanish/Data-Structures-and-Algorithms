#include <iostream>
using namespace std;

void permutations(string &str, int index) {
    if(index >= str.length()) {
        cout << str << " ";
        return;
    }
    for(int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        permutations(str, index + 1);
        swap(str[index], str[j]);
    }
}

int main() {
    string str;
    cin >> str;
    int index = 0;
    permutations(str, index);
    return 0;
}