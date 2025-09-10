/*
 * Purpose: Prints a rectangle with a specified number at the center and another number elsewhere.
 * Topic: Nested Loops, Rectangle Patterns, Conditional Logic
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_rows;
    int num_cols;
    int center_number;
    int fill_number;

    // Get number of rows
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Get number of columns
    printf("Enter the number of columns: ");
    if (scanf("%d", &num_cols) != 1 || num_cols <= 0) {
        fprintf(stderr, "Error: Invalid input for number of columns. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Get center number
    printf("Enter the number to fill the center with: ");
    if (scanf("%d", &center_number) != 1) {
        fprintf(stderr, "Error: Invalid input for center number.\n");
        return EXIT_FAILURE;
    }

    // Get fill number
    printf("Enter the number to fill the rest of the rectangle with: ");
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Error: Invalid input for fill number.\n");
        return EXIT_FAILURE;
    }

    // Print rectangle with center number
    for (int row = 1; row <= num_rows; row++) {
        for (int col = 1; col <= num_cols; col++) {
            // Check if current position is the center
            // For odd dimensions, center is (rows/2 + 1, cols/2 + 1)
            // For even dimensions, pick one of the middle cells as center
            if (row == (num_rows + 1) / 2 && col == (num_cols + 1) / 2) {
                printf("%d ", center_number);
            } else {
                printf("%d ", fill_number);
            }
        }
        printf("\n"); // New line after each row
    }

    return EXIT_SUCCESS;
}
