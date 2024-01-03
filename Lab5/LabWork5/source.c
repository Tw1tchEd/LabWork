#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция для заполнения массива четными натуральными числами до 99
void fillArray(int** arr, int* size) {
    *size = 49; // Максимальное количество четных чисел до 99
    *arr = (int*)malloc(*size * sizeof(int));

    // Проверка на успешное выделение памяти
    if (*arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(1);
    }

    int index = 0;
    for (int i = 2; i <= 99; i += 2) {
        (*arr)[index++] = i;
    }
}

// Функция для удаления чисел, не принадлежащих отрезку [a, b]
void filterArray(int** arr, int* size, int a, int b) {
    int newSize = 0;

    for (int i = 0; i < *size; ++i) {
        if ((*arr)[i] >= a && (*arr)[i] <= b) {
            (*arr)[newSize++] = (*arr)[i];
        }
    }

    // Освобождение избыточной памяти
    *arr = (int*)realloc(*arr, newSize * sizeof(int));

    // Проверка на успешное выделение памяти
    if (*arr == NULL && newSize > 0) {
        printf("Ошибка выделения памяти.\n");
        exit(1);
    }

    *size = newSize;
}

// Функция для вывода массива на экран
void printArray(const int* arr, int size) {
    printf("Массив: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Russian");
    int* array;
    int size;

    fillArray(&array, &size);

    // Вывод изначального массива
    printArray(array, size);

    int a, b;
    printf("Введите границы отрезка [a, b]: ");
    scanf_s("%d %d", &a, &b);

    // Проверка на корректность введенных границ
    if (a > b) {
        printf("Ошибка: b должно быть не меньше a.\n");
        return 1;
    }

    // Удаление чисел, не принадлежащих отрезку [a, b]
    filterArray(&array, &size, a, b);

    // Вывод отфильтрованного массива
    printArray(array, size);

    // Освобождение памяти
    free(array);

    return 0;
}
