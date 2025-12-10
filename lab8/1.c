#include <stdio.h>
#include <stdlib.h>

float sr_strok(float *arr, int n) {
    float sr = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sr += arr[i];
            count++;
        }
    }
    if (count != 0) {return sr / count;}
    else {return 0;}
}

float summa(float **arr, int n) {
    float sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int funk3(float **arr, int n, float *arr2) {
    int count = 0;
    int arr2_index = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && i + j < n - 1) {
                if (arr2_index < n) {  
                    arr2[arr2_index] = arr[i][j];
                    arr2_index++;
                }
                if (arr[i][j] < 0) {
                    count += 1;
                }
            }
        }
    }
    return count;
}

int main() {
    int N;

    printf("Введите размер матрицы: ");
    scanf("%d", &N);
    float arr2[N];
    printf("\nИсходная матрица:\n");
    float **arr = malloc(N * sizeof(float*));
    for (int i = 0; i < N; i++) {
        arr[i] = (float*)calloc(N, sizeof(float));
        if (arr[i] == NULL) {/* error */}
        
        for (int j = 0; j < N; j++) {
            arr[i][j] = i - (j + 2);
            printf("%6.1f ", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("\nМодифицированная матрица:\n");
    for (int i = 0; i < N; i++) {
        float average = sr_strok(arr[i], N);
        for (int j = 0; j < N; j++) {
            arr[i][j] += average;
            printf("%6.1f ", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("\nСумма всех элементов: %.2f\n", summa(arr, N));
    
    printf("Количество отрицательных элементов выше главнои и побочной диагонали: %d\n", funk3(arr, N, arr2));


    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}