#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 4

void message(void *arg) {
    printf("Поток завершил работу\n");
}

void *thread_print(void *arg) {
    pthread_cleanup_push(message, NULL);

    char **strings = (char **)arg;
    for (int i = 0; i < 3; i++) {
        printf("%s\n", strings[i]);
        sleep(2);
    }
    
    pthread_cleanup_pop(0);
    return NULL;
}

int main() {
    pthread_t tids[4];
    char *strings1[] = {"поток 1, вывод 1", "поток 1, вывод 2", "поток 1, вывод 3"};
    char *strings2[] = {"поток 2, вывод 1", "поток 2, вывод 2", "поток 2, вывод 3"};
    char *strings3[] = {"поток 3, вывод 1", "поток 3, вывод 2", "поток 3, вывод 3"};
    char *strings4[] = {"поток 4, вывод 1", "поток 4, вывод 2", "поток 4, вывод 3"};
    char **strings[] = {strings1, strings2, strings3, strings4};

    for (int i = 0; i < N; i++) {
        pthread_create(&tids[i], NULL, thread_print, strings[i]);
    }

    sleep(2);

    for (int i = 0; i < N; i++) {
        pthread_cancel(tids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(tids[i], NULL);
    }
}