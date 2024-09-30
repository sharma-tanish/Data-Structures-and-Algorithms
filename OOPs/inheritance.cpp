#include <iostream>
using namespace std;

class Human {
public:
    int height;
    int weight;
    int age;

    int getAge() {
        return this->age;
    }
    void setWeight(int weight) {
        this->weight = weight;

    }
};

class Male : protected Human {
public:
    string color;
    void sleep() {
        cout << "Male sleeping" << endl;
    }
    int getHeight() {
        return this->height;
    }
};

int main() {

    Male object1;
    cout << object1.getHeight() << endl;
    // cout << object1.weight << endl;
    // cout << object1.age << endl;
    // cout << object1.color << endl; 
    // object1.setWeight(84);
    // cout << object1.weight << endl;
    object1.sleep();

    return 0;
}