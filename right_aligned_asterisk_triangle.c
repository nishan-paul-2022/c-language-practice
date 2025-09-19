/*
 * Purpose: Prints a right-aligned triangle pattern using asterisks with leading spaces.
 * Topic: Nested Loops, Spacing
 */

#include <stdio.h>

void print_triangle(int num_rows) {
    int space_count = num_rows;
    for (int row = 1; row <= num_rows; row++) {
        for (int space_col = 1; space_col < space_count; space_col++) {
            printf(" ");
        }
        for (int col = 1; col <= row; col++) {
            printf(" *");
        }
        space_count--;
        printf("\n");
    }
}

int main(void) {
    int num_rows;
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Invalid input. Enter a positive integer.\n");
        return 0;
    }
    print_triangle(num_rows);
    return 0;
}
