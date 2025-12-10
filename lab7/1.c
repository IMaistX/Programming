#include <stdio.h>
int main() {
    char string[1000];
    printf("Enter string: ");
    fgets(string, sizeof(string), stdin);
    
    int total = 0;
    short int i = 0;
    char k = 0;
    while (string[i] != '\0') {
        if (string[i] >= '0' && string[i] <= '9'){
            total += string[i] - '0';
            k = 1;
        }
        
        i++;
    }
    if (k != 0) {
        printf("Цифры есть!\n");
        printf("Сумма цифр: %d\n", total);
    }
    else {
        printf("Цифр нет!");
    }
}