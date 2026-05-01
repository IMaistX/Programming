#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

struct Automobil {
    char brand[20];
    int year;
    int power;
    int cost;
};


void fillRandom(struct Automobil cars[], int size) {
    char* brands[] = {"Toyota", "BMW", "Audi", "Volkswagen", "Porsche"};
    
    srand(time(NULL));
    
    for (int i = 0; i < size; i++) {
        int idx = rand() % 5;
        
        int j = 0;
        while (brands[idx][j] != '\0') {
            cars[i].brand[j] = brands[idx][j];
            j++;
        }
        cars[i].brand[j] = '\0';
        
        cars[i].year = 1980 + rand() % 27;     // от 2000 до 2023
        cars[i].power = 120 + rand() % 501;      // от 50 до 250
        cars[i].cost = 5000 + rand() % 45001;   // от 5000 до 50000
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