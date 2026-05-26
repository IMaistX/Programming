#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shifr.h"

int main() {
    char text[256] = "";
    char dirty_key[256] = "";
    char line[512];
    int i;

    FILE *f = fopen("config.txt", "r");
    if (f == NULL) {
        printf("Error: config.txt not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), f)) {
        char name[100] = "";
        char val[256] = "";
        
        
        if (sscanf(line, "%99[^=]=%255[^\n]", name, val) == 2) {
            if (strcmp(name, "TEXT") == 0) {
                strcpy(text, val);
            } else if (strcmp(name, "KEY") == 0) {
                strcpy(dirty_key, val);
            }
        }
    }
    fclose(f);

    i = 0;
    while (text[i] == ' ' || text[i] == '\t') i++;
    if (text[i] == '\0' || text[i] == '\n') {
        printf("Ошибка: пустой текст\n");
        return 1;
    }

    i = 0;
    while (dirty_key[i] == ' ' || dirty_key[i] == '\t') i++;
    if (dirty_key[i] == '\0' || dirty_key[i] == '\n') {
        printf("Ошибка: пустой ключ\n");
        return 1;
    }

    printf("Загружено из файла:\nТекст: %s\nКлюч: %s\n\n", text, dirty_key);

    char *clean_key = CleanKey(dirty_key);
    int cols = strlen(clean_key);

    OtsenkaKriptostoykosti(clean_key);

    int *poryadok = (int*)malloc(cols * sizeof(int));
    SortKey(clean_key, poryadok, cols);

    char *encrypted = Perestanovka(text, clean_key, poryadok);
    char *decrypted = DePerestanovka(encrypted, clean_key, poryadok);

    FILE *f_out1 = fopen("encrypted.txt", "w");
    fprintf(f_out1, "%s", encrypted);
    fclose(f_out1);
    printf("Шифротекст сохранен.\n");

    FILE *f_out2 = fopen("decrypted.txt", "w");
    fprintf(f_out2, "%s", decrypted);
    fclose(f_out2);
    printf("Расшифрованный текст сохранен.\n");

    free(clean_key);
    free(poryadok);
    free(encrypted);
    free(decrypted);

    return 0;
}