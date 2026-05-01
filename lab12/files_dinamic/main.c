#include <stdio.h>
#include <stdlib.h>
#include "automobil.h"

int main() {
    int sizes[] = {100, 10000, 100000};
    
    printf("Размер\tВремя (сек)\n");
    printf("-----------------\n");
    
    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        struct Automobil* cars = malloc(size * sizeof(struct Automobil));
        
        fillRandom(cars, size);
        
        double start = getTime();
        sortByYear(cars, size);
        double end = getTime();
        
        printf("%d\t%.3f\n", size, end - start);
        
        free(cars);
    }
    
    return 0;
}