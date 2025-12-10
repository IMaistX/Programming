#include <stdio.h>
#define N 6

int main() {
    int maximum = -33000;
    short int count = 0;
    double signal_energy;
    short int complex[N] = {-1234, 1000, 27140, -8, 32, 9};
    for (int i = 0; i < N; i += 2) {
        if (complex[i] > maximum) {
            maximum = complex[i];
        }
        printf("complex[%d] = %d + j*(%d)\n", count, complex[i], complex[i + 1]);

        signal_energy += complex[i] * complex[i] + complex[i + 1] * complex[i + 1];
        count += 1;
    }
    printf("\n");
    printf("Энергия сигнала для complex: %f\n", signal_energy);
    printf("Максимальный элемент среди реальной части: %d\n", maximum);
}