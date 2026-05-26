#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shifr.h"


unsigned long long CalculateFactorial(int n) {
    if (n <= 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


void OtsenkaKriptostoykosti(const char *clean_key) {
    int len = strlen(clean_key);
    printf("ОЦЕНКА КРИПТОСТОЙКОСТИ:\n");
    printf("Длина очищенного ключа: %d символов.\n", len);

    if (len < 5) {
        printf("Стойкость: ОЧЕНЬ НИЗКАЯ.\n");
        printf("Ключ слишком короткий. Шифр легко взламывается вручную.\n");
    } else if (len >= 5 && len <= 10) {
        printf("Стойкость: СРЕДНЯЯ.\n");
        unsigned long long combinations = CalculateFactorial(len);
        printf("Количество комбинаций для перебора (N!): %llu\n", combinations);
    } else {
        printf("Стойкость: ВЫСОКАЯ.\n");
        if (len > 20) {
            printf("Огромное количество комбинаций для перебора.\n");
        } else {
            unsigned long long combinations = CalculateFactorial(len);
            printf("Количество комбинаций для перебора (N!): %llu\n", combinations);
        }
    }
}


char* CleanKey(char* str) {
    if (str == NULL) return NULL;

    int len = strlen(str);
    
    char* clean_key = (char*)malloc((len + 1) * sizeof(char));
    if (clean_key == NULL) return NULL;

    int clean_count = 0;

    for (int i = 0; i < len; i++) {
        int flag = 0;

        for (int j = 0; j < clean_count; j++) {
            if (clean_key[j] == str[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            clean_key[clean_count] = str[i];
            clean_count++;
        }
    }

    clean_key[clean_count] = '\0';
    return clean_key;
}


void SortKey(char *str, int *indices, int len) {
    for (int i = 0; i < len; i++) {
        indices[i] = i;
    }
    

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[indices[j]] > str[indices[j + 1]]) {
                int tempIndex = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tempIndex;
            }
        }
    }
}


char* Perestanovka(char *text, char *clean_key, int *indices) {
    int len = strlen(text);
    int cols = strlen(clean_key);
    
    int rows = (len + cols - 1) / cols;

    char **matrix = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)calloc(cols, sizeof(char));
    }

    int index_text = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index_text < len) {
                matrix[i][j] = text[index_text];
                index_text++;
            } else {
                matrix[i][j] = '-';
            }
        }
    }
    
    int total = rows * cols;
    char *shifr = (char*)malloc((total + 1) * sizeof(char));
    if (shifr == NULL) return NULL;

    int index_shifr = 0;
    
    for (int i = 0; i < cols; i++) {
        int col = indices[i];
        for (int j = 0; j < rows; j++) {
            shifr[index_shifr] = matrix[j][col];
            index_shifr++;
        }
    }
    shifr[index_shifr] = '\0';

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return shifr;
}


char* DePerestanovka(char *shifr, char *clean_key, int *indices) {
    int len = strlen(shifr);
    int cols = strlen(clean_key);
    int rows = len / cols;

    char **matrix = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(cols * sizeof(char));
    }

    int index_shifr = 0;
    for (int i = 0; i < cols; i++) {
        int col = indices[i];
        for (int j = 0; j < rows; j++) {
            matrix[j][col] = shifr[index_shifr];
            index_shifr++;
        }
    }

    char *original_text = (char*)malloc((len + 1) * sizeof(char));
    int index_text = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != '-') {
                original_text[index_text] = matrix[i][j];
                index_text++;
            }
        }
    }
    original_text[index_text] = '\0';

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return original_text;
}