#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Функція для виведення масиву
void PrintArray(double mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(6) << mas[i] << " ";
    PrintArray(mas, size, i + 1);
}

// Рекурсивна функція для підрахунку кількості додатних елементів
int CountPositive(double mas[], int size, int i = 0) {
    if (i == size) return 0; 
    return (mas[i] > 0 ? 1 : 0) + CountPositive(mas, size, i + 1);
}

// Рекурсивна функція для знаходження індексу останнього нульового елемента
int FindLastZeroIndex(double mas[], int size, int i = 0, int lastZeroIndex = -1) {
    if (i == size) return lastZeroIndex;
    if (mas[i] == 0) {
        lastZeroIndex = i;
    }
    return FindLastZeroIndex(mas, size, i + 1, lastZeroIndex); 
}

// Рекурсивна функція для обчислення суми елементів після останнього нульового елемента
double SumAfterLastZero(double mas[], int size, int i = 0) {
    int lastZeroIndex = FindLastZeroIndex(mas, size); 
    if (lastZeroIndex == -1 || i <= lastZeroIndex) return 0; 
    return mas[i] + SumAfterLastZero(mas, size, i + 1); 
}

// Рекурсивна функція для перестановки елементів масиву
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
    cout << "Введіть кількість елементів масиву n: ";
    cin >> n;

    double* mas = new double[n];

    cout << "Введіть елементи масиву: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "Початковий масив: " << endl;
    PrintArray(mas, n);

    // 1.1. Кількість додатних елементів
    int positiveCount = CountPositive(mas, n);
    cout << "Кількість додатних елементів: " << positiveCount << endl;

    // 1.2. Сума елементів після останнього нульового елемента
    double sumAfterZero = SumAfterLastZero(mas, n);
    cout << "Сума елементів після останнього нуля: " << sumAfterZero << endl;

    // 2. Перетворення масиву
    ReorderArray(mas, n);

    cout << "Перетворений масив: " << endl;
    PrintArray(mas, n);

    delete[] mas;
    return 0;
}
