/*
 * Purpose: Performs matrix multiplication for two matrices.
 * Topic: 2D arrays, matrix operations, loops, input/output.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 10 // Define a reasonable maximum dimension for matrices

int main(void) {
    int R1, C1_R2, C2; // Dimensions: Matrix1 (R1 x C1_R2), Matrix2 (C1_R2 x C2)
    double matrix1[MAX_DIM][MAX_DIM];
    double matrix2[MAX_DIM][MAX_DIM];
    double result_matrix[MAX_DIM][MAX_DIM];
    int i, j, k;
    double sum; // To store the sum for matrix multiplication

    printf("Enter dimensions for Matrix 1 (rows cols, e.g., '3 4'): ");
    // Read dimensions for the first matrix and validate
    if (scanf("%d %d", &R1, &C1_R2) != 2) {
        printf("Invalid input for Matrix 1 dimensions. Please enter two integers separated by a space.\n");
        return 0;
    }

    // Validate dimensions for Matrix 1
    if (R1 <= 0 || R1 > MAX_DIM || C1_R2 <= 0 || C1_R2 > MAX_DIM) {
        printf("Invalid dimensions for Matrix 1. Rows and columns must be positive and within limits (max %d x %d).\n", MAX_DIM, MAX_DIM);
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    printf("Enter dimensions for Matrix 2 (rows cols, e.g., '4 2'): ");
    // Read dimensions for the second matrix and validate
    if (scanf("%d %d", &C1_R2, &C2) != 2) { // Note: C1_R2 must match for multiplication
        printf("Invalid input for Matrix 2 dimensions. Please enter two integers separated by a space.\n");
        return 0;
    }

    // Validate dimensions for Matrix 2
    if (C1_R2 <= 0 || C1_R2 > MAX_DIM || C2 <= 0 || C2 > MAX_DIM) {
        printf("Invalid dimensions for Matrix 2. Rows and columns must be positive and within limits (max %d x %d).\n", MAX_DIM, MAX_DIM);
        return 0;
    }

    // Check if matrix multiplication is possible
    // The number of columns in the first matrix must equal the number of rows in the second matrix.
    // This is already handled by using C1_R2 for both.

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    printf("\\nEnter elements for Matrix 1 (%d x %d):\n", R1, C1_R2);
    // Read elements for Matrix 1
    for (i = 0; i < R1; i++) {
        for (j = 0; j < C1_R2; j++) {
            printf("Enter element matrix1[%d][%d]: ", i, j);
            if (scanf("%lf", &matrix1[i][j]) != 1) {
                printf("Invalid input for element matrix1[%d][%d]. Please enter a double.\n", i, j);
                return 0;
            }
            // Consume the newline character left by scanf
            while (getchar() != '\n');
        }
    }

    printf("\\nEnter elements for Matrix 2 (%d x %d):\n", C1_R2, C2);
    // Read elements for Matrix 2
    for (i = 0; i < C1_R2; i++) {
        for (j = 0; j < C2; j++) {
            printf("Enter element matrix2[%d][%d]: ", i, j);
            if (scanf("%lf", &matrix2[i][j]) != 1) {
                printf("Invalid input for element matrix2[%d][%d]. Please enter a double.\n", i, j);
                return 0;
            }
            // Consume the newline character left by scanf
            while (getchar() != '\n');
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < R1; i++) { // Iterate through rows of the result matrix
        for (j = 0; j < C2; j++) { // Iterate through columns of the result matrix
            sum = 0.0; // Initialize sum for the current element of the result matrix
            for (k = 0; k < C1_R2; k++) { // Iterate through elements for dot product
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result_matrix[i][j] = sum; // Store the calculated sum
        }
    }

    printf("\\nResult of Matrix Multiplication (%d x %d):\n", R1, C2);
    // Print the resulting matrix
    for (i = 0; i < R1; i++) {
        for (j = 0; j < C2; j++) {
            printf("%.2lf ", result_matrix[i][j]);
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}
