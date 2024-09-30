#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int minMaxSum(vector<int> &nums, int k) {
    deque<int> dq, dq2; // dq stores maximum element & dq2 stores minimum element
    int ans = 0;

    // Process first window
    for(int i = 0; i < k; i++) {
        int element = nums[i];
        while(!dq.empty() && element > nums[dq.back()]) {
            dq.pop_back();
        }
        while(!dq2.empty() && element < nums[dq2.back()]) {
            dq2.pop_back();
        }
        dq.push_back(i);
        dq2.push_back(i);
    }

    // Process remaining window
    for(int i = k; i < nums.size(); i++) {
        // Answer ko store karlo
        ans = ans + nums[dq.front()] + nums[dq2.front()];

        // Removal of out of range elements
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }
        if(!dq2.empty() && i - dq2.front() >= k){
            dq2.pop_front();
        }

        // Removal of smaller elements
        int element = nums[i];
        while(!dq.empty() && element > nums[dq.back()]){
            dq.pop_back();
        }
        // Removal of larger elements
        while(!dq2.empty() && element < nums[dq2.back()]){
            dq2.pop_back();
        }

        // Addition
        dq.push_back(i);
        dq2.push_back(i);
    }

    // Last window ka answer store karlo
    ans = ans + nums[dq.front()] + nums[dq2.front()];
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(-1);
    v.push_back(7);
    v.push_back(-3);
    v.push_back(-1);
    v.push_back(-2);

    int k = 4;

    cout << minMaxSum(v, k) << endl;
}