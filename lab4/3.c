// 1 вар
#include <stdio.h>

int main() {
    int a;
    printf("Введите a: ");
    scanf("%d", &a);
    int count = 0;
    for (int i = 0; i < 32; i++) {
        count += a & 1;
        a = a >> 1;
    }
    printf("Количество еденичных битов в числе a: %d\n", count);
    printf("Количество нулевых битов в числе a: %d\n", 32 - count);
}
