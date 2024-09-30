#include <iostream>
using namespace std;


class LivingBeing {
public:
    int age;
    int weight;

    void live() {
        cout << "Lives" << endl;
    }
};

class Animal : virtual public LivingBeing {
public:
    void bark() {
        cout << "Barks" << endl;
    }
};

class Human : virtual public LivingBeing {
public:
    int height;

    void speak() {
        cout << "Speaks" << endl;
    }
};

class Hybrid : public Animal, public Human {
public:
    void move() {
        cout << "Moves" << endl;
    }
};

int main() {

    Hybrid obj1;

    // Diamond problem

    // Solution 1: Scope resolution operator
    obj1.Animal::live();
    obj1.Human::live();

    // Solution 2: Virtual
    obj1.live();
    
    return 0;
}