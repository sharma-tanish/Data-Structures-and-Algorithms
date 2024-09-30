#include <iostream> 
using namespace std;

int countDistinctWays(int nStairs) {
    if(nStairs == 0) {
        return 1;
    }
    if(nStairs == 1) {
       return 1;
    }
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main() {
    int nStairs;
    cin >> nStairs;
    cout << countDistinctWays(nStairs) << endl;
    return 0;
}