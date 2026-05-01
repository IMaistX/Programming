#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc text.c -o text
// ./text file.txt out.txt


typedef struct Worker {
    char name[200];
    char id[100];
    char lvl[200];
} Worker;

double file_size(const char *file) {
    FILE *f = fopen(file, "rb");
    if (f == NULL) return 0;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);
    return size / 1024.0;
}

void Search_worker() {
    FILE *file_r = fopen("database.dat", "rb");
    if (file_r == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int id;
    Worker human;
    printf("Введите id работника: \n");
    scanf("%d", &id);

    int found = 0;
    
    while (fread(&human, sizeof(Worker), 1, file_r) == 1) {
        int ID = atoi(human.id);
        
        
        if (ID == id) {
            printf("%s; lvl %s\n", human.name, human.lvl);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Нет такого работника\n");
    }

    fclose(file_r);
}

void compress() {
    int count = 1;

    FILE *file_r = fopen("database.dat", "rb");
    if (file_r == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *file_w = fopen("database.rle", "wb");
    if (file_w == NULL) {
        perror("Error opening file");
        exit(1);
    }

    unsigned char prev_byte;
    fread(&prev_byte, 1, 1, file_r);
    unsigned char byte;
    while (fread(&byte, 1, 1, file_r) == 1) {
        if (byte == prev_byte && count < 255) {
            count += 1;
        }
        else {
            fwrite(&count, 1, 1, file_w);
            fwrite(&prev_byte, 1, 1, file_w);
            prev_byte = byte;
            count = 1;
        }
    }
    fwrite(&count, 1, 1, file_w);
    fwrite(&prev_byte, 1, 1, file_w);

    fclose(file_r);
    fclose(file_w);


}


void decompress() {
    FILE *file_r = fopen("database.rle", "rb");
    if (file_r == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *file_w = fopen("database_2.dat", "wb");
    if (file_w == NULL) {
        perror("Error opening file");
        exit(1);
    }

    unsigned char count;
    unsigned char value;
    
    while (fread(&count, 1, 1, file_r) == 1 && 
           fread(&value, 1, 1, file_r) == 1) {
        
        for (int i = 0; i < count; i++) {
            fwrite(&value, 1, 1, file_w);
        }
    }
    
    fclose(file_r);
    fclose(file_w);
}



int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./a.out file.txt out.txt\n");
        exit(1);
    }
    


    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *file_w = fopen(argv[2], "wb");
    if (file_w == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    

    char str[120];
    Worker humans[15];
    Worker human;
    int i = 0;

    while (fgets(str, sizeof(str), file)) {
        char *string = strtok(str, ";");
        strcpy(human.name, string);
        
        string = strtok(NULL, ";");
        strcpy(human.id, string);
        
        string = strtok(NULL, ";");
        strcpy(human.lvl, string);
        
        humans[i] = human;
        i++;
    }
    
    fwrite(humans, sizeof(Worker), 15, file_w);
    

    fclose(file);
    fclose(file_w);
    Search_worker();
    compress();
    decompress();

    double size = file_size("database.dat");
    double size_before = file_size("database.rle");
    printf("Размер до: %lf Кб, Размер после: %lf Кб. Сжатие: %lf%%\n", size, size_before, (1 - size_before / size) * 100);

    
    return 0;
}