/*
 * Purpose: Demonstrates matrix transpose and summing elements of a specified row or column.
 * Topic: 2D Arrays, Matrix Transpose, Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int read_matrix_dimensions(int *rows, int *cols) {
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", rows, cols) != 2) {
        fprintf(stderr, "Error: Invalid input for dimensions.\n");
        return -1;
    }
    while (getchar() != '\n');

    if (*rows <= 0 || *rows > MAX_ROWS || *cols <= 0 || *cols > MAX_COLS) {
        fprintf(stderr, "Error: Dimensions out of range. Rows: 1-%d, Cols: 1-%d\n", MAX_ROWS, MAX_COLS);
        return -1;
    }
    return 0;
}

int read_matrix_elements(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    printf("Enter the elements of the %d x %d matrix:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error: Invalid input for element [%d][%d].\n", i, j);
                return -1;
            }
        }
    }
    while (getchar() != '\n');
    return 0;
}

void print_original_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_transposed_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    printf("\nTransposed Matrix:\n");
    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculate_row_sum(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int row_index, sum = 0, j;
    printf("\nEnter a row index (0 to %d) to sum its elements, or -1 to skip row sum: ", rows - 1);
    scanf("%d", &row_index);
    while (getchar() != '\n');

    if (row_index != -1) {
        if (row_index < 0 || row_index >= rows) {
            fprintf(stderr, "Error: Row index out of bounds.\n");
        } else {
            for (j = 0; j < cols; j++) {
                sum += matrix[row_index][j];
            }
            printf("Sum of elements in row %d: %d\n", row_index, sum);
        }
    }
}

void calculate_column_sum(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int col_index, sum = 0, i;
    printf("\nEnter a column index (0 to %d) to sum its elements, or -1 to skip column sum: ", cols - 1);
    scanf("%d", &col_index);
    while (getchar() != '\n');

    if (col_index != -1) {
        if (col_index < 0 || col_index >= cols) {
            fprintf(stderr, "Error: Column index out of bounds.\n");
        } else {
            for (i = 0; i < rows; i++) {
                sum += matrix[i][col_index];
            }
            printf("Sum of elements in column %d: %d\n", col_index, sum);
        }
    }
}

int main(void) {
    int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];

    if (read_matrix_dimensions(&rows, &cols) == -1) {
        return 0;
    }

    if (read_matrix_elements(rows, cols, matrix) == -1) {
        return 0;
    }

    print_original_matrix(rows, cols, matrix);
    print_transposed_matrix(rows, cols, matrix);
    calculate_row_sum(rows, cols, matrix);
    calculate_column_sum(rows, cols, matrix);

    return 0;
}
