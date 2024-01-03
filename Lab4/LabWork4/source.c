#include <stdio.h>
#include <stdlib.h>

void findSumNoNegRows(int** matrix, int rows, int cols);
void findMinParallelDiagSum(int** matrix, int rows, int cols);

int main() {
    int rows, cols;

    printf("Write amount of rows: ");
    scanf_s("%d", &rows);
    printf("Write amount of columns: ");
    scanf_s("%d", &cols);

    // Выделение памяти под матрицу
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Ввод элементов матрицы
    printf("Enter the elements %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("element [%d][%d] = ", i+1, j+1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // Вызов функции для определения суммы элементов в строках без отрицательных элементов
    findSumNoNegRows(matrix, rows, cols);

    // Вызов функции для определения минимума среди сумм элементов параллельных главной диагонали
    findMinParallelDiagSum(matrix, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void findSumNoNegRows(int** matrix, int rows, int cols) {
    int sum = 0;

    // Перебор строк матрицы
    for (int i = 0; i < rows; i++) {
        int hasNegative = 0;

        // Перебор элементов строки
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                hasNegative = 1;
                break;
            }
            sum += matrix[i][j];
        }

        // Если в строке нет отрицательных элементов, выводим сумму
        if (!hasNegative) {
            printf("summ of elements %d: %d\n", i + 1, sum);
        }

        sum = 0; // Сброс суммы для следующей строки
    }
}

void findMinParallelDiagSum(int** matrix, int rows, int cols) {
    int minSum = 0; // Инициализация минимальной суммы значением первого элемента

    // Перебор диагоналей параллельных главной диагонали
    for (int k = 1; k < rows; k++) {
        int sum = 0;

        // Перебор элементов диагонали
        for (int i = 0, j = k; j < rows && i < cols; i++, j++) {
            sum += matrix[i][j];
            if (i == 0) {
				minSum = sum;
			}
        }

        // Обновление минимальной суммы
        if (sum <= minSum) {
            minSum = sum;
        }
    }
    printf("min sum: %d\n", minSum);
}
