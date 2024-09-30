#include <iostream>
using namespace std;


class Animal {
public:
    int age;
    int weight;

    void bark() {
        cout << "Barking" << endl;
    }
};

class Dog : public Animal {

};

class germanShepherd : public Dog {

};

int main() {

    germanShepherd g1;
    g1.bark();

    return 0;
}