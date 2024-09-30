#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    v.push_back(9);

    cout << "Finding 5: " << binary_search(v.begin(), v.end(), 5) << endl;

    cout << "Lower bound: " << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    cout << "Upper bound: " << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;

    int a = 3;
    int b = 7;

    cout << "Max: " << max(a, b) << endl;
    cout << "Min: " << min(a, b) << endl;

    swap(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    string str = "Tanish Sharma";
    reverse(str.begin() , str.end());
    cout << "Reversed String: " << str << endl;

    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "Printing v after rotation:" << endl;
    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end()); // Based on Intro Sort - combination of Quick Sort, Heap Sort and Insertion Sort
    cout << "Printing v after sorting:" << endl;
    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}