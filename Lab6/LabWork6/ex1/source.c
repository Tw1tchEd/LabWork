#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция для нахождения максимального элемента в массиве
int findMax(const int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Функция для обмена значениями между двумя переменными
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для сортировки массива четных элементов методом выбора
void selectionSortEvenAfterMax(int* arr, int size) {
    int maxIndex = 0;

    // Находим индекс максимального элемента
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    // Переносим максимальный элемент в конец массива
    swap(&arr[maxIndex], &arr[size - 1]);

    // Сортируем четные элементы после максимального методом выбора
    for (int i = 0; i < size - 1; i += 2) {
        int minIndex = i;
        for (int j = i + 2; j < size; j += 2) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    // Выделение динамической памяти под массив
    int* arr = (int*)malloc(size * sizeof(int));

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; ++i) {
        scanf_s("%d", &arr[i]);
    }

    // Вызов функции для сортировки четных элементов после максимального
    selectionSortEvenAfterMax(arr, size);

    // Вывод отсортированного массива
    printf("Отсортированный массив:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    // Освобождение выделенной памяти
    free(arr);

    return 0;
}
