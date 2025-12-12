#ifndef FRACTION_H
#define FRACTION_H

struct Fraction {
    int a;
    int b;
};

struct Fraction mult(struct Fraction f1, struct Fraction f2);
struct Fraction div(struct Fraction f1, struct Fraction f2);

#endif