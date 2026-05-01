#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Automobil {
    char brand[20];
    int year;
    int power;
    int cost;
} Auto;


Auto fillRand() { 
    Auto car;
    char* brands[] = {"Toyota", "BMW", "Audi", "Volkswagen", "Porsche"};
    
    int idx = rand() % 5;

    strcpy(car.brand, brands[idx]);
    
    car.year = 1980 + rand() % 27;
    car.power = 120 + rand() % 481;
    car.cost = 5000 + rand() % 45001;
    
    return car;
}

typedef struct Node {
    Auto car;
    struct Node *next;
} Node;

Node* S = NULL;


Node *newNode() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->car = fillRand();
    new_node->next = NULL;
    
    return new_node;
}


Node* appendBack(Node* head) {
    Node* new_node = newNode();
    if (new_node == NULL) return head;
    
    if (head == NULL) {
        return new_node;
    }
    
    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    
    cur->next = new_node;
    return head;
}


void printList(Node* head) {
    Node* cur = head;
    int i = 1;
    while (cur != NULL) {
        printf("Автомобиль #%d:\n", i++);
        printf("  Бренд: %s\n", cur->car.brand);
        printf("  Год: %d\n", cur->car.year);
        printf("  Мощность: %d л.с.\n", cur->car.power);
        printf("  Цена: %d $\n", cur->car.cost);
        printf("\n");
        cur = cur->next;
    }
}



int main() {
    srand(time(NULL));
    int n;
    printf("Введите расмер списка: \n");
    scanf("%d", &n);

    S = NULL;

    for (int i = 0; i < n; i++) {
        S = appendBack(S);
    }
    
    printList(S);

    Node* cur = S;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    
    return 0;
}