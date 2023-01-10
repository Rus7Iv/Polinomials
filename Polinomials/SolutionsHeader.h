#pragma once

int* galois_field(int A[], int n, int p);
void printPoly(int poly[], int n);

int* add(int A[], int B[], int m, int n);
int* subtraction(int A[], int B[], int m, int n);
int* multiply(int A[], int B[], int m, int n);
int* multiply_const(int A[], int n, int p);
int calculation_poly(int A[], int n, int x);