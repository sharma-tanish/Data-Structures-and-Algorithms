#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int> > &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool myComparator1(int &a, int &b) {
    // return a < b; // Increasing order
    return a > b; // Decreasing order
}

bool myComparator2(vector<int> &a, vector<int> &b) {
    // return a[0] < b[0]; // Sorting by 0th index
    return a[1] < b[1]; // Increasing order sorting by 1st index
    // return a[1] > b[1]; // Decreasing order sorting by 1st index
}

int main() {
    // vector<int> v1;
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int element;
    //     cin >> element;
    //     v1.push_back(element);
    // }
    // // sort(v.begin(), v.end()); // Increasing order
    // sort(v1.begin(), v1.end(), myComparator1);
    // printVector(v1);

    vector<vector<int> >v2;
    vector<int> v2a; v2a.push_back(0); v2a.push_back(22);
    vector<int> v2b; v2b.push_back(1); v2b.push_back(11);
    vector<int> v2c; v2c.push_back(0); v2c.push_back(33);
    vector<int> v2d; v2d.push_back(1); v2d.push_back(55);
    vector<int> v2e; v2e.push_back(2); v2e.push_back(44);
    v2.push_back(v2a);
    v2.push_back(v2b);
    v2.push_back(v2c);
    v2.push_back(v2d);
    v2.push_back(v2e);
    // sort(v2.begin(), v2.end()); // Sorting by 0th index
    sort(v2.begin(), v2.end(), myComparator2); // Sorting by 1st index
    printMatrix(v2);
    return 0;
}