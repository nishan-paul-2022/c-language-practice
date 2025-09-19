/*
 * Purpose: Generates and prints Pascal's triangle up to a specified number of rows.
 * Topic: Pascal's Triangle, Combinatorics
 */

#include <stdio.h>

long long calculate_next_coefficient(long long current_coeff, int n, int k) {
    if (k < 0 || k > n || current_coeff < 0) {
        return -1;
    }
    
    long long next_coeff;
    if (__builtin_mul_overflow(current_coeff, (n - k + 1), &next_coeff)) {
        return -2;
    }
    return next_coeff / k;
}

int read_num_rows() {
    int num_rows;
    printf("Enter the number of rows for Pascal's triangle: ");
    
    if (scanf("%d", &num_rows) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return -1;
    }

    if (num_rows < 0) {
        printf("Number of rows cannot be negative.\n");
        return -1;
    }
    
    return num_rows;
}

void print_header(int num_rows) {
    printf("\n");
    printf("Row\\Col");
    for (int i = 0; i <= num_rows; ++i) {
        printf("%4d", i);
    }
    printf("\n");
}

void print_pascal_triangle(int num_rows) {
    int row_label = 0;
    
    for (int m = 0; m <= num_rows; ++m) {
        long long coefficient = 1;
        
        printf("%4d ", row_label++);

        for (int k = 0; k <= m; ++k) {
            printf("%4lld", coefficient);

            if (k < m) {
                coefficient = calculate_next_coefficient(coefficient, m, k + 1);
                if (coefficient < 0) {
                    if (coefficient == -1) {
                        printf(" ERR");
                    } else {
                        printf(" OVFL");
                    }
                    break;
                }
            }
        }
        printf("\n");
    }
}

int main(void) {
    int num_rows = read_num_rows();
    
    if (num_rows == -1) {
        return 0;
    }

    print_header(num_rows);
    print_pascal_triangle(num_rows);

    return 0;
}
