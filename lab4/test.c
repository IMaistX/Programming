#include <stdio.h>
int main() {
    int a;
    printf("Введите чило: ");
    scanf("%d", &a);
    int a2 = 0;
    for (int i = 0; i < 11; i++) {
        a2 += (a & 7);
      
        a = a >> 3;
    }
printf("%d", a2);
printf("\n");
}