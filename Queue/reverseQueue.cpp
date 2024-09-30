#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverse(queue<int> &q) {
    stack<int> st;
    while(!q.empty()) {
        int frontElement = q.front();
        q.pop();
        st.push(frontElement);
    }
    while(!st.empty()) {
        int topElement = st.top();
        st.pop();
        q.push(topElement);
    }
}

void recursiveReverse(queue<int> &q) {
    if(q.empty()) {
        return;
    }
    int temp = q.front();
    q.pop();
    recursiveReverse(q);
    q.push(temp);
}

int main() {
    
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    // reverse(q);
    recursiveReverse(q);

    while(!q.empty()) {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;

    return 0;
}