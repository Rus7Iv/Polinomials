#include <iostream>
#include "SolutionsHeader.h"

using namespace std;
extern const int p;

int max(int m, int n) { return (m > n) ? m : n; }

// ??????? ???? ?????
int* galois_field(int A[], int n, int p)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= p) {
            A[i] = A[i] % p - 1;
        }
        if (A[i] < 0) {
            A[i] = p + A[i];
        }
    }

    return A;
}

// ????? ???????? ? ???????
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

// ???????? ???? ?????????
int* add(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* sum = new int[size];

    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    galois_field(sum, n, p);

    return sum;
}

// ????????? ???? ?????????
int* subtraction(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* difference = new int[size];

    for (int i = 0; i < m; i++)
        difference[i] = A[i];

    for (int i = 0; i < n; i++)
        difference[i] -= B[i];

    galois_field(difference, n, p);

    return difference;
}

// ????????? ???? ?????????
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

    galois_field(prod, n, p);

    return prod;
}

// ????????? ???????? ?? ?????????
int* multiply_const(int A[], int n, int p)
{
    int* prod = new int[n];

    for (int i = 0; i < n; i++)
        prod[i] = 0;

    for (int i = 0; i < n; i++)
    {
        prod[i] += A[i] * p;
    }

    galois_field(prod, n, p);

    return prod;
}

// ?????????? ???????? ? ?????
int calculation_poly(int A[], int n, int x)
{
    int prod = 0;

    galois_field(A, n, p);

    for (int i = 0; i < n; i++)
    {
        prod += A[i] * pow(x, i);
    }

    return prod;
}
