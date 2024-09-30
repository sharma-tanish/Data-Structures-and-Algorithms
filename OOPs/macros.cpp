#include <iostream>
using namespace std;

#define PI 3.14
#define AREA(l, b) (l * b)
#define MAX(a, b) (a > b ? a : b)

int main() {
    
    int r = 5;
    double areaCircle = PI * r * r;
    cout << "Area of circle: " << areaCircle << endl;

    int l = 4, b = 7;
    int areaRectangle = AREA(l, b);
    cout << "Area of rectanglr: " << areaRectangle << endl;

    return 0;
}