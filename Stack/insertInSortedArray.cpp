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

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    
    sortedInsert(st, 32);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}