#include <iostream>
using namespace std;

void reverse(char ch[], int n) {
    int start = 0;
    int end = n - 1;
    while(start < end) {
        swap(ch[start], ch[end]);
        start++;
        end--;
    }
}

int getLength(char ch[]) {
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char ch[50];
    cin.getline(ch, 50);
    reverse(ch, getLength(ch));
    cout << ch << endl;
}