#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "automobil.h"

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}


void fillRandom(struct Automobil cars[], int size) {
    char* brands[] = {"Toyota", "BMW", "Audi", "Honda", "Ford"};
    
    srand(time(NULL));
    
    for (int i = 0; i < size; i++) {
        int idx = rand() % 5;
        
        int j = 0;
        while (brands[idx][j] != '\0') {
            cars[i].brand[j] = brands[idx][j];
            j++;
        }
        cars[i].brand[j] = '\0';
        
        cars[i].year = 2000 + rand() % 24;
        cars[i].power = 50 + rand() % 201;
        cars[i].cost = 5000 + rand() % 45001;
    }
}

void printCars(struct Automobil cars[], int size) {
    printf("\n");
    printf("  N    Марка        Год    Мощн    Стоимость\n");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        printf("  %2d   %-10s  %4d    %3d     %7d\n", 
               i + 1, 
               cars[i].brand, 
               cars[i].year, 
               cars[i].power, 
               cars[i].cost);
    }
    printf("\n");
}


void sortByYear(struct Automobil cars[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (cars[j].year > cars[j + 1].year) {
                struct Automobil temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}