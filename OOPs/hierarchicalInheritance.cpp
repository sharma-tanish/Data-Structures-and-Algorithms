#include <iostream>
using namespace std;

class A {
public:
    void func1() {
        cout << "Inside funcion 1" << endl;
    }
};

class B : public A {
public:
    void func2() {
        cout << "Inside funcion 2" << endl;
    }
};

class C : public A {
public:
    void func3() {
        cout << "Inside funcion 3" << endl;
    }
};

int main() {

    A object1;
    object1.func1();

    B object2;
    object2.func1();
    object2.func2();

    C object3;
    object3.func1();
    object3.func3();

    return 0;
}