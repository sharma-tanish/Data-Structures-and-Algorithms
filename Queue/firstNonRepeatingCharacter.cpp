#include <iostream>
#include <queue>

using namespace std;

int main() {

    string str = "ababc";
    queue<char> q;
    int frequency[26] = {0};

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        frequency[ch - 'a']++;
        q.push(ch);

        // Find answer
        while(!q.empty()) {
            char frontCharacter = q.front();
            if(frequency[frontCharacter - 'a'] > 1) {
                // This is not the answer
                q.pop();
            }
            else {
                // = 1
                // This is the answer
                cout << frontCharacter << " ";
                break;
            }
        }

        if(q.empty()) {
            // Koi answer nahi nikla
            cout << '#' << " ";
        }
    }
    
    cout << endl;

    return 0;
}