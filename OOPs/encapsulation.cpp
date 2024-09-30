#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    int rollNumber;

public:
    string getName() {
        return this->name;
    }
    int getAge() {
        return this->age;
    }
    int getRollNumber() {
        return this->rollNumber;
    }
};

int main() {
    Student s1;
    cout << "Everything working fine" << endl;
    return 0;
}