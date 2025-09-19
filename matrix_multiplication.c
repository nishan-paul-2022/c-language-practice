/*
 * Purpose: Performs matrix multiplication for two matrices of compatible dimensions.
 * Topic: 2D Arrays, Matrix Operations, Loops, Input Validation
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 10

int read_matrix_dimensions(int *rows, int *cols, int matrix_num) {
    printf("Enter dimensions for Matrix %d (rows cols): ", matrix_num);

    if (scanf("%d %d", rows, cols) != 2 || *rows <= 0 || *cols <= 0 || *rows > MAX_DIM || *cols > MAX_DIM) {
        printf("Invalid dimensions. Rows and columns must be between 1 and %d.\n", MAX_DIM);
        return -1;
    }

    return 0;
}

int read_matrix_elements(int rows, int cols, double matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter numeric values only.\n");
                return -1;
            }
        }
    }

    return 0;
}

void multiply_matrices(int r1, int c1, int c2, double matrix1[MAX_DIM][MAX_DIM], 
                      double matrix2[MAX_DIM][MAX_DIM], double result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void print_matrix(int rows, int cols, double matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%-8.2lf", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int r1, c1;
    if (read_matrix_dimensions(&r1, &c1, 1) == -1) {
        return 0;
    }

    int r2, c2;
    if (read_matrix_dimensions(&r2, &c2, 2) == -1) {
        return 0;
    }

    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Columns of Matrix 1 must equal rows of Matrix 2.\n");
        return 0;
    }

    double matrix1[MAX_DIM][MAX_DIM];
    printf("\nEnter elements for Matrix 1 (%d x %d):\n", r1, c1);
    if (read_matrix_elements(r1, c1, matrix1) == -1) {
        return 0;
    }

    double matrix2[MAX_DIM][MAX_DIM];
    printf("\nEnter elements for Matrix 2 (%d x %d):\n", r2, c2);
    if (read_matrix_elements(r2, c2, matrix2) == -1) {
        return 0;
    }

    double result[MAX_DIM][MAX_DIM];
    multiply_matrices(r1, c1, c2, matrix1, matrix2, result);

    printf("\n\nResult of Matrix Multiplication (%d x %d):\n", r1, c2);
    print_matrix(r1, c2, result);

    return 0;
}
