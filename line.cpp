#include "line.h"

double gradient(const Line * l, const Point * p) {
    return (l->a * p->x) + (l->b * p->y) + l->c;
}

std::string CheckPointPosition(double eval_result) {
    if (eval_result > EPSILON) {
        return "Left";
    } else if (eval_result < -EPSILON) {
        return "Right";
    } else {
        return "On Line";
    }
}