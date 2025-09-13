/*
 * Purpose: Generates and prints Pascal's triangle up to a specified number of rows using recursion.
 * Topic: Recursion, Binomial Coefficients, Nested Loops, Input Handling
 */

#include <stdio.h>

int calculate_pascal_value(int row, int col) {
    if (col < 1 || row < 1 || col > row) {
        return 0;
    }

    if (col == 1 || col == row) {
        return 1;
    }
    
    int ans = calculate_pascal_value(row - 1, col) + calculate_pascal_value(row - 1, col - 1);
    return ans;
}

int read_num_rows(void) {
    int num_rows;
    printf("Enter the number of rows for Pascal's triangle: ");
    
    if (scanf("%d", &num_rows) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of rows.\n");
        while (getchar() != '\n');
        return -1;
    }

    if (num_rows < 0) {
        fprintf(stderr, "Error: Number of rows cannot be negative.\n");
        return -1;
    }
    
    return num_rows;
}

void print_pascal_triangle(int num_rows) {
    if (num_rows == 0) {
        printf("No rows to display.\n");
        return;
    }

    for (int row_index = 1; row_index <= num_rows; row_index++) {
        for (int col_index = 1; col_index <= row_index; col_index++) {
            printf("%d ", calculate_pascal_value(row_index, col_index));
        }
        printf("\n");
    }
}

int main(void) {
    int num_rows = read_num_rows();
    
    if (num_rows == -1) {
        return 0;
    }

    print_pascal_triangle(num_rows);

    return 0;
}
