#include <iostream>
using namespace std;

void subsequence(string str, int index, string output, vector<string> &ans) {
    if(index >= str.length()) {
        ans.push_back(output);
        return;
    }
    char ch = str[index];
    // Exclude
    subsequence(str, index + 1, output, ans);
    // Include
    output.push_back(ch);
    subsequence(str, index + 1, output, ans);
}

int main() {
    string str;
    cin >> str;
    string output;
    vector<string> ans;
    int index = 0;
    subsequence(str, index, output, ans);
    cout << "Subsequences:" << endl;
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}