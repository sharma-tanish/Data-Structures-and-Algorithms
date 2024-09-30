#include <iostream>
#include <vector>
using namespace std;

int main() {

    // vector<int> v;
    // vector<int> v2(5, 1); // Creates a vector of size 5 and initialises all the values with 1
    // vector<int> v2copy(v2);

    // cout << "Printing v2:" << endl;
    // for(int i:v2) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << "Printing v2copy:" << endl;
    // for(int i:v2copy) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << "Capacity: " << v.capacity() << endl;

    // v.push_back(1);
    // cout << "Capacity: " << v.capacity() << endl;

    // v.push_back(2);
    // cout << "Capacity: " << v.capacity() << endl;

    // v.push_back(3);
    // cout << "Capacity: " << v.capacity() << endl;

    // cout << "Size: " << v.size() << endl;

    // cout << "Element at 2nd index: " << v.at(2) << endl;

    // cout << "First element: " << v.front() << endl;
    // cout << "Last element: " << v.back() << endl;

    // cout << "First element: " << v[0] << endl;
    // cout << "Last element: " << v[v.size() - 1] << endl;

    // cout << "Before pop operation" << endl;
    // for(int i:v) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // v.pop_back();

    // cout << "After pop operation" << endl;
    // for(int i:v) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << "Size before clearing: " << v.size() << endl;
    // v.clear();
    // cout << "Size after clearing: " << v.size() << endl;

    vector<vector<int> > arr1(5, vector<int> (10, -1));

    for(int i = 0; i < arr1.size(); i++) {
        for(int j = 0; j < arr1[i].size(); j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int> > arr2;

    vector<int> arr2a(10, 0);
    vector<int> arr2b(8, 1);
    vector<int> arr2c(5, 0);
    vector<int> arr2d(12, 1);
    vector<int> arr2e(14, 0);

    arr2.push_back(arr2a);
    arr2.push_back(arr2b);
    arr2.push_back(arr2c);
    arr2.push_back(arr2d);
    arr2.push_back(arr2e);

    for(int i = 0; i < arr2.size(); i++) {
        for(int j = 0; j < arr2[i].size(); j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    // Taking input for 1D vector
    // vector<int> v;
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int element;
    //     cin >> element;
    //     v.push_back(element);
    // }


    // Taking input for 2D vector 
    // vector<vector<int> > v;
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int a, b;
    //     cin >> a >> b;
    //     vector<int> temp;
    //     temp.push_back(a); 
    //     temp.push_back(b);
    //     v.push_back(temp); 
    // }

    return 0;
}