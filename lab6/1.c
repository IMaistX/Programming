#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (n == 1) {
        printf("%d", matrix[0][0]);
    }
    else if (n == 2) {
        int opred = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        printf("%d\n", opred);
    }
    else if (n == 3) {
        int opred = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]);
        printf("%d\n", opred);
    }
    else {printf("Вводите число от1 до 3\n");}




    
}
