#include <iostream>

using namespace std;

class A {
    int x;

public:
    A(int _val) : x(_val) {}
    
    int getX() const {
        return x;
    }
    
    void setX(int _val) {
        this->x = _val;
    }

    friend class B;
    friend void print(const A &);
};

void print(const A &a) {
    cout << a.x << endl;
}

class B {
public:
    void print(const A &a) {
        // cout << a.getX() << endl;
        cout << a.x << endl;
    }
};

int main() {
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}