#include <iostream>
#include <iomanip>
#include<locale>
#include <cmath>
using namespace std;

int max(int m, int n) { return (m > n) ? m : n; }

// Сложение двух полиномов
int* add(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* sum = new int[size];

    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}

// Вычитание двух полиномов
int* subtraction(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* difference = new int[size];

    for (int i = 0; i < m; i++)
        difference[i] = A[i];

    for (int i = 0; i < n; i++)
        difference[i] -= B[i];

    return difference;
}

// Умножение двух полиномов
int* multiply(int A[], int B[], int m, int n)
{
    int* prod = new int[m + n - 1];

    for (int i = 0; i < m + n - 1; i++)
        prod[i] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            prod[i + j] += A[i] * B[j];
    }

    return prod;
}

// Умножение полинома на константу
int* multiply_const(int A[], int n, int p)
{
    int* prod = new int[n];

    for (int i = 0; i < n; i++)
        prod[i] = 0;

    for (int i = 0; i < n; i++)
    {
        prod[i] += A[i] * p;
    }

    return prod;
}

// Вычисление полинома в точке
int calculation_poly(int A[], int n, int x)
{
    int prod = 0;

    for (int i = 0; i < n; i++)
    {
        prod += A[i] * pow(x,i);
    }

    return prod;
}

// Вовод полинома в консоли
void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != n - 1)
            cout << " + ";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // 5 + 10x^2 + 6x^3
    int A[] = { 5, 0, 10, 6 };

    // 1 + 2x + 4x^2
    int B[] = { 1, 2, 4 };
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    cout << "\tЗачётная работа (Иванов Р., ИТ-41)\nЗадание: разработать библиотеку для работы с полиномами\n";

    cout << "\nПервый полином равен \n\t";
    printPoly(A, m);
    cout << "\nВторой полином равен \n\t";
    printPoly(B, n);

    int* sum = add(A, B, m, n);
    int size = max(m, n);

    cout << "\nСумма 2-ух полиномов равна \n\t";
    printPoly(sum, size);

    int* difference = subtraction(A, B, m, n);

    cout << "\nРазность 2-ух полиномов равна\n\t";
    printPoly(difference, size);

    int* prod = multiply(A, B, m, n);

    cout << "\nПроизведение 2-ух полиномов равно\n\t";
    printPoly(prod, m + n - 1);

    const int p = 10;
    int* prod1 = multiply_const(A, m, p);

    cout << "\nПроизведение 1-ого полинома на p=10 равно\n\t";
    printPoly(prod1, m);

    int* prod2 = multiply_const(B, n, p);

    cout << "\nПроизведение 2-ого полинома на p=10 равно\n\t";
    printPoly(prod2, n);

    int x;
    cout << "\n\nВведите x для нахождения значения полинома в точке: "; cin >> x;
    int prod11 = calculation_poly(A, m, x);
    cout << "\nЗначение 1-ого полинома в точке x равно " << prod11;

    int prod12 = calculation_poly(B, n, x);
    cout << "\nЗначение 2-ого полинома в точке x равно " << prod12 << endl;

    return 0;
}