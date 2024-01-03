#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ������� ��� ���������� ������� ������� ������������ ������� �� 99
void fillArray(int** arr, int* size) {
    *size = 49; // ������������ ���������� ������ ����� �� 99
    *arr = (int*)malloc(*size * sizeof(int));

    // �������� �� �������� ��������� ������
    if (*arr == NULL) {
        printf("������ ��������� ������.\n");
        exit(1);
    }

    int index = 0;
    for (int i = 2; i <= 99; i += 2) {
        (*arr)[index++] = i;
    }
}

// ������� ��� �������� �����, �� ������������� ������� [a, b]
void filterArray(int** arr, int* size, int a, int b) {
    int newSize = 0;

    for (int i = 0; i < *size; ++i) {
        if ((*arr)[i] >= a && (*arr)[i] <= b) {
            (*arr)[newSize++] = (*arr)[i];
        }
    }

    // ������������ ���������� ������
    *arr = (int*)realloc(*arr, newSize * sizeof(int));

    // �������� �� �������� ��������� ������
    if (*arr == NULL && newSize > 0) {
        printf("������ ��������� ������.\n");
        exit(1);
    }

    *size = newSize;
}

// ������� ��� ������ ������� �� �����
void printArray(const int* arr, int size) {
    printf("������: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Russian");
    int* array;
    int size;

    fillArray(&array, &size);

    // ����� ������������ �������
    printArray(array, size);

    int a, b;
    printf("������� ������� ������� [a, b]: ");
    scanf_s("%d %d", &a, &b);

    // �������� �� ������������ ��������� ������
    if (a > b) {
        printf("������: b ������ ���� �� ������ a.\n");
        return 1;
    }

    // �������� �����, �� ������������� ������� [a, b]
    filterArray(&array, &size, a, b);

    // ����� ���������������� �������
    printArray(array, size);

    // ������������ ������
    free(array);

    return 0;
}
