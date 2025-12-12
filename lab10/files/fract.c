#include "fract.h"

struct Fraction mult(struct Fraction f1, struct Fraction f2) {
    struct Fraction result;
    result.a = f1.a * f2.a;
    result.b = f1.b * f2.b;
    return result;
}

struct Fraction div(struct Fraction f1, struct Fraction f2) {
    struct Fraction result;
    result.a = f1.a * f2.b;
    result.b = f1.b * f2.a;
    return result;
}