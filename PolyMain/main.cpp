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

    cout << "\t�������� ������ (������ �., ��-41)\n�������: ����������� ���������� ��� ������ � ���������� ��� ������� ����� �����\n";

    cout << "\n������ ������� ����� \n\t";
    printPoly(A, m);
    cout << "\n������ ������� ����� \n\t";
    printPoly(B, n);

    int* sum = add(A, B, m, n);
    int size = max(m, n);

    cout << "\n����� 2-�� ��������� ����� \n\t";
    printPoly(sum, size);

    int* difference = subtraction(A, B, m, n);

    cout << "\n�������� 2-�� ��������� �����\n\t";
    printPoly(difference, size);

    int* prod = multiply(A, B, m, n);

    cout << "\n������������ 2-�� ��������� �����\n\t";
    printPoly(prod, m + n - 1);

    int* prod1 = multiply_const(A, m, p);

    cout << "\n������������ 1-��� �������� �� p=" << p << " �����\n\t";
    printPoly(prod1, m);

    int* prod2 = multiply_const(B, n, p);

    cout << "\n������������ 2-��� �������� �� p=" << p << " �����\n\t";
    printPoly(prod2, n);

    int x;
    cout << "\n\n������� x ��� ���������� �������� �������� � �����: "; cin >> x;
    int prod11 = calculation_poly(A, m, x);
    cout << "\n�������� 1-��� �������� � ����� x ����� " << prod11;

    int prod12 = calculation_poly(B, n, x);
    cout << "\n�������� 2-��� �������� � ����� x ����� " << prod12 << endl;

    return 0;
}