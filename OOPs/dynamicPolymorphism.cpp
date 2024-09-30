#include <iostream>

using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes sound" << endl;
    }
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
    ~Dog() {
        cout << "Dog destructor" << endl;
    }
}; 

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows" << endl;
    }
};

void sound(Animal *animal) {
    animal->sound(); // Polymorphic statement: animal->sound is behaving as per required object allocated at runtime
}

int main() {
    Animal *animal = new Dog();
    sound(animal);

    // animal = new Cat();
    // sound(animal);

    delete animal;
    return 0;
}