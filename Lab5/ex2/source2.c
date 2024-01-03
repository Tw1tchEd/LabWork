#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void printArray(int** array, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        printf("Строка %d: ", i + 1);
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int** array;
    int rows;
    int cols[MAX_ROWS];

    printf("Введите количество строк: ");
    scanf_s("%d", &rows);

    if (rows <= 0 || rows > MAX_ROWS) {
        printf("Ошибка ввода\n");
        return EXIT_FAILURE;
    }

    array = (int**)malloc(rows * sizeof(int*));

    if (array == NULL) {
        printf("Ошибка выделения памяти\n");
        return EXIT_FAILURE;
    }

    int count = 1;

    for (int i = 0; i < rows; i++) {
        printf("Введите число элементов в строке %d: ", i + 1);
        scanf_s("%d", &cols[i]);

        if (cols[i] <= 0 || cols[i] > MAX_COLS) {
            printf("Ошибка ввода\n");
            exit(EXIT_FAILURE);
        }

        array[i] = (int*)malloc(cols[i] * sizeof(int));

        if (array[i] == NULL) {
            printf("Ошибка выделения памяти\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < cols[i] - 1; j++) {
            array[i][j] = count++;
        }

        array[i][cols[i] - 1] = 0;
    }
    printArray(array, rows, cols);
    freeArray(array, rows);

    return EXIT_SUCCESS;
}
