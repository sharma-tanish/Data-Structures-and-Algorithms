#include <iostream>

using namespace std;

class Box {
    int width;
    Box(int _width) : width(_width) {}

public:
    int getWidth() const {
        return width; 
    }

    void setWidth(int _width) {
        width = _width;
    }

    friend class BoxFactory;
};

class BoxFactory {
    int count;

public:
    Box getBox(int _w) {
        count++;
        return Box(_w);
    }
};

int main() {
    BoxFactory bFact;
    Box b = bFact.getBox(5);
    cout << b.getWidth() << endl;
    return 0;
}