#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ������� ��� ��������� ������
void PrintArray(double mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(6) << mas[i] << " ";
    PrintArray(mas, size, i + 1);
}

// ���������� ������� ��� ��������� ������� �������� ��������
int CountPositive(double mas[], int size, int i = 0) {
    if (i == size) return 0; 
    return (mas[i] > 0 ? 1 : 0) + CountPositive(mas, size, i + 1);
}

// ���������� ������� ��� ����������� ������� ���������� ��������� ��������
int FindLastZeroIndex(double mas[], int size, int i = 0, int lastZeroIndex = -1) {
    if (i == size) return lastZeroIndex;
    if (mas[i] == 0) {
        lastZeroIndex = i;
    }
    return FindLastZeroIndex(mas, size, i + 1, lastZeroIndex); 
}

// ���������� ������� ��� ���������� ���� �������� ���� ���������� ��������� ��������
double SumAfterLastZero(double mas[], int size, int i = 0) {
    int lastZeroIndex = FindLastZeroIndex(mas, size); 
    if (lastZeroIndex == -1 || i <= lastZeroIndex) return 0; 
    return mas[i] + SumAfterLastZero(mas, size, i + 1); 
}

// ���������� ������� ��� ������������ �������� ������
void ReorderArray(double mas[], int size, int i = 0, int j = 0) {
    if (i == size) return;
    if (floor(mas[i]) <= 1) {
        swap(mas[i], mas[j]);
        ReorderArray(mas, size, i + 1, j + 1);
    }
    else {
        ReorderArray(mas, size, i + 1, j); 
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    cout << "������ ������� �������� ������ n: ";
    cin >> n;

    double* mas = new double[n];

    cout << "������ �������� ������: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "���������� �����: " << endl;
    PrintArray(mas, n);

    // 1.1. ʳ������ �������� ��������
    int positiveCount = CountPositive(mas, n);
    cout << "ʳ������ �������� ��������: " << positiveCount << endl;

    // 1.2. ���� �������� ���� ���������� ��������� ��������
    double sumAfterZero = SumAfterLastZero(mas, n);
    cout << "���� �������� ���� ���������� ����: " << sumAfterZero << endl;

    // 2. ������������ ������
    ReorderArray(mas, n);

    cout << "������������ �����: " << endl;
    PrintArray(mas, n);

    delete[] mas;
    return 0;
}
