#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double file_size(const char *file) {
    FILE *f = fopen(file, "rb");
    if (f == NULL) return 0;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);
    return size / 1024.0;
}

void compress() {
    int count = 1;

    FILE *file_r = fopen("dog.png", "rb");
    if (file_r == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *file_w = fopen("dog.rle", "wb");
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
    FILE *file_r = fopen("dog.rle", "rb");
    if (file_r == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *file_w = fopen("dog_press.png", "wb");
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

int main() {
    compress();
    decompress();

    double size = file_size("dog.png");
    double size_before = file_size("dog.rle");
    printf("Размер до: %lf Кб, Размер после: %lf Кб. Сжатие: %lf%%\n", size, size_before, (1 - size_before / size) * 100);

    
    return 0;
}