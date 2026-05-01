#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Automobil {
    int nomer;
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
    struct Node *prev;
} Node;

Node* S = NULL;
Node* cur = NULL;

Node *newNode() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->car = fillRand();
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

Node* appendBack(Node* head) {
    if (head == NULL) {
        Node* node1 = newNode();  // нечётный
        Node* node2 = newNode();  // чётный
        
        node1->car.nomer = 1;
        node2->car.nomer = 2;
        
        node2->prev = node1;
        node1->prev = NULL;
        
        node1->next = NULL;
        node2->next = NULL;
        
        return node2;
    }
    
    Node* up = head;
    while (up->next != NULL) {
        up = up->next;
    }
    
    Node* down = up->prev;
    
    Node* new_down = newNode();
    Node* new_up = newNode();
    
    new_down->car.nomer = down->car.nomer + 2;
    new_up->car.nomer = up->car.nomer + 2;
    
    new_up->prev = new_down;
    new_down->prev = NULL;

    up->next = new_up;
    down->next = new_down;
    
    new_up->next = NULL;
    new_up->next = NULL;
    
    return head;
}

void printCurrent() {
    if (cur == NULL) {
        printf("Нет текущего элемента\n");
        return;
    }
    
    printf("\nТекущий автомобиль #%d\n", cur->car.nomer);
    printf("    Бренд: %s\n", cur->car.brand);
    printf("    Год: %d\n", cur->car.year);
    printf("    Мощность: %d л.с.\n", cur->car.power);
    printf("    Цена: %d $\n", cur->car.cost);
    
    printf("\n");
}

void Right() {
    if (cur == NULL) {
        printf("\nНет элемента!\n");
        return;
    }
    
    if (cur->next != NULL) {
        cur = cur->next;
    } else {
        printf("\nНельзя переместиться направо!\n");
    }
}

void Down() {
    if (cur == NULL) {
        printf("\n Нет элемента!\n");
        return;
    }
    
    if (cur->car.nomer % 2 == 0) {
        if (cur->prev != NULL) {
            cur = cur->prev;
        } else {
            printf("\nНельзя переместиться вниз!\n");
        }
    } else {
        printf("\nНельзя переместиться вниз! Вы уже на нижнем уровне.\n");
    }
}

int main() {
    srand(time(NULL));
    int n;
    
    printf("Введите размер списка: \n");
    scanf(" %d", &n);
    
    S = NULL;
    
    for (int i = 0; i < n; i++) {
        S = appendBack(S);
    }
    
    cur = S;
    
    char command;
    while (1) {
        printCurrent();
        printf("Введите команду (d - вправо, s - вниз, q - выход): ");
        scanf(" %c", &command);
        
        switch (command) {
        case 'd':
            Right();
            break;
        case 's':
            Down();
            break;
        case 'q':
            printf("Выход из программы...\n");
            Node* cur_up = S;
            while (cur_up != NULL) {
                Node* temp_up = cur_up;
                Node* temp_down = cur_up->prev;
                cur_up = cur_up->next;
                free(temp_up);
                if (temp_down != NULL) {
                    free(temp_down);
                }
            }
            return 0;
        default:
            printf("\nНет такок команды!\n");
            break;
        }
    }
    
    return 0;
}