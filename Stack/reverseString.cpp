#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "Tanish Sharma";

    string result = "";

    stack<char> st;

    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    while(!st.empty()) {
        result.push_back(st.top()); 
        st.pop();
    }

    cout << result << endl;

    return 0;
}