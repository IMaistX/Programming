#include <stdio.h>
int main() {
    int a;
    printf("Введите чило: ");
    scanf("%d", &a);
    int a2;
    for (int i = 0; i < sizeof(a) * 8; i++) {
        printf("%o", (a & 7));
        a = a >> 3;
    }
printf("\n");
}