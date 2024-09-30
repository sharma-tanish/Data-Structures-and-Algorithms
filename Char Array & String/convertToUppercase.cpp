#include <iostream>
using namespace std;

void toUppercase(char ch[]) {
    for(int i = 0; ch[i] != '\0'; i++) {
        if(ch[i] >= 'a' && ch[i] <= 'z') {
            ch[i] = ch[i] - 'a' + 'A';
        }
    }
}

int main() {
    char ch[50];
    cin.getline(ch, 50);
    toUppercase(ch);
    cout << ch << endl;
}