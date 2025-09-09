/*
 * Purpose: Performs element-wise addition of two 5x5 integer matrices and prints the resulting sum matrix.
 * Topic: Arrays (Multi-dimensional), Loops, Basic I/O
 */

#include <stdio.h> // Required for printf and scanf

#define ROWS 5 // Define number of rows
#define COLS 5 // Define number of columns

int main() {
    int matrix_a[ROWS][COLS]; // First matrix
    int matrix_b[ROWS][COLS]; // Second matrix
    int sum_matrix[ROWS][COLS]; // Matrix to store the sum
    int i, j;

    printf("Enter elements for Matrix A (%dx%d):\n", ROWS, COLS);
    // Read elements for Matrix A
    for (i = 0; i < ROWS; i++) {
        printf("Row %d (space-separated integers): ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("\nEnter elements for Matrix B (%dx%d):\n", ROWS, COLS);
    // Read elements for Matrix B
    for (i = 0; i < ROWS; i++) {
        printf("Row %d (space-separated integers): ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // Calculate the sum of the two matrices
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    printf("\nResultant Sum Matrix (%dx%d):\n", ROWS, COLS);
    // Print the sum matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", sum_matrix[i][j]);
        }
        printf("\n"); // Newline after each row
    }
    printf("\n");

    return 0;
}
