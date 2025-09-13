/*
 * Purpose: Prints a hollow rectangle pattern using a specified number.
 * Topic: Nested Loops, Rectangle Patterns
 */

#include <stdio.h>
#include <stdlib.h>

int get_positive_integer(const char *prompt) {
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1 || value <= 0) {
        fprintf(stderr, "Error: Invalid input. Please enter a positive integer.\n");
        return -1;
    }
    return value;
}

int get_fill_number(void) {
    int fill_number;
    printf("Enter the number to fill the rectangle with: ");
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Error: Invalid input for fill number.\n");
        return -1;
    }
    return fill_number;
}

void print_hollow_rectangle(int num_rows, int num_cols, int fill_number) {
    for (int row = 1; row <= num_rows; row++) {
        for (int col = 1; col <= num_cols; col++) {
            if (row == 1 || row == num_rows || col == 1 || col == num_cols) {
                printf("%d ", fill_number);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int num_rows = get_positive_integer("Enter the number of rows: ");
    if (num_rows == -1) return 0;

    int num_cols = get_positive_integer("Enter the number of columns: ");
    if (num_cols == -1) return 0;

    int fill_number = get_fill_number();
    if (fill_number == -1) return 0;

    print_hollow_rectangle(num_rows, num_cols, fill_number);

    return 0;
}
