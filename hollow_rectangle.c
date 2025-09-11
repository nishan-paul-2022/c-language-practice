/*
 * Purpose: Prints a hollow rectangle pattern using a specified number.
 * Topic: Nested Loops, Rectangle Patterns
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_rows;
    int num_cols;
    int fill_number;

    // Prompt user for rectangle dimensions
    printf("Enter the number of rows: ");
    // Validate rows input
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return 0;
    }

    printf("Enter the number of columns: ");
    // Validate columns input
    if (scanf("%d", &num_cols) != 1 || num_cols <= 0) {
        fprintf(stderr, "Error: Invalid input for number of columns. Please enter a positive integer.\n");
        return 0;
    }

    printf("Enter the number to fill the rectangle with: ");
    // Validate fill number input
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Error: Invalid input for fill number.\n");
        return 0;
    }

    // Print hollow rectangle
    for (int row = 1; row <= num_rows; row++) {
        for (int col = 1; col <= num_cols; col++) {
            // Print fill number for border positions
            if (row == 1 || row == num_rows || col == 1 || col == num_cols) {
                printf("%d ", fill_number);
            } else {
                // Print spaces for inside of rectangle
                printf("  "); // Two spaces to match width of "%d "
            }
        }
        printf("\n"); // Move to next line
    }

    return 0;
}
