#include <iostream>
#include <iomanip>
#include<locale>
#include "../Polinomials/SolutionsHeader.h"

using namespace std;
extern const int p = 4;

int main()
{
    setlocale(LC_ALL, "Russian");

    // 5 + 10x^2 + 6x^3
    int A[] = { 5, 0, 10, 6 };

    // 1 + 2x + 4x^2
    int B[] = { 1, 2, 4 };
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    galois_field(A, m, p);
    galois_field(B, n, p);

    cout << "\tЗачётная работа (Иванов Р., ИТ-41)\nЗадание: разработать библиотеку для работы с полиномами над простым полем Галуа\n";

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

    int* prod1 = multiply_const(A, m, p);

    cout << "\nПроизведение 1-ого полинома на p=" << p << " равно\n\t";
    printPoly(prod1, m);

    int* prod2 = multiply_const(B, n, p);

    cout << "\nПроизведение 2-ого полинома на p=" << p << " равно\n\t";
    printPoly(prod2, n);

    int x;
    cout << "\n\nВведите x для нахождения значения полинома в точке: "; cin >> x;
    int prod11 = calculation_poly(A, m, x);
    cout << "\nЗначение 1-ого полинома в точке x равно " << prod11;

    int prod12 = calculation_poly(B, n, x);
    cout << "\nЗначение 2-ого полинома в точке x равно " << prod12 << endl;

    return 0;
}