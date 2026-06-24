#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

int main() {
    Circle c;
    Point p;

    cout << "Input: ";
    
    cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y;
    
    double result = distance(&c, &p);
    cout << "Output: " << CheckPointInCircle(result) << endl;

    return 0;
}