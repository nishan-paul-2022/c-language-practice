/*
 * Purpose: Demonstrates printing a rectangle pattern filled with row numbers using nested loops and input validation.
 * Topic: Pattern Printing and Nested Loops
*/

#include <stdio.h>

int get_positive_integer(const char *prompt) {
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1 || value <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1; 
    }
    return value;
}

void print_rectangle_rows(int rows, int cols) {
    for (int row = 1; row <= rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%4d", row);
        }
        printf("\n");
    }
}

int main(void) {
    int rows = get_positive_integer("Enter the number of rows: ");
    if (rows <= 0) {
        return 0;
    }

    int cols = get_positive_integer("Enter the number of columns: ");
    if (cols <= 0) {
        return 0;
    }

    printf("\nRectangle with row numbers:\n");
    print_rectangle_rows(rows, cols);

    return 0;
}
