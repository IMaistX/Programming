#include <stdio.h>
float det2(float matrix[2][3]) {
    float opred = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return opred;
}
float detx2(float matrix[2][3]) {
    float opred = matrix[0][2] * matrix[1][1] - matrix[0][1] * matrix[1][2];
    return opred;
}
float dety2(float matrix[2][3]) {
    float opred = matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0];
    return opred;
}
float det3(float matrix[3][4]) {
    float opred = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]);
    return opred;
}

float detx3(float matrix[3][4]) {
    float opred = (matrix[0][3] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][3]) + (matrix[0][2] * matrix[1][3] * matrix[2][1]) - (matrix[0][1] * matrix[1][3] * matrix[2][2]) - (matrix[0][3] * matrix[1][2] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][3]);
    return opred;
}
float dety3(float matrix[3][4]) {
    float opred = (matrix[0][0] * matrix[1][3] * matrix[2][2]) + (matrix[0][3] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][3]) - (matrix[0][3] * matrix[1][0] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][3]) - (matrix[0][2] * matrix[1][3] * matrix[2][0]);
    return opred;
}
float detz3(float matrix[3][4]) {
    float opred = (matrix[0][0] * matrix[1][1] * matrix[2][3]) + (matrix[0][1] * matrix[1][3] * matrix[2][0]) + (matrix[0][3] * matrix[1][0] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][3]) - (matrix[0][0] * matrix[1][3] * matrix[2][1]) - (matrix[0][3] * matrix[1][1] * matrix[2][0]);
    return opred;
}

int main() {
    int n;
    scanf("%d", &n);
    float matrix[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n + 1); j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n + 1); j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    float opred;
    if (n == 2) {
        opred = det2(matrix);
        if (opred != 0) {
            float opred_x = detx2(matrix);
            float opred_y = dety2(matrix);
            float x = opred_x / opred;
            float y = opred_y / opred;
            printf("x = %f, y = %f\n", x, y);
        }
        else {
            printf("Нет единственного решения\n");
        }
    }
    else {
        opred = det3(matrix);
        if (opred != 0) {
            float opred_x = detx3(matrix);
            float opred_y = dety3(matrix);
            float opred_z = detz3(matrix);
            float x = opred_x / opred;
            float y = opred_y / opred;
            float z = opred_z / opred;
            printf("x = %f, y = %f, z = %f\n", x, y, z);
        }
        else {
            printf("Нет единственного решения\n");
        }
    }
}