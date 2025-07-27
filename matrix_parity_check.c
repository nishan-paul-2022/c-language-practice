// Purpose: Checks the parity of row and column sums in a matrix to detect single bit errors.
// Topic: Arrays (2D), Loops, Conditional Logic, Error Detection

#include <stdio.h>

int main() {
    int n; // Size of the square matrix

    // Loop to process multiple matrices until n is 0
    while (scanf("%d", &n) == 1 && n != 0) {
        int i, j;
        int row_sum_index = 0;
        int col_sum_index;
        int total_sums_count = 2 * n; // n rows + n columns

        // Declare Variable Length Arrays (VLAs) for matrix and sums
        int matrix[n][n];
        int sums[total_sums_count];

        // Read matrix elements
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        // Calculate row sums
        for (i = 0; i < n; i++) {
            sums[row_sum_index] = 0; // Initialize sum for current row
            for (j = 0; j < n; j++) {
                sums[row_sum_index] += matrix[i][j];
            }
            row_sum_index++;
        }

        // Calculate column sums
        col_sum_index = n; // Start column sums after row sums in the 'sums' array
        for (j = 0; j < n; j++) {
            sums[col_sum_index] = 0; // Initialize sum for current column
            for (i = 0; i < n; i++) {
                sums[col_sum_index] += matrix[i][j];
            }
            col_sum_index++;
        }

        // Check if all sums are even
        int all_sums_even = 1;
        for (i = 0; i < total_sums_count; i++) {
            if (sums[i] % 2 != 0) {
                all_sums_even = 0;
                break;
            }
        }

        if (all_sums_even) {
            printf("OK\n");
        } else {
            int odd_row_count = 0;
            int odd_col_count = 0;
            int odd_row_idx = -1;
            int odd_col_idx = -1;

            // Count odd row sums and find the index of the first one
            for (i = 0; i < n; i++) {
                if (sums[i] % 2 != 0) {
                    odd_row_count++;
                    odd_row_idx = i;
                }
            }

            // Count odd column sums and find the index of the first one
            for (i = n; i < total_sums_count; i++) {
                if (sums[i] % 2 != 0) {
                    odd_col_count++;
                    odd_col_idx = i;
                }
            }

            // Determine output based on odd sum counts
            if (odd_row_count == 1 && odd_col_count == 1) {
                // Single bit change detected
                printf("Change bit (%d,%d)\n", odd_row_idx + 1, odd_col_idx + 1 - n);
            } else {
                // Multiple errors or corrupt matrix
                printf("Corrupt\n");
            }
        }
    }

    return 0;
}
