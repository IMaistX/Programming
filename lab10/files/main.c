#include <stdio.h>
#include "fract.h"

int main() {
    struct Fraction f1, f2;
    struct Fraction res1, res2;

    f1.a = 3;
    f1.b = 4;
    
    f2.a = 2;
    f2.b = 5;

    res1 = mult(f1, f2);
    printf("Умножение: %d/%d * %d/%d = %d/%d\n", f1.a, f1.b, f2.a, f2.b, res1.a, res1.b);

    res2 = div(f1, f2);
    printf("Деление: %d/%d / %d/%d = %d/%d\n", f1.a, f1.b, f2.a, f2.b, res2.a, res2.b);

    return 0;
}