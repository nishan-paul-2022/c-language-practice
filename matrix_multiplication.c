/*
 * Purpose: Performs matrix multiplication for two matrices of compatible dimensions.
 * Topic: 2D Arrays, Matrix Operations, Loops, Input Validation
 */

#include <stdio.h>

#define MAX_DIM 10 // Maximum dimension for the matrices

// Function to read matrix elements from the user
void read_matrix(int rows, int cols, double matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter numeric values only.\n");
                // Exit if input is invalid to avoid further errors
                exit(1);
            }
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, double matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%-8.2lf", matrix[i][j]); // Print with formatting
        }
        printf("\n");
    }
}

int main(void) {
    int r1, c1, r2, c2;
    double matrix1[MAX_DIM][MAX_DIM], matrix2[MAX_DIM][MAX_DIM], result[MAX_DIM][MAX_DIM];

    // Get dimensions for the first matrix
    printf("Enter dimensions for Matrix 1 (rows cols): ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0 || r1 > MAX_DIM || c1 > MAX_DIM) {
        printf("Invalid dimensions. Rows and columns must be between 1 and %d.\n", MAX_DIM);
        return 1;
    }

    // Get dimensions for the second matrix
    printf("Enter dimensions for Matrix 2 (rows cols): ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0 || r2 > MAX_DIM || c2 > MAX_DIM) {
        printf("Invalid dimensions. Rows and columns must be between 1 and %d.\n", MAX_DIM);
        return 1;
    }

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Columns of Matrix 1 must equal rows of Matrix 2.\n");
        return 1;
    }

    // Read elements for both matrices
    printf("\nEnter elements for Matrix 1 (%d x %d):\n", r1, c1);
    read_matrix(r1, c1, matrix1);

    printf("\nEnter elements for Matrix 2 (%d x %d):\n", r2, c2);
    read_matrix(r2, c2, matrix2);

    // Perform matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the resulting matrix
    printf("\nResult of Matrix Multiplication (%d x %d):\n", r1, c2);
    print_matrix(r1, c2, result);

    return 0;
}