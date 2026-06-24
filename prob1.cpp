#include <iostream>
#include "point.h"
#include "line.h"

using namespace std;

int main() {
    Line l;
    Point p;

    cout << "Input: ";
    
    cin >> l.a >> l.b >> l.c >> p.x >> p.y;
    
    double result = gradient(&l, &p);
    cout << "Output: " << CheckPointPosition(result) << endl;

    return 0;
}