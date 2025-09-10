/*
 * Purpose: Performs element-wise addition of two 5x5 integer matrices and prints the resulting sum matrix.
 * Topic: Arrays (Multi-dimensional), Loops, Basic I/O
 */

#include <stdio.h>

#define ROWS 5 // Number of rows in the matrices
#define COLS 5 // Number of columns in the matrices

int main() {
    int matrix_a[ROWS][COLS]; // The first matrix
    int matrix_b[ROWS][COLS]; // The second matrix
    int sum_matrix[ROWS][COLS]; // Stores the element-wise sum
    int i, j;

    printf("--- Enter Elements for Matrix A (%d x %d) ---\n", ROWS, COLS);
    // Read elements for the first matrix
    for (i = 0; i < ROWS; i++) {
        printf("Enter elements for row %d (space-separated): ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("\n--- Enter Elements for Matrix B (%d x %d) ---\n", ROWS, COLS);
    // Read elements for the second matrix
    for (i = 0; i < ROWS; i++) {
        printf("Enter elements for row %d (space-separated): ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // Perform element-wise addition of the two matrices.
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    printf("\n--- Resultant Sum Matrix (%d x %d) ---\n", ROWS, COLS);
    // Print the final sum matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%-4d", sum_matrix[i][j]); // Print with formatting
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}