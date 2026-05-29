#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 4

pthread_mutex_t mutex;

int flag = 0; 

void message(void *arg) {
    printf("Поток завершил работу\n");
}

void *thread_print(void *arg) {
    pthread_cleanup_push(message, NULL);

    char **p = (char **)arg;
    int val = atoi(p[0]);; 
    char **strings = p + 1;

    for (int i = 0; i < 3; i++) {
        while (1) {
            pthread_mutex_lock(&mutex);
            if (flag == val) {
                printf("%s\n", strings[i]);
                flag = 0;
                pthread_mutex_unlock(&mutex);
                break;
            }
            pthread_mutex_unlock(&mutex);
            usleep(100);
        }
        sleep(2);
    }
    
    pthread_cleanup_pop(0);
    return NULL;
}

int main() {
    pthread_t tids[4];
    
    pthread_mutex_init(&mutex, NULL);

    char *strings1[] = {"1", "поток 1, вывод 1", "поток 1, вывод 2", "поток 1, вывод 3"};
    char *strings2[] = {"2", "поток 2, вывод 1", "поток 2, вывод 2", "поток 2, вывод 3"};
    char *strings3[] = {"3", "поток 3, вывод 1", "поток 3, вывод 2", "поток 3, вывод 3"};
    char *strings4[] = {"4", "поток 4, вывод 1", "поток 4, вывод 2", "поток 4, вывод 3"};
    char **strings[] = {strings1, strings2, strings3, strings4};

    char *s_main[] = {"Главный: вывод 1", "Главный: вывод 2", "Главный: вывод 3", "Главный: вывод 4"};

    for (int i = 0; i < N; i++) {
        pthread_create(&tids[i], NULL, thread_print, strings[i]);
    }

    for (int i = 0; i < N; i++) {
        while (1) {
            pthread_mutex_lock(&mutex);
            if (flag == 0) {
                printf("%s\n", s_main[i]);
                flag = i + 1;
                pthread_mutex_unlock(&mutex);
                break;
            }
            pthread_mutex_unlock(&mutex);
            usleep(100);
        }
    }

    sleep(2);

    for (int i = 0; i < N; i++) {
        pthread_cancel(tids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(tids[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}
