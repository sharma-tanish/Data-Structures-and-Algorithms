#include <iostream>

using namespace std;

class abc {
public:
    int x;
    int *y;
    
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // Shallow copy (Default copy constructor)
    // abc(const abc &obj) {
    //     this->x = obj.x;
    //     this->y = obj.y;
    // }

    // Deep copy
    abc(const abc &obj) {
        this->x = obj.x;
        this->y = new int(*obj.y);
    }

    void print() const {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "*y: " << *y << endl << endl;
    }

    ~abc() {
        delete y;
    }
};

int main() {
    abc a(1, 2);
    cout << "Printing a" << endl;
    a.print();

    abc b(a); // Copy a into b
    // abc b = a;
    cout << "Printing b" << endl;
    b.print();

    *b.y = 20;

    cout << "Printing b after changing *y in b" << endl;
    b.print();
    cout << "Printing a after changing *y in b" << endl;
    a.print();

    // Problem with shallow copy
    // abc *a = new abc(1, 2);
    // abc b = *a;
    // delete a;
    // b.print();
    return 0;
}