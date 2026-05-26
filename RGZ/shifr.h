#ifndef SHIFR_H
#define SHIFR_H

unsigned long long CalculateFactorial(int n);
void OtsenkaKriptostoykosti(const char *clean_key);
char* CleanKey(char* str);
void SortKey(char *str, int *indices, int len);
char* Perestanovka(char *text, char *clean_key, int *indices);
char* DePerestanovka(char *shifr, char *clean_key, int *indices);

#endif