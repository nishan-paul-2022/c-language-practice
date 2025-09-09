// Purpose: Prints a rectangle with a specified number at the center and another number elsewhere.
// Topic: Nested Loops, Rectangle Patterns, Conditional Logic

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

int main(void) {
    int num_rows;
    int num_cols;
    int center_number;
    int fill_number;

    // Prompt user for input
    printf("Enter the number of rows: ");
    // Input validation for number of rows
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    printf("Enter the number of columns: ");
    // Input validation for number of columns
    if (scanf("%d", &num_cols) != 1 || num_cols <= 0) {
        fprintf(stderr, "Error: Invalid input for number of columns. Please enter a positive integer.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    printf("Enter the number to fill the center with: ");
    // Input validation for center number
    if (scanf("%d", &center_number) != 1) {
        fprintf(stderr, "Error: Invalid input for center number.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    printf("Enter the number to fill the rest of the rectangle with: ");
    // Input validation for fill number
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Error: Invalid input for fill number.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    // Print the rectangle
    for (int row = 1; row <= num_rows; row++) {
        for (int col = 1; col <= num_cols; col++) {
            // Check if the current position is the center
            // For odd dimensions, the center is (rows/2 + 1, cols/2 + 1)
            // For even dimensions, we can pick one of the middle cells as center
            if (row == (num_rows + 1) / 2 && col == (num_cols + 1) / 2) {
                printf("%d ", center_number);
            } else {
                printf("%d ", fill_number);
            }
        }
        printf("\n"); // Move to the next line after printing a row
    }

    return EXIT_SUCCESS;
}
