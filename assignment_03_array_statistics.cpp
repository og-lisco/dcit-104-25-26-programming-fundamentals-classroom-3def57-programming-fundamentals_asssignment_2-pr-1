// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to print a matrix in a neat grid using setw()
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// Helper function to read matrix elements from the user
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// PART A: Transpose Matrix (rows become columns, columns become rows)
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// PART B: Add Two Matrices (element-wise addition)
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices (A is M x N, B is N x P, Result is M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // -------------------------------------------------------------
    // PART A - TRANSPOSE
    // -------------------------------------------------------------
    cout << "=== PART A: TRANSPOSE A MATRIX ===" << endl;
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    int matA[MAX_SIZE][MAX_SIZE];
    readMatrix(matA, rowsA, colsA);

    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matA, transposed, rowsA, colsA);

    cout << "\nOriginal Matrix:\n";
    printMatrix(matA, rowsA, colsA);

    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, colsA, rowsA);

    // -------------------------------------------------------------
    // PART B - ADDITION
    // -------------------------------------------------------------
    cout << "\n=== PART B: ADD TWO MATRICES ===" << endl;
    int rowsAdd, colsAdd;
    cout << "Enter number of rows for both matrices: ";
    cin >> rowsAdd;
    cout << "Enter number of columns for both matrices: ";
    cin >> colsAdd;

    int addA[MAX_SIZE][MAX_SIZE], addB[MAX_SIZE][MAX_SIZE], addResult[MAX_SIZE][MAX_SIZE];
    
    cout << "\nEnter Matrix 1 elements:\n";
    readMatrix(addA, rowsAdd, colsAdd);
    
    cout << "\nEnter Matrix 2 elements:\n";
    readMatrix(addB, rowsAdd, colsAdd);

    addMatrices(addA, addB, addResult, rowsAdd, colsAdd);

    cout << "\nSum Matrix:\n";
    printMatrix(addResult, rowsAdd, colsAdd);

    // -------------------------------------------------------------
    // PART C - MULTIPLICATION
    // -------------------------------------------------------------
    cout << "\n=== PART C: MULTIPLY TWO MATRICES ===" << endl;
    int M, N, P;
    cout << "Enter rows of Matrix A (M): ";
    cin >> M;
    cout << "Enter cols of Matrix A / rows of Matrix B (N): ";
    cin >> N;
    cout << "Enter cols of Matrix B (P): ";
    cin >> P;

    int multA[MAX_SIZE][MAX_SIZE], multB[MAX_SIZE][MAX_SIZE], multResult[MAX_SIZE][MAX_SIZE];

    cout << "\nEnter Matrix A (" << M << "x" << N << ") elements:\n";
    readMatrix(multA, M, N);

    cout << "\nEnter Matrix B (" << N << "x" << P << ") elements:\n";
    readMatrix(multB, N, P);

    multiplyMatrices(multA, multB, multResult, M, N, P);

    cout << "\nProduct Matrix (" << M << "x" << P << "):\n";
    printMatrix(multResult, M, P);

    return 0;
}
// =============================================================================



