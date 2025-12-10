#include <stdio.h>

int simple_digit(int digit) {
    if (digit < 2) {
        return 0;
    }
    int n;
    for (n = 2; n < digit; n++) {
        if (digit % n == 0) {
            break;
        }
    }
    if (n == digit) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    int x_size = sizeof(x) / sizeof(x[0]);
    int y[x_size / 2 + 1];
    int ind = 0;
    
    for (int i = 0; i < x_size; i += 2) {
        y[ind] = x[i];
        ind++;
    }
    
    int y_size = ind;
    int simple_x = 0;
    int simple_y = 0;
    float count = 0;
    float summa = 0;
    
    for (int i = 0; i < x_size; i++) {
        if (simple_digit(x[i]) == 1) {
            simple_x += 1;
        }
        count++;
        summa += x[i];
    }
    
    for (int i = 0; i < y_size; i++) {
        if (simple_digit(y[i]) == 1) {
            simple_y += 1;
        }
        count++;
        summa += y[i];
    }
    
    float sr = 0;
    if (count > 0) {
        sr = summa / count;
    }
    
    printf("Кол-во простых в x: %d\n", simple_x);
    printf("Кол-во простых в y: %d\n", simple_y);
    printf("Среднее во всех массивах: %.2f\n", sr);

    return 0;
}