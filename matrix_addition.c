/*
 * Purpose: Performs element-wise addition of two 5x5 integer matrices and prints the resulting sum matrix.
 * Topic: Arrays (Multi-dimensional), Loops, Basic I/O
 */

#include <stdio.h>

#define ROWS 5
#define COLS 5

void read_matrix(int matrix[ROWS][COLS], const char label[]) {
    int i, j;
    printf("--- Enter Elements for %s (%d x %d) ---\n", label, ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        printf("Enter elements for row %d (space-separated): ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void add_matrices(int matrix_a[ROWS][COLS], int matrix_b[ROWS][COLS], int sum_matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
}

void print_matrix(int matrix[ROWS][COLS], const char title[]) {
    int i, j;
    printf("\n--- %s (%d x %d) ---\n", title, ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%-4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int matrix_a[ROWS][COLS];
    int matrix_b[ROWS][COLS];
    int sum_matrix[ROWS][COLS];

    read_matrix(matrix_a, "Matrix A");
    printf("\n");
    read_matrix(matrix_b, "Matrix B");

    add_matrices(matrix_a, matrix_b, sum_matrix);
    print_matrix(sum_matrix, "Resultant Sum Matrix");

    return 0;
}
