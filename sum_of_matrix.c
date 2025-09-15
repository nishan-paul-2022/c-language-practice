/*
 * Purpose: Reads matrix dimensions and values, prints sum of each row and column, 
 *          sums of main and secondary diagonals, and total sum of all values.
 * Topic: Nested Loops, Matrix Operations, Summation
 */

#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // discard leftover input
}

void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double** allocate_matrix(int rows, int cols) {
    double **matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Error: Memory allocation failed.\n");
            free_matrix(matrix, i);
            return NULL;
        }
    }
    return matrix;
}

int read_positive_int(const char *prompt) {
    int n;
    printf("%s", prompt);
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a valid positive integer.\n");
        return -1;
    }
    clear_input_buffer();
    return n;
}

int read_matrix(int rows, int cols, double **matrix) {
    for (int i = 0; i < rows; i++) {
        printf("Enter %d values for row %d: ", cols, i + 1);
        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("\nError: Invalid input detected. Stopping program.\n");
                return -1;
            }
        }
        clear_input_buffer();
    }
    return 0;
}

void print_row_sums(int rows, int cols, double **matrix) {
    for (int i = 0; i < rows; i++) {
        double sum = 0.0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of row %d: %.2lf\n", i + 1, sum);
    }
}

void print_column_sums(int rows, int cols, double **matrix) {
    for (int j = 0; j < cols; j++) {
        double sum = 0.0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of column %d: %.2lf\n", j + 1, sum);
    }
}

void calculate_main_diagonal(int rows, int cols, double **matrix) {
    double sum = 0.0;
    for (int i = 0; i < rows && i < cols; i++) {
        sum += matrix[i][i];
    }
    printf("Sum of main diagonal: %.2lf\n", sum);
}

void calculate_secondary_diagonal(int rows, int cols, double **matrix) {
    double sum = 0.0;
    for (int i = 0; i < rows && i < cols; i++) {
        sum += matrix[i][cols - i - 1];
    }
    printf("Sum of secondary diagonal: %.2lf\n", sum);
}

void calculate_total_sum(int rows, int cols, double **matrix) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Total sum of all values: %.2lf\n", sum);
}

int main(void) {
    int rows = read_positive_int("Enter the number of rows: ");
    if (rows == -1) {
        return 0;
    }

    int cols = read_positive_int("Enter the number of columns: ");
    if (cols == -1) {
        return 0;
    }

    double **matrix = allocate_matrix(rows, cols);
    if (matrix == NULL) {
        return 0;
    }

    if (read_matrix(rows, cols, matrix) == -1) {
        return 0;
    }

    print_row_sums(rows, cols, matrix);
    print_column_sums(rows, cols, matrix);
    calculate_main_diagonal(rows, cols, matrix);
    calculate_secondary_diagonal(rows, cols, matrix);
    calculate_total_sum(rows, cols, matrix);

    free_matrix(matrix, rows);

    return 0;
}
