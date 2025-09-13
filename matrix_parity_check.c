/*
 * Purpose: Checks the parity of row and column sums in a matrix to detect single bit errors.
 * Topic: Arrays (2D), Loops, Conditional Logic, Error Detection
 */

#include <stdio.h>

void read_matrix(int n, int matrix[n][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void calculate_row_sums(int n, int matrix[n][n], int sums[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        sums[i] = 0;
        for (j = 0; j < n; j++) {
            sums[i] += matrix[i][j];
        }
    }
}

void calculate_column_sums(int n, int matrix[n][n], int sums[]) {
    int i, j;
    for (j = 0; j < n; j++) {
        sums[n + j] = 0;
        for (i = 0; i < n; i++) {
            sums[n + j] += matrix[i][j];
        }
    }
}

int check_all_sums_even(int total_sums_count, int sums[]) {
    int i;
    for (i = 0; i < total_sums_count; i++) {
        if (sums[i] % 2) {
            return 0;
        }
    }
    return 1;
}

void check_parity_errors(int n, int sums[]) {
    int odd_row_count = 0;
    int odd_col_count = 0;
    int odd_row_idx = -1;
    int odd_col_idx = -1;
    int i;

    for (i = 0; i < n; i++) {
        if (sums[i] % 2) {
            odd_row_count++;
            odd_row_idx = i;
        }
    }

    for (i = n; i < 2 * n; i++) {
        if (sums[i] % 2) {
            odd_col_count++;
            odd_col_idx = i;
        }
    }

    if (odd_row_count == 1 && odd_col_count == 1) {
        printf("Change bit (%d,%d)\n", odd_row_idx + 1, odd_col_idx + 1 - n);
    } else {
        printf("Corrupt\n");
    }
}

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n) {
        int matrix[n][n];
        int sums[2 * n];

        read_matrix(n, matrix);
        calculate_row_sums(n, matrix, sums);
        calculate_column_sums(n, matrix, sums);

        if (check_all_sums_even(2 * n, sums)) {
            printf("OK\n");
        } else {
            check_parity_errors(n, sums);
        }
    }

    return 0;
}
