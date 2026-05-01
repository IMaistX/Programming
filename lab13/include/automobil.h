#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#define N 5

struct Automobil {
    char brand[20];
    int year;
    int power;
    int cost;
};


void fillRandom(struct Automobil cars[], int size);
void printCars(struct Automobil cars[], int size);
void sortByYear(struct Automobil cars[], int size);
double getTime();

#endif