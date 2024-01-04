#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void sortMatrixRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int* row = matrix[i];
        shellSort(row, cols);
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int rows, cols;

    printf("������� ������ ������� (NxM): ");
    scanf_s("%d%d", &rows, &cols);

    // ��������� ������ ��� �������
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // ���� ��������� �������
    printf("������� �������� �������:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("element[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // ���������� ����� �������
    sortMatrixRows(matrix, rows, cols);

    // ����� ��������������� �������
    printf("\n������� ����� ����������:\n");
    printMatrix(matrix, rows, cols);

    // ������������ ������
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
