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
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Displays a matrix in a neat, aligned grid
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }                
}

// Reads a matrix of the given dimensions from user input
void readMatrix(int mat [MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

//  PART A: Transposes an M x N matrix into an N x M matrix
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

// PART B: Adds two matrices of the same size, element by element
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

//PART C: Multiplies an M x N matrix with an N x P matrix, resulting in an M x P matrix
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // ------- PART A: Transpose -------
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix1, rows, cols);

    transposeMatrix(matrix1, rows, cols, resultMatrix);

    cout << "Original matrix:" << endl;
    displayMatrix(matrix1, rows, cols);

    cout << "Transposed matrix:" << endl;
    displayMatrix(resultMatrix, cols, rows);


// ------- PART B: Add Matrices -------
cout << "Enter number of rows: ";
cin >> rows;
cout << "Enter number of columns: ";
cin >> cols;

cout << "Enter elements for Matrix 1:" << endl;
readMatrix(matrix1, rows, cols);

    cout << "Enter elements for Matrix 2:" << endl;
    readMatrix(matrix2, rows, cols);

addMatrices(matrix1, matrix2, rows, cols, resultMatrix);

cout << "Sum of matrices:" << endl;
displayMatrix(resultMatrix, rows, cols);

// ------- PART C: Multiply Matrices -------
int rows1, cols1, rows2, cols2;
cout << "Enter number of rows for Matrix A: ";
cin >> rows1;
cout << "Enter number of columns for Matrix A: ";
cin >> cols1;
cout << "Enter number of rows for Matrix B: ";
cin >> rows2;
cout << "Enter number of columns for Matrix B: ";
cin >> cols2;

cout << "Enter elements for Matrix A:" << endl;
readMatrix(matrix1, rows1, cols1);

cout << "Enter elements for Matrix B:" << endl;
readMatrix(matrix2, rows2, cols2);

multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2, resultMatrix);

cout << "Product of matrices:" << endl;
displayMatrix(resultMatrix, rows1, cols2);

    return 0;
}
