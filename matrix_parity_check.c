/*
 * Purpose: Checks the parity of row and column sums in a matrix to detect single bit errors.
 * Topic: Arrays (2D), Loops, Conditional Logic, Error Detection
 */

#include <stdio.h>
#include <stdlib.h>


int** allocate_matrix(int n) {
    int **matrix = (int**)malloc(n * sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}


void free_matrix(int **matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}


void read_matrix(int n, int **matrix) {
    printf("Enter matrix elements row by row:\n");

    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


void calculate_row_sums(int n, int **matrix, int sums[]) {
    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < n; j++) {
            sums[i] += matrix[i][j];
        }
    }
}


void calculate_column_sums(int n, int **matrix, int sums[]) {
    for (int j = 0; j < n; j++) {
        sums[n + j] = 0;
        for (int i = 0; i < n; i++) {
            sums[n + j] += matrix[i][j];
        }
    }
}


int check_all_sums_even(int total_sums_count, int sums[]) {
    for (int i = 0; i < total_sums_count; i++) {
        if (sums[i] % 2) {
            return 0;
        }
    }

    return 1;
}


void check_parity_errors(int n, int sums[]) {
    int odd_row_count = 0;
    int odd_row_idx = -1;
    for (int i = 0; i < n; i++) {
        if (sums[i] % 2) {
            odd_row_count++;
            odd_row_idx = i;
        }
    }

    int odd_col_count = 0;
    int odd_col_idx = -1;
    for (int i = n; i < 2 * n; i++) {
        if (sums[i] % 2) {
            odd_col_count++;
            odd_col_idx = i - n;
        }
    }

    if (odd_row_count == 1 && odd_col_count == 1) {
        printf("Change bit (%d,%d)\n", odd_row_idx + 1, odd_col_idx + 1);
    } else {
        printf("Corrupt\n");
    }
}

int main(void) {    
    printf("Matrix Parity Error Detection Program\n");
    printf("=====================================\n");
    
    while (1) {
        int n;
        printf("\nEnter matrix size (0 to exit): ");
        if (scanf("%d", &n) != 1 || n == 0) {
            printf("Program terminated.\n");
            break;
        }
        
        if (n < 0) {
            printf("Invalid matrix size. Please enter a positive number.\n");
            continue;
        }
        
        int **matrix = allocate_matrix(n);
        if (matrix == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 0;
        }
        
        read_matrix(n, matrix);

        int sums[2 * n];
        calculate_row_sums(n, matrix, sums);
        calculate_column_sums(n, matrix, sums);

        printf("Parity check result: ");
        if (check_all_sums_even(2 * n, sums)) {
            printf("OK\n");
        } else {
            check_parity_errors(n, sums);
        }
        
        free_matrix(matrix, n);
    }

    return 0;
}
