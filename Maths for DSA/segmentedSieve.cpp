#include <iostream>
#include <vector>
using namespace std;

vector<bool> basicSieve(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(sieve[i] == true) {
            for(int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

vector<bool> segmentedSeive(int L, int R) {
    vector<bool> sieve = basicSieve(sqrt(R));
    vector<int> basePrimes;
    for(int i = 0; i < sieve.size(); i++) {
        if(sieve[i] == true) {
            basePrimes.push_back(i);
        }    
    }
    vector<bool> segSieve(R - L + 1, true);
    if(L == 1) {
        segSieve[0] = false;
    }
    for(auto prime : basePrimes){
        int firstMultiple = (L / prime) * prime;
        firstMultiple = firstMultiple < L ? firstMultiple + prime : firstMultiple;
        for(int j = max(firstMultiple, prime * prime); j <= R; j += prime) {
            segSieve[j - L] = false;
        }
    }
    return segSieve;
}

int main() {
    int L, R;
    cin >> L >> R;
    vector<bool> ans = segmentedSeive(L, R);
    for(int i = 0; i < ans.size(); ++i) {
        if(ans[i] == true) {
            cout << L + i << " ";
        }    
    }
    cout << endl;
    return 0;
}
