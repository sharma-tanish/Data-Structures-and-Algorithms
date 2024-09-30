#include <iostream>
#include <stack>

using namespace std;

void sortedInsert(stack<int> &st, int element) {
    if(st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, temp);
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(5);
    st.push(12);
    st.push(8);
    st.push(9);
    st.push(17);
    
    sortStack(st);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}