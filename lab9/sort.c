#include <stdio.h>

// Ваша существующая функция сортировки
void sort(int arr[], int n) {
    // код сортировки из предыдущих шагов
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Добавленная функция main()
int main() {
    int a[] = {4, 2, 0, 8, 1, 9};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    sort(a, n);
    
    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
