/*
 * Purpose: Prints a rectangle with a specified number at the center and another number elsewhere.
 * Topic: Nested Loops, Rectangle Patterns, Conditional Logic
 */

#include <stdio.h>
#include <stdlib.h>

int get_rows() {
    int num_of_rows;
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_of_rows) != 1 || num_of_rows <= 0) {
        fprintf(stderr, "Invalid input for number of rows. Please enter a positive integer.\n");
        return -1;
    }
    return num_of_rows;
}

int get_columns() {
    int num_of_cols;
    printf("Enter the number of columns: ");
    if (scanf("%d", &num_of_cols) != 1 || num_of_cols <= 0) {
        fprintf(stderr, "Invalid input for number of columns. Please enter a positive integer.\n");
        return -1;
    }
    return num_of_cols;
}

int get_center_number() {
    int center_number;
    printf("Enter the number to fill the center with: ");
    if (scanf("%d", &center_number) != 1) {
        fprintf(stderr, "Invalid input for center number.\n");
        return -1;
    }
    return center_number;
}

int get_fill_number() {
    int fill_number;
    printf("Enter the number to fill the rest of the rectangle with: ");
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Invalid input for fill number.\n");
        return -1;
    }
    return fill_number;
}

int is_center_position(int row, int col, int num_of_rows, int num_of_cols) {
    return (row == (num_of_rows + 1) / 2 && col == (num_of_cols + 1) / 2);
}

void print_rectangle(int num_of_rows, int num_of_cols, int center_number, int fill_number) {
    for (int row = 1; row <= num_of_rows; row++) {
        for (int col = 1; col <= num_of_cols; col++) {
            if (is_center_position(row, col, num_of_rows, num_of_cols)) {
                printf("%d ", center_number);
            } else {
                printf("%d ", fill_number);
            }
        }
        printf("\n");
    }
}

int main(void) {
    int num_of_rows = get_rows();
    if (num_of_rows == -1) {
        return 0;
    }

    int num_of_cols = get_columns();
    if (num_of_cols == -1) {
        return 0;
    }

    int center_number = get_center_number();
    if (center_number == -1) {
        return 0;
    }

    int fill_number = get_fill_number();
    if (fill_number == -1) {
        return 0;
    }

    print_rectangle(num_of_rows, num_of_cols, center_number, fill_number);
    return 0;
}
