#include <iostream>
using namespace std;

class A {
public:
    // Function overloading
    void sayHello() {
        cout << "Hello Tanish Sharma" << endl;
    }    
    int sayHello(char name) {
        cout << "Hello Tanish Sharma" << endl;
        return 1;
    }
    void sayHello(string name) {
        cout << "Hello " << name << endl;
    }
};

class B {
public:
    int a;
    int b;

    int add() {
        return a + b;
    }
    // Operator overloading
    void operator+(B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Output: " << value2 - value1 << endl;
        cout << "Hello Sharma Ji" << endl;
    }
    void operator()() {
        cout << "Main bracket hoon " << this->a << endl;
    }
};

// Method overriding
class Animal {
public:
    void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Barking" << endl;
    }
};

int main() {

    Dog obj;
    obj.speak();


    // Calling operator overloaded function
    // B obj1, obj2;
    // obj1.a = 4;
    // obj2.a = 7;
    // obj1 + obj2;

    // obj1();
    // obj2();


    // Calling overloaded functions
    // A obj;
    // obj.sayHello();

    return 0; 
}