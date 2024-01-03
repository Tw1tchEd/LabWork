#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int size;

    // ���� ������� �������
    printf("������� ������ ���������� �������: ");
    scanf_s("%d", &size);

    // ��������� ������ ��� �������
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }

    // ���� ��������� �������
    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("������� [%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // ���������� ������������ ����� ��/��� ������� ����������
    int min = matrix[1][0]; // ������ ������� ��� ������� ����������
    for (int i = 2; i < size; i++) {
        if (matrix[i][i - 1] < min) {
            min = matrix[i][i - 1];
        }
    }

    // ����� ����������
    printf("����������� ����� ��/��� ������� ����������: %d\n", min);

    // ������������ ���������� ������
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
