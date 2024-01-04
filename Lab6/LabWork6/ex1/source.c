#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ������� ��� ���������� ������������� �������� � �������
int findMax(const int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ������� ��� ������ ���������� ����� ����� �����������
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ������� ��� ���������� ������� ������ ��������� ������� ������
void selectionSortEvenAfterMax(int* arr, int size) {
    int maxIndex = 0;

    // ������� ������ ������������� ��������
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    // ��������� ������������ ������� � ����� �������
    swap(&arr[maxIndex], &arr[size - 1]);

    // ��������� ������ �������� ����� ������������� ������� ������
    for (int i = 0; i < size - 1; i += 2) {
        int minIndex = i;
        for (int j = i + 2; j < size; j += 2) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;

    // ���� ������� �������
    printf("������� ������ �������: ");
    scanf_s("%d", &size);

    // ��������� ������������ ������ ��� ������
    int* arr = (int*)malloc(size * sizeof(int));

    // ���� ��������� �������
    printf("������� �������� �������:\n");
    for (int i = 0; i < size; ++i) {
        scanf_s("%d", &arr[i]);
    }

    // ����� ������� ��� ���������� ������ ��������� ����� �������������
    selectionSortEvenAfterMax(arr, size);

    // ����� ���������������� �������
    printf("��������������� ������:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    // ������������ ���������� ������
    free(arr);

    return 0;
}
