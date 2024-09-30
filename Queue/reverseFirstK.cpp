#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if(k > q.size() || k == 0) {
        return;
    }
    // Push first k elements from Q to S
    stack<int> st;
    for(int i = 0; i < k; i++) {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    // Push all k elements from S to Q
    while(!st.empty()) {
        int element = st.top();
        st.pop();
        q.push(element);
    }
    // Place first (n - k) elements from front to rear in Q
    for(int i = 0; i < q.size() - k; i++) {
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

int main() {
    
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseFirstK(q, 4);

    while(!q.empty()) {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;

    return 0;
}