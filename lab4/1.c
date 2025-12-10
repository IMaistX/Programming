#include <stdio.h>

int main() {
    printf("Введите чило:");
    int a;
    scanf("%d", &a);
    printf("Введите бит который надо инвертировать:");
    int i;
    scanf("%d", &i);

    int result = a ^ (1 << (i - 1));
    printf("%d\n", result);
}