// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Read elements for a matrix
void readMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
}

// Display matrix in a formatted grid
void printMatrix(const int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << setw(5) << mat[i][j];
        cout << endl;
    }
}

// PART A: Transpose
void transpose(const int src[MAX][MAX], int dest[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) dest[j][i] = src[i][j];
}

// PART B: Add two matrices
void add(const int A[MAX][MAX], const int B[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) res[i][j] = A[i][j] + B[i][j];
}

// PART C: Multiply two matrices (M x N * N x P)
void multiply(const int A[MAX][MAX], const int B[MAX][MAX], int res[MAX][MAX], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) res[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], Res[MAX][MAX];
    int r, c, M, N, P;

    // --- Part A: Transpose ---
    cout << "--- Part A: Transpose ---\nEnter rows and cols: ";
    cin >> r >> c;
    readMatrix(A, r, c);
    transpose(A, Res, r, c);
    cout << "\nOriginal:\n"; printMatrix(A, r, c);
    cout << "\nTransposed:\n"; printMatrix(Res, c, r);

    // --- Part B: Addition ---
    cout << "\n--- Part B: Addition ---\nEnter rows and cols: ";
    cin >> r >> c;
    cout << "Matrix A:\n"; readMatrix(A, r, c);
    cout << "Matrix B:\n"; readMatrix(B, r, c);
    add(A, B, Res, r, c);
    cout << "\nSum:\n"; printMatrix(Res, r, c);

    // --- Part C: Multiplication ---
    cout << "\n--- Part C: Multiplication ---\nEnter M, N, P: ";
    cin >> M >> N >> P;
    cout << "Matrix A (" << M << "x" << N << "):\n"; readMatrix(A, M, N);
    cout << "Matrix B (" << N << "x" << P << "):\n"; readMatrix(B, N, P);
    multiply(A, B, Res, M, N, P);
    cout << "\nProduct:\n"; printMatrix(Res, M, P);

    return 0;
}
// =============================================================================


