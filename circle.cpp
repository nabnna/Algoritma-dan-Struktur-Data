#include "circle.h"
#include <cmath>

double distance(const Circle * c, const Point * p) {
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    double dist = std::sqrt((dx * dx) + (dy * dy));
    
    return dist - c->radius;
}

std::string CheckPointInCircle(double diff) {
    if (diff > EPSILON) {
        return "Outside";
    } 
    else if (diff < -EPSILON) {
        return "Inside";
    } 
    else {
        return "On Circle";
    }
}