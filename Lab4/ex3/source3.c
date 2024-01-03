#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    // Задаем размер матрицы
    int N;
    printf("Введите размер матрицы N (не больше 100): ");
    scanf_s("%d", &N);

    if (N > 100) {
        printf("Превышен максимальный размер матрицы.\n");
        return 1;
    }

    // Объявляем матрицу размером NxN
    int matrix[100][100];

    // Вводим элементы матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("element [%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    int minElement;

    // Проходим по элементам во второй области и находим минимальный элемент
    for (int i = 0; i < N / 2; i++) {
        for (int j = N / 2; j < N; j++) {
            if (matrix[i][j] < matrix[0][N / 2]) {
                minElement = matrix[i][j];
            }
        }
    }

    // Выводим результат
    printf("Минимальный элемент во второй области матрицы: %d\n", minElement);

    return 0;
}
