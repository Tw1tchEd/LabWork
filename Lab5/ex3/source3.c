#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int size;

    // Ввод размера матрицы
    printf("Введите размер квадратной матрицы: ");
    scanf_s("%d", &size);

    // Выделение памяти под матрицу
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }

    // Ввод элементов матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // Нахождение минимального числа на/под главной диагональю
    int min = matrix[1][0]; // Первый элемент под главной диагональю
    for (int i = 2; i < size; i++) {
        if (matrix[i][i - 1] < min) {
            min = matrix[i][i - 1];
        }
    }

    // Вывод результата
    printf("Минимальное число на/под главной диагональю: %d\n", min);

    // Освобождение выделенной памяти
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
