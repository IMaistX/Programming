#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


void *sleep_sort(void *arg) {
    int  num= *(int *)arg;
    sleep(num);
    printf("%d ", num);
}

void FillRand(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 10;
    }
}

int main() {
    srand(time(NULL));

    int n = 0;
    printf("ВВедите длину списка (не больше 50):\n");
    scanf("%d", &n);

    pthread_t tids[n];

    int arr[n];
    FillRand(arr, n);

    printf("Исходный массив \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Отсортированный массив: \n");
    fflush(stdout);

    for (int i = 0; i < n; i++) {
        pthread_create(&tids[i], NULL, sleep_sort, &arr[i]);
    }


    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("\n");
}