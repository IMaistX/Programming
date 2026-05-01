#include <stdio.h>
#include "automobil.h"

int main() {
    struct Automobil cars[N];
    
    fillRandom(cars, N);
    
    printf("ДО СОРТИРОВКИ:");
    printCars(cars, N);
    
    sortByYear(cars, N);
    
    printf("ПОСЛЕ СОРТИРОВКИ ПО ГОДУ:");
    printCars(cars, N);
    
    return 0;
}