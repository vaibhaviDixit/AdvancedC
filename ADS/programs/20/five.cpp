/*

Multiply two matrices using recursion.

Input:

Matrix A:
1 2 3
4 5 6
7 8 9
Matrix B:
9 8 7
6 5 4
3 2 1

Output:

Matrix C (Product of A and B):
30 24 18
84 69 54
138 114 90

*/

#include <iostream>
using namespace std;

const int N = 3;

void multiplyMatrices(int A[][N], int B[][N], int C[][N], int rowA, int colA, int colB) {
    if (rowA == N) {
        return;
    }

    if (colA == N) {
        multiplyMatrices(A, B, C, rowA + 1, 0, 0);
        return;
    }

    if (colB == N) {
        multiplyMatrices(A, B, C, rowA, colA + 1, 0);
        return;
    }

    C[rowA][colB] = 0;
    for (int k = 0; k < N; k++) {
        C[rowA][colB] += A[rowA][k] * B[k][colB];
    }

    multiplyMatrices(A, B, C, rowA, colA, colB + 1);
}

int main() {
    int A[N][N] = {{0, 1, 3}, {7, 3, 1}, {12, 6, 4}};
    int B[N][N] = {{11, 7, 32}, {9, 2, 9}, {3, 2, 8}};
    int C[N][N] = {0};

    multiplyMatrices(A, B, C, 0, 0, 0);

    cout << "Matrix A:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix C (Product of A and B):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
This program multiplies two matrices using recursion. It calculates the dot product of rows from matrix A and columns from matrix B to populate
the resulting matrix C.

*/
