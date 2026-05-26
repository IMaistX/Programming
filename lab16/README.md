# Лабораторная работа #16
Задание на 3

```c
void message(void *arg) {
    printf("Поток завершил работу\n");
}
```

Программа, которая создает поток с помощью pthread_create(), атрибуты по умолчанию. 
Родительский и дочерний потоки выводят на экран по 5 строк текста.
 
```c
#include <stdio.h>
#include <pthread.h>

void *thread_print(void *_) {
    for (int i = 1; i < 6; i++) {
        printf("дочерний поток, %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_print, NULL);
    for (int i = 1; i < 6; i++) {
        printf("родительский поток, %d\n", i);
    }
}
```
 
Чтобы родительский поток выводил текст после дочернего, был добавлен pthread_join:
 
```c
#include <stdio.h>
#include <pthread.h>

void *thread_print(void *_) {
    for (int i = 1; i < 6; i++) {
        printf("дочерний поток, %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_print, NULL);

    pthread_join(tid, NULL);

    for (int i = 1; i < 6; i++) {
        printf("родительский поток, %d\n", i);
    }
}
```

Далее программа была модифицирована: основной поток создает 4 потока, 
исполняющих одну и ту же функцию. Эта функция печатает последовательность текстовых строк, переданных как параметр. 
Каждый из созданных потоков печатает различные последовательности строк. 
 
```c
#include <stdio.h>
#include <pthread.h>

#define N 4

void *thread_print(void *arg) {
    char **strings = (char **)arg;
    for (int i = 0; i < 3; i++) {
        printf("%s\n", strings[i]);
    }
    return NULL;
}

int main() {
    pthread_t tids[N];
    char *strings1[] = {"поток 1, вывод 1", "поток 1, вывод 2", "поток 1, вывод 3"};
    char *strings2[] = {"поток 2, вывод 1", "поток 2, вывод 2", "поток 2, вывод 3"};
    char *strings3[] = {"поток 3, вывод 1", "поток 3, вывод 2", "поток 3, вывод 3"};
    char *strings4[] = {"поток 4, вывод 1", "поток 4, вывод 2", "поток 4, вывод 3"};
    char **strings[] = {strings1, strings2, strings3, strings4};

    for (int i = 0; i < N; i++) {
        pthread_create(&tids[i], NULL, thread_print, strings[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(tids[i], NULL);
    }
}
```
 
Был добавлен сон с помощью sleep() в функцию потоков между выводами строк. 
Спустя две секунды после создания дочерних потоков основной поток прерывает работу всех дочерних потоков с помощью pthread_cancel(). 
 
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 4

void *thread_print(void *arg) {
    char **strings = (char **)arg;
    for (int i = 0; i < 3; i++) {
        printf("%s\n", strings[i]);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t tids[N];
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
```
 
Далее был использован pthread_cleanup_push(), чтобы дочерний поток перед завершением распечатывал сообщение об этом.
 
```c
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
    pthread_t tids[N];
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
```

Реализован алгоритм сортировки Sleepsort с асимптотикой O(N) (по времени). Суть алгоритма: на вход подается массив не более 50 целочисленных значений.
Для каждого элемента массива создается отдельный поток, в который в качестве аргумента передается значение элемента. Сам поток уходит в сон с 
помощью sleep() с параметром равным аргументу потока (значение элемента массива). 
 
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void FillRand(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10; // Генерация чисел от 0 до 9, как на скриншоте
    }
}

void *sleep_sort(void *arg) {
    int num = *(int *)arg;
    sleep(num);
    printf("%d ", num);
    return NULL;
}

int main() {
    srand(time(NULL));

    int n = 0;
    printf("Введите длину списка (не больше 50):\n");
    scanf("%d", &n);

    pthread_t tids[n];
    int arr[n];
    FillRand(arr, n);

    printf("Исходный массив \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Отсортированный массив: \n");
    fflush(stdout);

    for (int i = 0; i < n; i++) {
        pthread_create(&tids[i], NULL, sleep_sort, &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL);
    }
    printf("\n");
}
```
