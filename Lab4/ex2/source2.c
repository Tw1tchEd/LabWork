#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int matrix[100][100];
    int rows, cols;

    printf("Введите количество строк (не более 100): ");
    scanf_s("%d", &rows);

    printf("Введите количество столбцов (не более 100): ");
    scanf_s("%d", &cols);

    if (rows > 100 || cols > 100) {
        printf("Превышен максимальный размер матрицы.\n");
        return 1;
    }

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("element [%d][%d] = ", i+1, j+1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // Находим первый столбец, все элементы которого отрицательны
    int negativeColumn = -1;
    for (int j = 0; j < cols; ++j) {
        int allNegative = 1;  // Предполагаем, что все элементы отрицательны

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] >= 0) {
                allNegative = 0;  // Найден положительный элемент
                break;
            }
        }

        if (allNegative) {
            negativeColumn = j;
            break;
        }
    }

    // Проверка на корректность ввода
    if (negativeColumn == -1) {
        printf("В матрице нет столбцов, все элементы которых отрицательны.\n");
        return 1;
    }

    // Вычисляем среднее арифметическое элементов выбранного столбца
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += matrix[i][negativeColumn];
    }

    int average = sum / rows;

    // Вычитаем среднее арифметическое из всех элементов матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] -= average;
        }
    }

    // Вывод измененной матрицы
    printf("Измененная матрица:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
