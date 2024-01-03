#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int matrix[100][100];
    int rows, cols;

    printf("������� ���������� ����� (�� ����� 100): ");
    scanf_s("%d", &rows);

    printf("������� ���������� �������� (�� ����� 100): ");
    scanf_s("%d", &cols);

    if (rows > 100 || cols > 100) {
        printf("�������� ������������ ������ �������.\n");
        return 1;
    }

    printf("������� �������� �������:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("element [%d][%d] = ", i+1, j+1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // ������� ������ �������, ��� �������� �������� ������������
    int negativeColumn = -1;
    for (int j = 0; j < cols; ++j) {
        int allNegative = 1;  // ������������, ��� ��� �������� ������������

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] >= 0) {
                allNegative = 0;  // ������ ������������� �������
                break;
            }
        }

        if (allNegative) {
            negativeColumn = j;
            break;
        }
    }

    // �������� �� ������������ �����
    if (negativeColumn == -1) {
        printf("� ������� ��� ��������, ��� �������� ������� ������������.\n");
        return 1;
    }

    // ��������� ������� �������������� ��������� ���������� �������
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += matrix[i][negativeColumn];
    }

    int average = sum / rows;

    // �������� ������� �������������� �� ���� ��������� �������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] -= average;
        }
    }

    // ����� ���������� �������
    printf("���������� �������:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
