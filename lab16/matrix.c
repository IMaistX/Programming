#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct {
    int start;
    int end;
    int n;
    int **A;
    int **B;
    int **C;
} work_t;

void *worker(void *arg) {
    work_t *w = (work_t *)arg;
    int n = w->n;
    
    for (int i = w->start; i < w->end; i++) {
        for (int j = 0; j < n; j++) {
            w->C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                w->C[i][j] += w->A[i][k] * w->B[k][j];
            }
        }
    }
    
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Использование: %s <размер> <кол-во потоков>\n", argv[0]);
        return 1;
    }
    
    int size = atoi(argv[1]);
    int p = atoi(argv[2]);
    
    int **A = (int **)malloc(size * sizeof(int *));
    int **B = (int **)malloc(size * sizeof(int *));
    int **C = (int **)malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }
    
    pthread_t *tids = (pthread_t *)malloc(p * sizeof(pthread_t));
    work_t *jobs = (work_t *)malloc(p * sizeof(work_t));
    
    int rows = size / p;
    int extra = size % p;
    
    struct timeval t1, t2;
    gettimeofday(&t1, NULL);
    
    int cur = 0;
    for (int t = 0; t < p; t++) {
        jobs[t].start = cur;
        jobs[t].end = cur + rows + (t < extra ? 1 : 0);
        jobs[t].n = size;
        jobs[t].A = A;
        jobs[t].B = B;
        jobs[t].C = C;
        pthread_create(&tids[t], NULL, worker, &jobs[t]);
        cur = jobs[t].end;
    }
    
    for (int t = 0; t < p; t++) {
        pthread_join(tids[t], NULL);
    }
    
    gettimeofday(&t2, NULL);
    double ms = (t2.tv_sec - t1.tv_sec) * 1000.0 + 
                (t2.tv_usec - t1.tv_usec) / 1000.0;
    
    if (size < 5) {
        printf("Матрица A:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%4d ", A[i][j]);
            }
            printf("\n");
        }
        
        printf("Матрица B:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%4d ", B[i][j]);
            }
            printf("\n");
        }
        
        printf("Матрица C:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%4d ", C[i][j]);
            }
            printf("\n");
        }
    }
    
    printf("Размер: %d\n", size);
    printf("Кол-во потоков: %d\n", p);
    printf("Время: %.2f мс\n", ms);
    
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    free(tids);
    free(jobs);
    
    return 0;
}