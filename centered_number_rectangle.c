/*
 * Purpose: Prints a rectangle with a specified number at the center and another number elsewhere.
 * Topic: Nested Loops, Rectangle Patterns, Conditional Logic
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Get number of rows
    int num_of_rows;
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_of_rows) != 1 || num_of_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return 0;
    }

    // Get number of columns
    int num_of_cols;
    printf("Enter the number of columns: ");
    if (scanf("%d", &num_of_cols) != 1 || num_of_cols <= 0) {
        fprintf(stderr, "Error: Invalid input for number of columns. Please enter a positive integer.\n");
        return 0;
    }

    // Get center number
    int center_number;
    printf("Enter the number to fill the center with: ");
    if (scanf("%d", &center_number) != 1) {
        fprintf(stderr, "Error: Invalid input for center number.\n");
        return 0;
    }

    // Get fill number
    int fill_number;
    printf("Enter the number to fill the rest of the rectangle with: ");
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Error: Invalid input for fill number.\n");
        return 0;
    }

    // Print rectangle with center numbers
    for (int row = 1; row <= num_of_rows; row++) {
        for (int col = 1; col <= num_of_cols; col++) {
            // Determine center position (handles both odd and even dimensions)
            if (row == (num_of_rows + 1) / 2 && col == (num_of_cols + 1) / 2) {
                printf("%d ", center_number);
            } else {
                printf("%d ", fill_number);
            }
        }
        printf("\n"); // New line after each row
    }

    return 0;
}
