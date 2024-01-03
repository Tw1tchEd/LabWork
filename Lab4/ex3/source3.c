#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    // ������ ������ �������
    int N;
    printf("������� ������ ������� N (�� ������ 100): ");
    scanf_s("%d", &N);

    if (N > 100) {
        printf("�������� ������������ ������ �������.\n");
        return 1;
    }

    // ��������� ������� �������� NxN
    int matrix[100][100];

    // ������ �������� �������
    printf("������� �������� �������:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("element [%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    int minElement;

    // �������� �� ��������� �� ������ ������� � ������� ����������� �������
    for (int i = 0; i < N / 2; i++) {
        for (int j = N / 2; j < N; j++) {
            if (matrix[i][j] < matrix[0][N / 2]) {
                minElement = matrix[i][j];
            }
        }
    }

    // ������� ���������
    printf("����������� ������� �� ������ ������� �������: %d\n", minElement);

    return 0;
}
